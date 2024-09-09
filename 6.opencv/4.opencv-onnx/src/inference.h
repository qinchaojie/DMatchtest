#ifndef INFERENCE_H
#define INFERENCE_H

#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <opencv2/imgproc.hpp> 
#include <opencv2/opencv.hpp> 
#include <opencv2/dnn.hpp>
using namespace std;
using namespace cv;

struct Object
{
    int class_id{0};
    std::string class_name{};
    float confidence{0.0};
    cv::Scalar color{};
    cv::Rect box{};
};

class YOLOV8{
public:
    // 初始化
    YOLOV8(const string &onnx_file_path,const Size &input_shape = {640, 640},\
     const string classes_define_file = "", const bool &using_cuda = false);
    
    vector<Object> infer(const Mat &input); // 推理方法

private:
    vector<string> classes{"Right hand calling", "Right hand typing", "Left hand calling", "Left hand typing", "Adjusting the radio", "Drinking", "Conversing with other passengers", "Reaching for backseat items", "Grooming hair and makeup"};


    string model_path{};
    string classes_path{};
    bool cuda_enabled{};

    void load_onnx_model(); // load model
    void load_classes_FromFile(); //load class match file
    Mat format2square(const Mat &source);

    Size2f model_shape{};
    float model_confidence_threshold {0.25};
    float model_score_threashold {0.45};
    float model_NMS_threshold {0.50};
    bool letter_box_square = true;
    dnn::Net net; // model
};


#endif