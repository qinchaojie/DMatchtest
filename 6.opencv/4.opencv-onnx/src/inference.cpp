#include "inference.h"


// 初始化方法实现

YOLOV8::YOLOV8(const string &onnx_file_path,const Size &input_shape,const string classes_define_file, const bool &using_cuda){
    model_path = onnx_file_path;
    model_shape = input_shape;
    classes_path = classes_define_file;
    cuda_enabled = using_cuda;
    load_onnx_model();
};

vector<Object> YOLOV8::infer(const Mat &input){
    Mat model_input = input;

    // 确定图像的大小是否匹配
    if (letter_box_square && model_shape.width == model_shape.height){
        // cout<<"resize"<<endl;
        model_input = format2square(model_input);  // 更改大小，
    }

    Mat blob;
    
    dnn::blobFromImage(model_input,blob,1.0/255.0, model_shape,Scalar(),true,false);
    net.setInput(blob);
    vector<Mat> outputs;
    net.forward(outputs,net.getUnconnectedOutLayersNames());
    int rows = outputs[0].size[1];
    int dimensions = outputs[0].size[2];
    bool yolov8 = false;
    if (dimensions > rows)
    {
        yolov8 = true;
        rows = outputs[0].size[2];
        dimensions = outputs[0].size[1];
        outputs[0] = outputs[0].reshape(1,dimensions);
        transpose(outputs[0],outputs[0]);
    }
    float *data = (float *)outputs[0].data;
    float x_factor = model_input.cols / model_shape.width;
    float y_factor = model_input.rows / model_shape.height;
    vector<int> class_ids;
    vector<float> confidences;
    vector<Rect> boxes;
    for (int i = 0;i<rows;++i)
    {
        if (yolov8)
        {
            float *classes_scores = data+4;
            Mat scores(1, classes.size(),CV_32FC1,classes_scores);
            Point classes_id;
            double max_class_score;
            minMaxLoc(scores, 0 ,&max_class_score, 0,&classes_id);

            if (max_class_score >model_score_threashold)
            {
                confidences.push_back(max_class_score);
                class_ids.push_back(classes_id.x);

                float x = data[0];
                float y = data[1];
                float w = data[2];
                float h = data[3];

                int left = int((x-0.5*w) * x_factor);
                int top = int((y-0.5*h) * y_factor);

                int width = int(w* x_factor);
                int height = int(h*y_factor);

                boxes.push_back(Rect(left,top,width,height));
            }
        }
        else
        {
            float confidence = data[4];
            if (confidence > model_score_threashold)
            {
                float *classes_scores = data+5;

                Mat scores(1,classes.size(),CV_32FC1,classes_scores);
                Point class_id;
                double max_class_score;

                minMaxLoc(scores,0,&max_class_score, 0, &class_id);

                if(max_class_score > model_score_threashold)
                {
                    confidences.push_back(confidence);
                    class_ids.push_back(class_id.x);
                    
                    
                    float x = data[0];
                    float y = data[1];
                    float w = data[2];
                    float h = data[3];

                    int left = int((x-0.5*w) * x_factor);
                    int top = int((y-0.5*h) * y_factor);

                    int width = int(w * x_factor);
                    int height = int(h * y_factor);

                    boxes.push_back(Rect(left,top,width,height));
                    
                }

            }
        }
        data+=dimensions;
    }
    
    vector<int> nms_re;
    dnn::NMSBoxes(boxes,confidences,model_score_threashold,model_NMS_threshold,nms_re);
    vector<Object> Objects{};
    for (unsigned long i = 0; i<nms_re.size();++i)
    {
        int idx = nms_re[i];

        Object result;
        result.class_id = class_ids[idx];
        result.confidence = confidences[idx];

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(100, 255);
        result.color = Scalar(dis(gen),
                                dis(gen),
                                dis(gen));

        result.class_name = classes[result.class_id];
        result.box = boxes[idx];

        Objects.push_back(result);
    }
    
    return Objects;


};


cv::Mat YOLOV8::format2square(const Mat &source)
{
    int col = source.cols;
    int row = source.rows;
    int _max = MAX(col,row);
    Mat re = Mat::zeros(_max,_max,CV_8UC3);
    source.copyTo(re(Rect(0,0,col,row)));
    return re;

}

void YOLOV8::load_classes_FromFile()
{
    ifstream input_file(classes_path);
    if (input_file.is_open())
    {
        string class_line;
        while ( getline(input_file,class_line))
        {
            classes.push_back(class_line);
        }
        input_file.close();
        
    }
}

void YOLOV8::load_onnx_model(){
    net = cv::dnn::readNetFromONNX(model_path);
    if (cuda_enabled)
    {
        cout<<"running on CUDA"<<endl;
        net.setPreferableBackend(dnn::DNN_BACKEND_CUDA);
        net.setPreferableTarget(dnn::DNN_TARGET_CUDA);
    }
    else
    {
        cout<<"Running on CPU"<<endl;
        net.setPreferableBackend(dnn::DNN_BACKEND_OPENCV);
        net.setPreferableTarget(dnn::DNN_TARGET_CPU);
    }
    printf("[INFO]: Model init success!\n");
}