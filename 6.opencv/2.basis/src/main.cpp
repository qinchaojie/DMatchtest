#include<iostream>
#include<opencv2/opencv.hpp>  //头文件

using namespace std;
using namespace cv;

// 便利数组
void printUseList(const cv::Mat img){
    int w = img.cols, h=img.rows, dims=img.channels();
    for (int y=0;y<h;y++){
        for (int x=0; x<w; x++){
            if (dims == 1){ //grey img
                int pv = img.at<uchar>(y,x);
                // img.at<uchar>(y, x) = 255 - pv;
                cout<< pv<< " ";
            }
            else if (dims ==3){
                cv::Vec3b bgr = img.at<cv::Vec3b>(y, x);
                // bgr[0][1][2]分别表示RGB 3 channal
                // cout<< bgr[0]<< " "<< bgr[1]<< " "<< bgr[2]<< " ";
                cout<< bgr<< " ";

                // img.at<cv::Vec3b>(y, x)[0] = 255 - bgr[0];
				// img.at<cv::Vec3b>(y, x)[1] = 255 - bgr[1];
				// img.at<cv::Vec3b>(y, x)[2] = 255 - bgr[2];
            }
        }
        cout<< "\n";
    }
};

void printUsePoint(const cv::Mat img){
    int w = img.cols, h=img.rows, dims=img.channels();

    for (int y = 0; y < h; y++)
	{
		// 使用 img.ptr<uchar>(y) 获取当前行的指针;
		// current_y 是指向图像第 y 行第一个像素的指针。
		uchar* current_y = (uchar*)img.ptr<uchar>(y);  // 获取当前行的第一个元素指针
		
		for (int x = 0; x < w; x++)
		{
			if (dims == 1)
			{
				// 灰度图像
                printf("%.4d ", *current_y++);
				// *current_y++ = 255 - pv;
			}
			else if (dims == 3)
			{
                printf("%3.1d %3.1d %3.1d ", *current_y++,*current_y++,*current_y++);

				// RGB图像
				// *current_y++ = 255 - *current_y;
				// *current_y++ = 255 - *current_y;
				// *current_y++ = 255 - *current_y;
			}
		}
        printf("\n");
	}
};





int main(int argc, char** argv){
    
    std::cout << "<<<<E1:图像的读取>>>>" << std::endl;
    // RGB
    cv::Mat img_rgb = cv::imread("/22085400631/cpp/opencv/2.basis/datas/3.jpg");
    // gray
    cv::Mat img_gray = cv::imread("/22085400631/cpp/opencv/2.basis/datas/111.png", cv::IMREAD_GRAYSCALE);
    if (img_rgb.empty()){
        std::cout << "filed to load img_gray ..." << std::endl;
        return -1;
    }
    if (img_gray.empty()){
        std::cout << "filed to load img_gray..." << std::endl;
        return -1;
    }

    cv::imwrite("/22085400631/cpp/opencv/2.basis/datas/out_rgb.png", img_rgb);
    cv::imwrite("/22085400631/cpp/opencv/2.basis/datas/out_gray.png", img_gray);


    std::cout << "<<<<E2:转换颜色>>>>" << std::endl;
    // 转换颜色
    cv::Mat hsv, gray;
	cv::cvtColor(img_rgb, hsv, cv::COLOR_BGR2HSV);
	cv::cvtColor(img_rgb, gray, cv::COLOR_BGR2GRAY);
    cv::imwrite("/22085400631/cpp/opencv/2.basis/datas/hsv.png", hsv);
    cv::imwrite("/22085400631/cpp/opencv/2.basis/datas/gray.png", gray);

    std::cout << "<<<<E3:图像创建>>>>" << std::endl;
    Mat m3 =  Mat::zeros(8, 8, CV_8UC3); 
    // 宽度为：8 高度为：8 通道数：3
    cout << "E3:宽度为：" << m3.cols << " 高度为：" << m3.rows << " 通道数：" << m3.channels() << endl;
    // cout << m3 << endl;
    m3 =  Mat::ones(cv::Size(8, 8), CV_8UC3);  // 只能更改第一个通道的值
    cout << "E3:更改值 "<<endl;
    cout << "E3:宽度为：" << m3.cols << " 高度为：" << m3.rows << " 通道数：" << m3.channels() << endl;
    // m3 = 111;
    // cout << m3 << endl;

    std::cout << "<<<<E4:图像像素赋值>>>>" << std::endl;
    cv::Mat m4 = cv::imread("/22085400631/cpp/opencv/2.basis/datas/111.png");    
    cv::Mat m4_1, m4_2;
    m4_1 = m4.clone();  // 新的内存空间
    m4_2.copyTo(m4);
    Mat m4_3 = m4; // 指向同一个内存空间

    std::cout << "<<<<E5:图像像素赋值>>>>" << std::endl;
    cv::Mat m5 = cv::imread("/22085400631/cpp/opencv/2.basis/datas/16Pixel.png");    
    cv::Mat m5_gray;
    cout << "E5:gray "<<endl;

    cv::cvtColor(m5, m5_gray, cv::COLOR_RGB2GRAY);
    cout << m5_gray <<endl;
    printUseList(m5_gray);
    cout << "E5:RGB "<<endl;
    cout << m5 <<endl;
    printUsePoint(m5);


    std::cout << "<<<<E6:算数运算>>>>" << std::endl;
    cv::Mat m6 = cv::Mat::zeros(4,4,CV_8UC3);
    cv::Mat dst;
    std::cout << m6 << std::endl;
    dst = m6 + cv::Scalar(1,2,3); // 在不同的通道加上不同的值
    std::cout << dst << std::endl;
    m6 = cv::Scalar(1,2,3);
    cv::multiply(m6, m6, dst); // 对应相乘
    std::cout << dst << std::endl;

    std::cout << "success!!!!" << std::endl;
    return 0;
}