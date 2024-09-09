#include<iostream>
#include<opencv2/opencv.hpp>  //头文件

using namespace std;
using namespace cv;



int main(int argc, char** argv){
    
    std::cout << "<<<<E1:图像的读取>>>>" << std::endl;
    cv::Mat src = cv::imread("/22085400631/cpp/opencv/3.GeometricTransformation/datas/111.png");
    printf("E1:size: %d, total: %d\n", src.size(), src.total()); //W*H, W*H*C
    
    cv::Rect rect1(100, 100, 250, 300);
	cv::Point p1(100, 100);
	cv::Point p2(300, 400);
    cv::RotatedRect r1(p1, cv::Size(100, 200), 30.0);
    // 绘制矩形
    // cv::rectangle(src, rect1, cv::Scalar(0,0,255), -1); //-1表示填充
    cv::rectangle(src, rect1, cv::Scalar(0,0,255), 2); //

    // 绘制圆形
	cv::circle(src, p1, 15, cv::Scalar(0, 255, 0), 2);

	// 绘制直线
	cv::line(src, p1, p2, cv::Scalar(255, 0, 0), 2);

	// 绘制椭圆
	cv::ellipse(src, r1, cv::Scalar(255, 255, 0), -1);
    cv::imwrite("/22085400631/cpp/opencv/3.GeometricTransformation/datas/E1-out.png", src);

    std::cout << "<<<<E2:随机生成>>>>" << std::endl;
    cv::Mat canvas = cv::Mat::zeros(cv::Size(512, 512), CV_8UC3);
	cv::RNG rng(12345);
    int x1 = rng.uniform(0, canvas.cols);
    int y1 = rng.uniform(0, canvas.rows);
    int x2 = rng.uniform(0, canvas.cols);
    int y2 = rng.uniform(0, canvas.rows);

    int b = rng.uniform(0, 255);
    int g = rng.uniform(0, 255);
    int r = rng.uniform(0, 255);
    cv::line(canvas, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(b, g, r), 5);
    cv::imwrite("/22085400631/cpp/opencv/3.GeometricTransformation/datas/E2-out.png", canvas);
    
    std::cout << "success!!!!" << std::endl;
    return 0;
}