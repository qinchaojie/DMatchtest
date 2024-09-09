
https://blog.csdn.net/weixin_50557558/article/details/141103000
# I读写

> 头文件 #include<opencv2/opencv.hpp> 

```c++
cv::imread();  // 读取
cv::imshow();  // 显示
cv::namedWindow();  // 创建窗口
cv::waitKey(0);  // 等待用户键盘输入
cv::destroyAllWindows();  // 销毁窗口
```
# II基础操作
# 转换颜色
> cv::cvtColor(img_rgb, hsv, cv::COLOR_BGR2HSV);

# 图像创建
```c++
cv::Mat::ones();  // 创建像素值全1的二维矩阵
cv::Mat::zeros();  // 创建像素值全0的二维矩阵
cv::Scalar(127, 127, 127); // 创建标量
```

>Examples
```c++
// 创建空白图像
// c++中Mat类似python中的Numpy
// CV_8UC1 8位无符号字符（unsigned char） 1：单通道， 3：3通道
//Mat m3 =  Mat::zeros(cv::Size(8, 8), CV_8UC1); 
//Mat m3 =  Mat::zeros(src.size(), src.type();
Mat m3 =  Mat::zeros(8, 8, CV_8UC3); 
// 宽度为：8 高度为：8 通道数：3
cout << "宽度为：" << m3.cols << " 高度为：" << m3.rows << " 通道数：" << m3.channels() << endl;
cout << m3 << endl;

// 单通道没啥区别，3通道时，只在每个像素的第1个通道为1，其余两个通道像素值为0
m3 =  Mat::ones(cv::Size(8, 8), CV_8UC3); 
// 即使直接赋值，仍然会出现这样的现象
//m3 = 127;

// Scalar可以解决  c++中的操作符重载全部可以运用在Mat中
m3 = cv::Scalar(127, 127, 127);
cout << m3 << endl;

```

# 像素赋值
```c++
src.clone();  // 图像拷贝克隆
src.copyTo(m2);  // 图像拷贝克隆
m1 = m2; // 图像拷贝克隆

```
>Examples
```c++
cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
cv::Mat m1, m2;
// 克隆 、 拷贝则会创建1个新的内存空间。
m1 = src.clone();
src.copyTo(m2);
// 直接赋值创建1个新Mat对象，指针还是指向同一个Data Block；
// 所以这里的m3的像素值改变，而src也会随着一起改变。
cv::Mat m3 = src;
m3 = cv::Scalar(0, 0, 255);
cv::imshow("res", src)

```

# 图像像素的读写操作
```c++
src.at<uchar>(y, x);;  // 单通道图像获取某个像素值
src.at<cv::Vec3b>(y, x);  // RGB三通道图像获取某个像素值
src.ptr<uchar>(y);  // 获取单通道图像某一行的指针

```
>数组方式遍历
```c++
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{ 
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	
	int w = src.cols;
	int h = src.rows;
	int dims = src.channels();
    
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (dims == 1)
			{
				// 灰度图像
				// at方法是Mat里面的1个函数模板，所以要指定模板的数据类型
				int pv = src.at<uchar>(y, x); // (y,x) (h,w)
				src.at<uchar>(y, x) = 255 - pv;
			}
			else if (dims == 3)
			{
				// RGB图像
				// 是一个模板类 cv::Vec 的特化版本，专门用于存储 3 个 uchar（无符号字符）值，通常表示 BGR 通道。
				// 是一个用于表示固定大小的三维向量的类型，专门用于图像处理中的颜色数据
				cv::Vec3b bgr = src.at<cv::Vec3b>(y, x);
				src.at<cv::Vec3b>(y, x)[0] = 255 - bgr[0];
				src.at<cv::Vec3b>(y, x)[1] = 255 - bgr[1];
				src.at<cv::Vec3b>(y, x)[2] = 255 - bgr[2];
			}
		}
	}

	cv::imshow("img", src);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	system("pause");
	return 0;
}

```
>指针方式遍历
```c++
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{ 
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	
	int w = src.cols;
	int h = src.rows;
	int dims = src.channels();

	for (int y = 0; y < h; y++)
	{
		// 使用 src.ptr<uchar>(y) 获取当前行的指针;
		// current_y 是指向图像第 y 行第一个像素的指针。
		uchar* current_y = src.ptr<uchar>(y);
		
		for (int x = 0; x < w; x++)
		{
			if (dims == 1)
			{
				// 灰度图像
				int pv = *current_y;
				*current_y++ = 255 - pv;
			}
			else if (dims == 3)
			{
				// RGB图像
				*current_y++ = 255 - *current_y;
				*current_y++ = 255 - *current_y;
				*current_y++ = 255 - *current_y;
			}
		}
	}

	cv::imshow("img", src);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	system("pause");
	return 0;
}

```

