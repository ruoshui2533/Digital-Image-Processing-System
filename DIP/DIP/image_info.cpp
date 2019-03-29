#include "image_info.h"

void show_image_info()
{
	Mat src = imread("Lena.bmp", 0);
	int gray = 0;
	int min_gray = 255;
	int max_gray = 0;
	int sum_gray = 0;
	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			gray = src.at<uchar>(i, j);
			if (min_gray > gray)
			{
				min_gray = gray;
			}
			if (max_gray < gray)
			{
				max_gray = gray;
			}
			sum_gray = sum_gray + gray;
		}
	}
	double mean_gray = sum_gray / 262144.0;
	cout << "图像灰度最小值:" << min_gray << endl;
	cout << "图像灰度最大值:" << max_gray << endl;
	cout << "图像灰度的均值:" << mean_gray << endl;
}
