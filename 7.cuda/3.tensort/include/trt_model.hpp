#ifndef TRT_MODEL_HPP
#define TRT_MODEL_HPP

#include <memory>
#include <vector>
#include <string>
#include "NvInfer.h"

#define WORKSPACESIZE 1<<28 // 2^28
namespace model{

enum task_type {        //->任务类型
    CLASSIFICATION,
    DETECTION,
    SEGMENTATION,
    MULTITASK
};

enum device {           //->设备类型
    CPU,
    GPU
};

enum precision {        //->精度
    FP32,
    FP16,
    INT8
};

struct image_info {     //->输入图像size
    int h;
    int w;
    int c;
    image_info(int height, int width, int channel) : h(height), w(width), c(channel) {} // 构造函数，用以初始化
};

struct Params {         //->构建模型参数
    device               dev           = GPU;
    int                  num_cls       = 1000;
    preprocess::tactics  tac           = preprocess::tactics::GPU_BILINEAR;
    image_info           img           = {224, 224, 3};
    task_type            task          = CLASSIFICATION;
    int                  ws_size       = WORKSPACESIZE;
    precision            prec          = FP32;
    std::string          cal_list;
    std::string          cal_table;
    int                  cal_batchsize = 64;
};

// 模板函数
template<typename T>            //->构建trt智能指针释放函数. trt指针的释放通过ptr->destroy完成
void destroy_trt_ptr(T* ptr){
    if (ptr) {
        std::string type_name = typeid(T).name();
        LOGD("Destroy %s", type_name.c_str());
        ptr->destroy(); 
    };
}


class Model {
public :
    Model(std::string onnxPath, Params params);
    virtual ~Model() {};
};



};
#endif // TRT_MODEL_HPP