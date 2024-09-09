
https://blog.csdn.net/weixin_50557558/article/details/141103000
# 几何形状绘制
```c++
cv::Size(640, 480); // 指定图像的尺寸或矩形的尺寸。
cv::Point p1(10, 20);  // 表一个二维坐标点，具有 x 和 y 坐标。
cv::RotatedRect(p1, cv::Size(100, 100), 0.0);  // 表示一个带有旋转角度的矩形区域。它包括矩形的中心位置、大小（宽度和高度）以及旋转角度。
cv::Rect rect(10, 20, 100, 50);  // 代表一个矩形区域，具有左上角的坐标 (x, y)、宽度和高度。

// 绘制矩形， thickness为-1表示填充
cv::rectangle(image, Rect(100, 100, 200, 100), Scalar(0, 255, 0), 2);  
// 绘制圆形， thickness为-1表示填充
cv::circle(image, Point(200, 200), 100, Scalar(0, 0, 255), 3); 
// 绘制直线
cv::line(image, Point(50, 50), Point(350, 350), Scalar(255, 0, 0), 2);
// 绘制椭圆， thickness为-1表示填充
cv::ellipse(image, RotatedRect(Point(200, 200), Size(100, 50), 45), Scalar(255, 255, 0), 2);

```
>Examples
```c++
int main()
{ 
	cv::Mat src = cv::imread("C:/Users/Desktop/102.jpg");
	
	cv::Rect rect1(100, 100, 250, 300);
	cv::Point p1(100, 100);
	cv::Point p2(300, 400);
	cv::RotatedRect r1(p1, cv::Size(100, 200), 0.0);
	// 绘制矩形
	cv::rectangle(src, rect1, cv::Scalar(0, 0, 255), -1);

	// 绘制圆形
	cv::circle(src, p1, 15, cv::Scalar(0, 255, 0), 2);

	// 绘制直线
	cv::line(src, p1, p2, cv::Scalar(255, 0, 0), 2);

	// 绘制椭圆
	cv::ellipse(src, r1, cv::Scalar(255, 255, 0), -1);
	cv::imshow("window", src);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	system("pause");
	return 0;
}
```
# 随机数，颜色随机
```
// cv::RNG（Random Number Generator）用于生成随机数。rng(12345) 是使用种子 12345 初始化一个随机数生成器对象。
cv::RNG rng(12345);  // 初始化随机数生成器
// 生成一个范围在 0 到 255 之间的随机整数。这通常用于生成随机颜色值或其他需要随机性的场景。
rng.uniform(0, 255)

```
>Examples
```c++
int main()
{ 
	cv::Mat canvas = cv::Mat::zeros(cv::Size(512, 512), CV_8UC3);
	cv::RNG rng(12345);
	while (true)
	{ 
		int x1 = rng.uniform(0, canvas.cols);
		int y1 = rng.uniform(0, canvas.rows);
		int x2 = rng.uniform(0, canvas.cols);
		int y2 = rng.uniform(0, canvas.rows);

		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);

		cv::line(canvas, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(b, g, r));
		cv::imshow("result", canvas);
		cv::waitKey(10);
	}
	
	system("pause");
	return 0;
}

```

# 多边形绘制与填充
```
// 这个不可以设置thickness为-1 填充
cv::polylines(image, points, true, cv::Scalar(0, 255, 0), 2);  // 绘制多边形的边框。
cv::fillPoly(image, std::vector<std::vector<cv::Point>>{points}, cv::Scalar(0, 0, 255)); // 填充多边形内部。

// 这个可以设置thickness为-1 填充
cv::drawContours(image, contours, -1, cv::Scalar(0, 255, 0), 2);  // 绘制轮廓。

```
> Examples
```c++
int main()
{ 
	cv::Mat canvas = cv::Mat::zeros(cv::Size(512, 512), CV_8UC3);

	vector<cv::Point>pts;
	cv::Point p1(100, 100);
	cv::Point p2(350, 100);
	cv::Point p3(450, 280);
	cv::Point p4(320, 450);
	cv::Point p5(80, 400);
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);

	vector<cv::Point>pts2;
	cv::Point t1(50, 100);
	cv::Point t2(10, 100);
	cv::Point t3(50, 580);
	cv::Point t4(100, 100);
	pts2.push_back(t1);
	pts2.push_back(t2);
	pts2.push_back(t3);
	pts2.push_back(t4);

	// 想要一次性绘制多个多边形，就用大容器存放多个多边形
	vector<vector<cv::Point>>contours;
	contours.push_back(pts);
	contours.push_back(pts2);
	
	// 这里的多边形绘制线，thickness 不能设置 -1 为填充
	//cv::polylines(canvas, pts, true, cv::Scalar(0, 0, 255), 2);
	// 填充多边形
	//cv::fillPoly(canvas, pts, cv::Scalar(0, 0, 255), 2, 0);

	
	// 也是绘制多边形，thickness设置1为填充
	cv::drawContours(canvas, contours, 0, cv::Scalar(0, 0, 255), -1);
	cv::imshow("result", canvas);
	cv::waitKey(0);
	
	system("pause");
	return 0;
}

```