# 算数运算
1. 可以和标量Scalar进行加减乘除；
2. 可以和创建的图像本身（全0、全1后进行赋初始值）的算术操作
>Examples 1
```c++
int main()
{ 
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	
	cv::Mat dst;
	//dst = src - cv::Scalar(50, 50, 50);  // 减法 // 在不同的通道加上不同的值
	//dst = src - cv::Scalar(50, 50, 50);  // 减法 
	//dst = src / cv::Scalar(2, 2, 2);      // 除法
	
	// 两个图形相乘，是不可以用标量进行操作的
	// penCV 并不支持直接用 * 操作符对 cv::Mat 和 cv::Scalar 进行运算
	//dst = src * cv::Scalar(2, 2, 2);
	// 使用 cv::multiply 函数
	cv::Mat m = cv::Mat::zeros(src.size(), src.type());
	m = cv::Scalar(2, 2, 2);
	cv::multiply(src, m, dst); //将源图像与矩阵m相乘，结果存储在目标图像dst中

	cv::imshow("加法操作", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	system("pause");
	return 0;
}

```
>Examples2
```c++
int main()
{ 
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	
	cv::Mat m = cv::Mat::zeros(src.size(), src.type());
	m = cv::Scalar(50, 50, 50);

	cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

	
	// 加法
	// 从上到下，从左到右，先遍历行（图像的高）
	for (int y = 0; y < src.rows; y++)
	{
		for (int x = 0; x < src.cols; x++)
		{
			// 获取原始图像的每个像素值
			cv::Vec3b p1 = src.at<cv::Vec3b>(y, x);
			// 获取m图像的每个像素值
			cv::Vec3b p2 = m.at<cv::Vec3b>(y, x);
			// saturate_cast方法在cv中常用， 将像素值约束在0-255之间
			dst.at<cv::Vec3b>(y, x)[0] = cv::saturate_cast<uchar>(p1[0] + p2[0]);
			dst.at<cv::Vec3b>(y, x)[1] = cv::saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<cv::Vec3b>(y, x)[2] = cv::saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}

	cv::imshow("加法操作", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	system("pause");
	return 0;
}

```
>***Examples 通过api来实现
```
cv::add(src, m, dst);  // 加法
cv::subtract(src, m, dst);  // 减法
cv::multiply(src, m, dst);  // 乘法
cv::divide(src, m, dst);  // 除法
cv::saturate_cast<uchar>(p);  // 将p的像素值约束在0-255之间
```
```c++
int main()
{ 
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	
	cv::Mat m = cv::Mat::zeros(src.size(), src.type());
	m = cv::Scalar(50, 50, 50);

	cv::Mat dst = cv::Mat::zeros(src.size(), src.type());
	
	// 加法
	cv::add(src, m, dst);
	// 减法
	cv::subtract(src, m, dst);
	// 除法
	cv::divide(src, m, dst);
	cv::imshow("加法操作", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	system("pause");
	return 0;
}


```