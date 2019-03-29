#include "saltpep_median_sobel.h"

void add_salt_pepper(Mat img, int n)
{
	for (int k = 0; k < n; k++)
	{
		img.at<uchar>(std::rand() % img.cols, std::rand() % img.rows) = 255;
		img.at<uchar>(std::rand() % img.cols, std::rand() % img.rows) = 0;
	}
}

void median_blur(int n)
{
	Mat img = imread("Lena.bmp", 0);
	imshow("Source", img);
	add_salt_pepper(img, 3000);
	imshow("Salt_Pepper", img);
	int temp[100] = { 0 };
	for (int i = n / 2; i < img.cols - n / 2; i++)
	{
		for (int j = n / 2; j < img.rows - n / 2; j++)
		{
			int count = 0;
			for (int a = i - n / 2; a <= i + n / 2; a++)
			{
				for (int b = j - n / 2; b <= j + n / 2; b++)
				{
					temp[count] = img.at<uchar>(a, b);
					count++;
				}
			}
			std::sort(temp, temp + count);
			img.at<uchar>(i, j) = temp[count / 2];
		}
	}
	imshow("MedianBlur", img);
	waitKey(0);
}

void sobel()
{
	Mat src = imread("Lena.bmp", 0);
	Mat img;
	src.copyTo(img);
	imshow("Source", src);
	int temp[3][3] = { {0} };
	for (int a = 1; a < src.cols - 1; a++)
	{
		for (int b = 1; b < src.rows - 1; b++)
		{
			temp[0][0] = src.at<uchar>(a - 1, b - 1);
			temp[0][1] = src.at<uchar>(a, b - 1);
			temp[0][2] = src.at<uchar>(a + 1, b - 1);
			temp[1][0] = src.at<uchar>(a  - 1, b);
			temp[1][1] = src.at<uchar>(a, b);
			temp[1][2] = src.at<uchar>(a + 1, b);
			temp[2][0] = src.at<uchar>(a - 1, b + 1);
			temp[2][1] = src.at<uchar>(a, b + 1);
			temp[2][2] = src.at<uchar>(a + 1, b + 1);
			double ux = temp[0][0] * (-1) + temp[0][1] * (-2) + temp[0][2] * (-1) + temp[2][0] * 1 + temp[2][1] * 2 + temp[2][2] * 1;
			double uy = temp[0][2] * (-1) + temp[1][2] * (-2) + temp[2][2] * (-1) + temp[0][0] * 1 + temp[1][0] * 2 + temp[2][0] * 1;
			double gray = std::sqrt(ux * ux + uy * uy);
			img.at<uchar>(a, b) = int(gray);
		}
	}
	imshow("Sobel", img);
	waitKey(0);
}