# 图像像素类型转换和归一化
常见的归一化：
1. NORM_L1：每个像素除以像素值之和；
2. NORM_L2：每个像素除以像素值的平方和的平方根；
3. NORM_INF：每个像素值÷最大值；
4. NORM_MINMAX：（x-min）/（max-min）
5. 注意：1、如果不将CV_8UC3转换成CV_32FC3 ，而是直接CV_8UC3做归一化，8位无符号型通过imshow可视化时，像素值是：0-255；而直接归一化到0-1之间，都是0.几的小数就是几乎是0，全黑图像了；
2、如果将CV_8UC3转换成CV_32FC3，没做归一化，可视化也是不对的，opencv中对float可视化，必须在0-1之间；
3、所以，一定先转float浮点型，再做归一化。

```c++
src.convertTo(dst, CV_32FC3); // 转换图像的数据类型
cv::normalize(dst, dst_normal, 1.0, 0.0, cv::NORM_MINMAX); // 将 dst 中的值归一化到 [0, 1] 范围
```
>Examples
```c++
int main()
{
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	cout << "src type = " << src.type() << endl;
	
	cv::Mat dst, dst_normal;
	// CV_8UC3、CV_32FC3  8和32都是每个字节是几个bit，U和F代表数据类型：无符号char、float型，C3代表channel3=3
	// CV_32S 32位整型（s表示整型）
	src.convertTo(dst, CV_32FC3);
	cout << "dst type = " << dst.type() << endl;

	// 转换成float型后，就可以进行归一化了
	cv::normalize(src, dst_normal, 1.0, 0.0, cv::NORM_MINMAX);
	cout << "dst_normal type = " << dst.type() << endl;

	cv::imshow("result", dst_normal);
	cv::waitKey(0);
	system("pause");
	return 0;
}
```
# 更改尺寸，反转
```c++
cv::resize(src, dst, newSize);  // 改变图像的尺寸

cv::flip(src, dst, 0); // 垂直翻转图像
cv::flip(src, dst, 1); // 水平翻转
cv::flip(src, dst, -1); // 同时水平和垂直翻转图像

/// 旋转
cv::Point pt1(10, 20); // 整数坐标
cv::Point2f pt2(10.5, 20.5); // 浮点数坐标
// 返回一个 2x3 的矩阵 M（生成的矩阵 M 包含旋转和平移信息。），用于将图像旋转 angle 角度（以 center 为中心），并且按 scale 缩放。
cv::Mat M = cv::getRotationMatrix2D(center, angle, scale);  // 生成二维旋转矩阵
cv::Mat M = cv::getRotationMatrix2D(cv::Point2f(src.cols / 2.0, src.rows / 2.0), 45.0, 1.0);  //  应用仿射变换到图像。


```

