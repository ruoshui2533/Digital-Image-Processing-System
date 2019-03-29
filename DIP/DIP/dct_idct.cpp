#include "dct_idct.h"

void init_dct(Mat & A) // 计算8x8块的离散余弦变换系数
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
		{
			double a;
			if (i == 0)
				a = sqrt(1.0 / 8.0);
			else
				a = sqrt(2.0 / 8.0);
			A.ptr<float>(i)[j] = (float)(a * cos((j + 0.5) * CV_PI * i / 8));
		}
}

void dct_img(Mat & image, const Mat & A, const Mat & mask) // dct变换
{
	//分块 8x8
	for (int i = 0; i < 512; i += 8)
	{
		for (int j = 0; j < 512; j += 8)
		{
			//X = AXAT 
			image(Range(i, i + 8), Range(j, j + 8)) = A * image(Range(i, i + 8), Range(j, j + 8)) *A.t();
			//用mask量化
			image(Range(i, i + 8), Range(j, j + 8)) /= mask;
		}
	}
}

void idct_img(Mat & image, const Mat & A, const Mat & mask)
{
	//分块8x8
	for (int i = 0; i < 512; i += 8)
	{
		for (int j = 0; j < 512; j += 8)
		{
			//还原量化
			image(Range(i, i + 8), Range(j, j + 8)) = image(Range(i, i + 8), Range(j, j + 8)).mul(mask);
			//X = ATXA
			image(Range(i, i + 8), Range(j, j + 8)) = A.t() * image(Range(i, i + 8), Range(j, j + 8)) * A;
		}
	}
}

void show_dct_idct()
{
	//读取图像，图像为灰度图，单通道
	Mat image = imread("Lena.bmp", 0);
	Mat fimage;
	Mat A(Size(8, 8), CV_32FC1);// 离散余弦系数矩阵
	//初始化mask量化矩阵
	float msk[8][8] = { {16,11,10,16,24,40,51,61},{12,12,14,19,26,58,60,55},{14,13,16,24,40,57,69,56},{14,17,22,29,51,87,80,62},{18,22,37,56,68,109,103,77},{24,35,55,64,81,104,113,92},{49,64,78,87,103,121,120,101},{72,92,95,98,112,100,103,99} };
	Mat mask(8, 8, CV_32FC1, msk);
	//显示原图
	if (!image.empty())
		imshow("image", image);
	//计算A系数
	init_dct(A);
	//转换成浮点数矩阵，进行dct变换
	image.convertTo(fimage, CV_32FC1);
	dct_img(fimage, A, mask);
	//计算压缩率， 用非零矩阵点数量比总数量、
	fimage.convertTo(image, CV_8UC1);
	double dctRate = countNonZero(image) / (512.0 * 512.0);
	cout << "the size becomes " << dctRate * 100 << "% of the original." << endl;
	imshow("压缩图", fimage);
	//dct反变换
	idct_img(fimage, A, mask);
	//显示还原的图像
	fimage.convertTo(image, CV_8UC1);
	imshow("还原图", image);
	waitKey(0);
}
