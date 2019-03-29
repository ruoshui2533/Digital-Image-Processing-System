#include "histogram_equal.h"

//void show_histogram()
//{
//	Mat src = imread("Lena.bmp", 0);
//	imshow("Source", src);
//	int pixel[256] = { 0 };
//	int gray;
//	for (int i = 0; i < src.rows; i++)
//	{
//		for (int j = 0; j < src.cols; j++)
//		{
//			gray = src.at<uchar>(i, j);
//			pixel[gray]++;
//		}
//	}
//	//std::cout << pixel[24] << std::endl;
//	int max = 0;
//	for (int m = 0; m < 256; m++)
//	{
//		if (max < pixel[m])
//		{
//			max = pixel[m];
//		}
//	}
//	Mat hist_img = Mat::zeros(max, 256, CV_8UC1);
//	Mat resize_img;
//	for (int k = 0; k < 256; k++)
//	{
//		if (pixel[k] != 0) 
//		{ 
//			hist_img.col(k).rowRange(Range(max - pixel[k], max)) = 255; 
//		}
//	}
//	resize(hist_img, resize_img, Size(256, 256));
//	imshow("Histogram", resize_img);
//	waitKey(0);
//}
//
//void show_equal_hist()
//{
//	Mat src = imread("Lena.bmp", 0);
//	int pixel[256] = { 0 };
//	int gray;
//	double count = 0;
//	for (int i = 0; i < src.rows; i++)
//	{
//		for (int j = 0; j < src.cols; j++)
//		{
//			gray = src.at<uchar>(i, j);
//			pixel[gray]++;
//			count++;
//		}
//	}
//	int temp_pixel[256] = { 0 };
//	for (int m = 0; m < 256; m++)
//	{
//		if (m == 0)
//		{
//			temp_pixel[m] = pixel[m];
//		}
//		else
//		{
//			temp_pixel[m] = temp_pixel[m - 1] + pixel[m];
//		}
//	}
//	int new_pixel[256] = { 0 };
//	for (int n = 0; n < 256; n++)
//	{
//		int k = int((temp_pixel[n] / count) * 255);
//		new_pixel[k] = pixel[n];
//	}
//	for (int a = 0; a < src.rows; a++)
//	{
//		for (int b = 0; b < src.cols; b++)
//		{
//			gray = src.at<uchar>(a, b);
//			src.at<uchar>(a, b) = int(temp_pixel[gray] / count * 255);
//		}
//	}
//	imshow("Equalized", src);
//	int max = 0;
//	for (int m = 0; m < 256; m++)
//	{
//		if (max < new_pixel[m])
//		{
//			max = new_pixel[m];
//		}
//	}
//	Mat hist_img = Mat::zeros(max, 256, CV_8UC1);
//	Mat resize_img;
//	for (int k = 0; k < 256; k++)
//	{
//		if (new_pixel[k] != 0)
//		{
//			hist_img.col(k).rowRange(Range(max - new_pixel[k], max)) = 255;
//		}
//	}
//	resize(hist_img, resize_img, Size(256, 256));
//	imshow("Histogram", resize_img);
//	waitKey(0);
//}

void show_hist_equal()
{
	Mat src = imread("Lena.bmp", 0);							// 读取灰度图片
	int pixel[256] = { 0 };										// 存储原图灰度值信息
	int temp_pixel[256] = { 0 };								// 存储累积灰度值信息
	int new_pixel[256] = { 0 };									// 存储直方图均衡化后的灰度值信息
	int max = 0;												// 存取灰度值的最大个数，作为直方图的纵坐标最大值
	double count = 0.0;											// 总像素个数
	for (int i = 0; i < src.rows; i++)							// 遍历图片获取灰度值数组和总像素个数
	{
		for (int j = 0; j < src.cols; j++)
		{
			pixel[src.at<uchar>(i, j)]++;
			count++;
		}
	}
	for (int m = 0; m < 256; m++)								// 获取灰度值的最大个数
	{
		if (max < pixel[m])
		{
			max = pixel[m];
		}
	}
	Mat hist_img = Mat::zeros(max, 256, CV_8UC1);				// 构建直方图，初始化高度为max
	Mat resize_img;												// 按比例缩放后的直方图，便于查看
	for (int k = 0; k < 256; k++)								// 绘制直方图
	{
		if (pixel[k] != 0)
		{
			hist_img.col(k).rowRange(Range(max - pixel[k], max)) = 255;
		}
	}
	resize(hist_img, resize_img, Size(256, 256));				// 按比例缩放直方图
	imshow("Histogram", resize_img);							// 显示缩放后的直方图
	imshow("Source", src);										// 显示原图
	for (int m = 0; m < 256; m++)								// 构建累计灰度值数组
	{
		if (m == 0)
		{
			temp_pixel[m] = pixel[m];
		}
		else
		{
			temp_pixel[m] = temp_pixel[m - 1] + pixel[m];
		}
	}
	for (int n = 0; n < 256; n++)								// 构建直方图均衡化后的灰度值数组
	{
		new_pixel[int(round((temp_pixel[n] / count) * 255))] = pixel[n];
	}
	Mat equal_hist_img = Mat::zeros(max, 256, CV_8UC1);			// 构建均衡化直方图，初始化高度为max
	Mat equal_resize_img;										// 按比例缩放后的均衡化直方图，便于查看
	for (int k = 0; k < 256; k++)								// 绘制均衡化直方图
	{
		if (new_pixel[k] != 0)
		{
			equal_hist_img.col(k).rowRange(Range(max - new_pixel[k], max)) = 255;
		}
	}
	resize(equal_hist_img, equal_resize_img, Size(256, 256));	// 按比例缩放均衡化直方图
	imshow("EqualizedHistogram", equal_resize_img);				// 显示缩放后的均衡化直方图
	for (int a = 0; a < src.rows; a++)							// 对原图进行灰度值映射变化
	{
		for (int b = 0; b < src.cols; b++)
		{
			src.at<uchar>(a, b) = int(round(temp_pixel[src.at<uchar>(a, b)] / count * 255));
		}
	}
	imshow("Equalized", src);									// 显示均衡化后的图片
	waitKey(0);
}
