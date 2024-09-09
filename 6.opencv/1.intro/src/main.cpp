#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

int main(int argc, char** argv)
{   
    std::string path = "/22085400631/codes/cpp/6.opencv/dog.png";

    Mat img = imread(path, 1);
    std::cout << path << std::endl;
    std::cout << "Image type: " << img.type() << std::endl;
    std::cout << "Number of channels: " << img.channels() << std::endl;

    if (img.empty())
    {
        std::cout << "Failed to read image!" << std::endl;
        return -1; // 返回一个错误码
    }
    
    std::cout << "Image dimensions: " << img.rows << "x" << img.cols << std::endl;

    imwrite("/22085400631/codes/cpp/6.opencv/out/dog_out.png", img);

    return 0;
}