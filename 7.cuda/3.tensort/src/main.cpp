#include <stdio.h>
// #include "cat.hpp"
#include <yaml-cpp/yaml.h>
#include <iostream>


int main(int* argc, char** argv){
    
    // 1. 解析配置文件的信息
    YAML::Node config = YAML::LoadFile("./config/config.yaml");   // load yaml
    std::string onnxPath = config["onnxPath"].as<std::string>(); // onnx path
    
    std::cout << config << std::endl;
    std::cout << onnxPath << std::endl;

    printf("run over!!\n");
    return 0;
}