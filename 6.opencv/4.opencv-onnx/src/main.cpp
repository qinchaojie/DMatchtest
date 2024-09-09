#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>
// #include <opencv2/opencv.hpp>
#include <chrono>
#include "inference.h"
using namespace std;
using namespace cv;

// 查找文件的路径
std::vector<std::string> getImgPath(std::string path){
    vector<string> image_names; // 字符串数组
        DIR* dir; 
        struct dirent* ent;
        if ((dir = opendir(path.c_str()))!=NULL)
        {
            while ((ent = readdir(dir))!=NULL)
            {
                if(ent ->d_type == DT_REG)
                {
                    image_names.push_back(path+ent->d_name);
                }
            }
        }
    return image_names;
};

int main(int argc, char ** argv){

    char lang[] = "LANG=zh_CN.UTF-8";
    char language[] = "LANGUAGE=zh_CN:zh";
    putenv(lang);
    putenv(language);
    setlocale(LC_ALL,"zh_CN.UTF-8");

    //  模型创建path
    std::string project_base_dir = "/22085400631/cpp/opencv/4.onnx/";
    std::string model_path = project_base_dir+"models/yolov8.onnx";
    // 初始化模型
    bool using_cuda = false; // 是否使用cuda
    YOLOV8 yolo(model_path,Size(640,640),"classes.txt",using_cuda); //init 

    // 数据加载
    string dataset_dir = project_base_dir+ "yolo8_img/";
    std::vector<std::string> imgPaths = getImgPath(dataset_dir);

    // out_dir
    std::string outDir = project_base_dir + "outDir/";
    int n = 0;
    for(string img_path: imgPaths){
        std::cout << img_path << endl;
        cv::Mat frame = cv::imread(img_path);
        if (frame.empty()){
            printf("%s load filed!\n", img_path);
            continue;
        }
        else{
            printf("%s load success!\n", img_path);
        }
        auto start = chrono::steady_clock::now();
        vector<Object> output = yolo.infer(frame);
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
        int objects = output.size();
        cout<<"Number of objects: " <<objects<<endl;

        // draw
        for (auto obj :output)
        {
            rectangle(frame,obj.box,obj.color,2);
            string pred_string = obj.class_name + ' ' + to_string(obj.confidence).substr(0,4);
            cout<<pred_string<<endl;
            putText(frame,pred_string,Point(obj.box.x+5,obj.box.y-10),FONT_HERSHEY_DUPLEX,1,obj.color);
            putText(frame,"FPS: "+to_string(1000.0/duration.count()).substr(0,4),Point(20,frame.rows-20),FONT_HERSHEY_DUPLEX,0.5,Scalar(0,255,0));
            
        }
        float scale = 0.8;
        resize(frame,frame,Size(frame.cols*scale,frame.rows*scale));
        
        cv::imwrite(outDir + std::to_string(n) + ".png", frame);
        n++;
    }
    return 0;
}