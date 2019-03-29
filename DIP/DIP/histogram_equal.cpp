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
	Mat src = imread("Lena.bmp", 0);							// ��ȡ�Ҷ�ͼƬ
	int pixel[256] = { 0 };										// �洢ԭͼ�Ҷ�ֵ��Ϣ
	int temp_pixel[256] = { 0 };								// �洢�ۻ��Ҷ�ֵ��Ϣ
	int new_pixel[256] = { 0 };									// �洢ֱ��ͼ���⻯��ĻҶ�ֵ��Ϣ
	int max = 0;												// ��ȡ�Ҷ�ֵ������������Ϊֱ��ͼ�����������ֵ
	double count = 0.0;											// �����ظ���
	for (int i = 0; i < src.rows; i++)							// ����ͼƬ��ȡ�Ҷ�ֵ����������ظ���
	{
		for (int j = 0; j < src.cols; j++)
		{
			pixel[src.at<uchar>(i, j)]++;
			count++;
		}
	}
	for (int m = 0; m < 256; m++)								// ��ȡ�Ҷ�ֵ��������
	{
		if (max < pixel[m])
		{
			max = pixel[m];
		}
	}
	Mat hist_img = Mat::zeros(max, 256, CV_8UC1);				// ����ֱ��ͼ����ʼ���߶�Ϊmax
	Mat resize_img;												// ���������ź��ֱ��ͼ�����ڲ鿴
	for (int k = 0; k < 256; k++)								// ����ֱ��ͼ
	{
		if (pixel[k] != 0)
		{
			hist_img.col(k).rowRange(Range(max - pixel[k], max)) = 255;
		}
	}
	resize(hist_img, resize_img, Size(256, 256));				// ����������ֱ��ͼ
	imshow("Histogram", resize_img);							// ��ʾ���ź��ֱ��ͼ
	imshow("Source", src);										// ��ʾԭͼ
	for (int m = 0; m < 256; m++)								// �����ۼƻҶ�ֵ����
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
	for (int n = 0; n < 256; n++)								// ����ֱ��ͼ���⻯��ĻҶ�ֵ����
	{
		new_pixel[int(round((temp_pixel[n] / count) * 255))] = pixel[n];
	}
	Mat equal_hist_img = Mat::zeros(max, 256, CV_8UC1);			// �������⻯ֱ��ͼ����ʼ���߶�Ϊmax
	Mat equal_resize_img;										// ���������ź�ľ��⻯ֱ��ͼ�����ڲ鿴
	for (int k = 0; k < 256; k++)								// ���ƾ��⻯ֱ��ͼ
	{
		if (new_pixel[k] != 0)
		{
			equal_hist_img.col(k).rowRange(Range(max - new_pixel[k], max)) = 255;
		}
	}
	resize(equal_hist_img, equal_resize_img, Size(256, 256));	// ���������ž��⻯ֱ��ͼ
	imshow("EqualizedHistogram", equal_resize_img);				// ��ʾ���ź�ľ��⻯ֱ��ͼ
	for (int a = 0; a < src.rows; a++)							// ��ԭͼ���лҶ�ֵӳ��仯
	{
		for (int b = 0; b < src.cols; b++)
		{
			src.at<uchar>(a, b) = int(round(temp_pixel[src.at<uchar>(a, b)] / count * 255));
		}
	}
	imshow("Equalized", src);									// ��ʾ���⻯���ͼƬ
	waitKey(0);
}
