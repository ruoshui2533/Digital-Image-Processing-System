#include "rotate.h"

void img_rotate(double angle)
{
	Mat srcImage = imread("Lena.bmp", 0);
	imshow("Source", srcImage);
	Mat dstImage;
	double sita = angle * CV_PI / 180;
	double a = (srcImage.cols - 1) / 2.0 + 0.5;
	double b = (srcImage.rows - 1) / 2.0 + 0.5;

	int nRowNum = srcImage.rows;
	int nColNum = srcImage.cols;
	dstImage.create(nRowNum, nColNum, srcImage.type());

	double f1 = -a * cos(sita) + b * sin(sita) + a;
	double f2 = -a * sin(sita) - b * cos(sita) + b;

	for (int i = 0; i < nRowNum; i++)
	{
		for (int j = 0; j < nColNum; j++)
		{
			int x = cvRound(j * cos(sita) - i * sin(sita) + f1);
			int y = cvRound(j * sin(sita) + i * cos(sita) + f2);
			if (x > 0 && x < nColNum && y > 0 && y < nRowNum)
			{
				dstImage.at<uchar>(i, j) = srcImage.at<uchar>(y, x);
			}
		}
	}
	imshow("Rotate", dstImage);
	waitKey(0);
}