>Examples1
```c++
int main()
{
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	int w = src.rows;
	int h = src.cols;

	cv::Mat min_src, max_src;

	cv::resize(src, min_src, cv::Size(w / 2, h / 2), 0, 0, INTER_LINEAR);
	cv::resize(src, min_src, cv::Size(w * 1.5, h * 1.5), 0, 0, INTER_LINEAR);

	cv::imshow("缩小图", min_src);
	cv::imshow("放大图", min_src);
	cv::waitKey(0);
	system("pause");
	return 0;
}
```
>Examples2
```c++
int main()
{
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	
	cv::Mat dst;
	// 0表示上下反转，1表示左右翻转,-1表示上下左右翻转
	cv::flip(src, dst, -1);
	cv::namedWindow("图像反转", WINDOW_FREERATIO);
	cv::imshow("图像反转", dst);
	cv::waitKey(0);
	system("pause");
	return 0;
}

```
>Examples3
```c++
int main()
{
	cv::Mat src = cv::imread("C:/Users/Desktop/02.jpg");
	int w = src.cols;
	int h = src.rows;

	cv::Mat dst, M;

	// 获取旋转矩阵
	M = cv::getRotationMatrix2D(cv::Point2f(w / 2, h / 2), 45, 1.0);
	cout << M.at<double>(0, 2) << endl;
	cout << M.at<double>(1, 2) << endl;
	double cos = abs(M.at<double>(0, 0));
	double sin = abs(M.at<double>(0, 1));
	// 求出新的旋转后的图像的宽高
	int new_w = w * cos + h * sin;
 	int new_h = w * sin + h * cos;

	// M矩阵的第3列是仿射变换的平移部分，保证了图像在旋转和缩放之后，旋转中心保持在原始图像的中心位置。
	// 所以这里要计算出，图像在新的宽高下的中心点，计算出旋转矩阵的中心的偏移量
	// 使旋转后的图像保持在新图像的中心位置。
	M.at<double>(0, 2) = M.at<double>(0, 2) + (new_w / 2 - w / 2);
	M.at<double>(1, 2) = M.at<double>(1, 2) + (new_h / 2 - h / 2);
	cv::warpAffine(src, dst, M, cv::Size(new_w, new_h));
	cv::namedWindow("图像旋转", WINDOW_FREERATIO);
	cv::imshow("图像旋转", dst);
	cv::waitKey(0);
	system("pause");
	return 0;
}


```

# 视频读取
```c++
// source 可以是摄像头的编号（如0），也可以是视频文件的路径。
cv::VideoCapture cap(source);  // 读取视频流
cap.get(CAP_PROP_FRAME_HEIGHT);  // 视频帧的高度度
cap.get(CAP_PROP_FRAME_HEIGHT);  // 视频帧的宽度
cap.get(CAP_PROP_FRAME_COUNT);   // 视频的总帧数
cap.get(CAP_PROP_FPS);  // 视频的帧率
```
>Examples
```c++
int main()
{
	cv::VideoCapture cap(0);

	cv::Mat src;
	while (true)
	{
		cap.read(src);

		if (src.empty())
		{
			break;
		}
		cv::flip(src, src, 1);
		cv::imshow("video", src);
		cv::waitKey(10);
	}
	cv::destroyAllWindows();
	cap.release();
	system("pause");
	return 0;
}

```

# 视频处理保存,	
```c++
// filename: 保存视频的文件名（如 "output.avi"）
// codec: 视频编解码器的四字符代码（如 cv::VideoWriter::fourcc('M', 'J', 'P', 'G')）。
// fps: 每秒帧数。
// frameSize: 帧的大小，如 cv::Size(width, height)。
// isColor: 帧是否是彩色的布尔值。
cv::VideoWriter writer(filename, codec, fps, frameSize, isColor);  // 保存视频流
writer.write(frame);  // 写入帧到视频文件
```
>Examples
```c++
int main()
{
	cv::VideoCapture cap(0);
	int frame_width = cap.get(CAP_PROP_FRAME_HEIGHT);
	int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
	// 视频的总帧数
	int count = cap.get(CAP_PROP_FRAME_COUNT);
	int fps = cap.get(CAP_PROP_FPS);
	
	// 创建视频存储对象
	cv::VideoWriter writer("D:/test.mp4", cap.get(CAP_PROP_FOURCC), fps, cv::Size(frame_width, frame_height), true);
	cv::Mat src;
	while (true)
	{
		cap.read(src);

		if (src.empty())
		{
			break;
		}
		cv::flip(src, src, 1);
		cv::imshow("video", src);
		writer.write(src);

		if (cv::waitKey(1) == 27)
		{
			// 按下ESC键退出
			break;
		}
	}
	cv::destroyAllWindows();
	cap.release();
	writer.release();
	system("pause");
	return 0;
}

```