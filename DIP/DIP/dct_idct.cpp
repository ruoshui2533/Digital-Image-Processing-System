#include "dct_idct.h"

void init_dct(Mat & A) // ����8x8�����ɢ���ұ任ϵ��
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

void dct_img(Mat & image, const Mat & A, const Mat & mask) // dct�任
{
	//�ֿ� 8x8
	for (int i = 0; i < 512; i += 8)
	{
		for (int j = 0; j < 512; j += 8)
		{
			//X = AXAT 
			image(Range(i, i + 8), Range(j, j + 8)) = A * image(Range(i, i + 8), Range(j, j + 8)) *A.t();
			//��mask����
			image(Range(i, i + 8), Range(j, j + 8)) /= mask;
		}
	}
}

void idct_img(Mat & image, const Mat & A, const Mat & mask)
{
	//�ֿ�8x8
	for (int i = 0; i < 512; i += 8)
	{
		for (int j = 0; j < 512; j += 8)
		{
			//��ԭ����
			image(Range(i, i + 8), Range(j, j + 8)) = image(Range(i, i + 8), Range(j, j + 8)).mul(mask);
			//X = ATXA
			image(Range(i, i + 8), Range(j, j + 8)) = A.t() * image(Range(i, i + 8), Range(j, j + 8)) * A;
		}
	}
}

void show_dct_idct()
{
	//��ȡͼ��ͼ��Ϊ�Ҷ�ͼ����ͨ��
	Mat image = imread("Lena.bmp", 0);
	Mat fimage;
	Mat A(Size(8, 8), CV_32FC1);// ��ɢ����ϵ������
	//��ʼ��mask��������
	float msk[8][8] = { {16,11,10,16,24,40,51,61},{12,12,14,19,26,58,60,55},{14,13,16,24,40,57,69,56},{14,17,22,29,51,87,80,62},{18,22,37,56,68,109,103,77},{24,35,55,64,81,104,113,92},{49,64,78,87,103,121,120,101},{72,92,95,98,112,100,103,99} };
	Mat mask(8, 8, CV_32FC1, msk);
	//��ʾԭͼ
	if (!image.empty())
		imshow("image", image);
	//����Aϵ��
	init_dct(A);
	//ת���ɸ��������󣬽���dct�任
	image.convertTo(fimage, CV_32FC1);
	dct_img(fimage, A, mask);
	//����ѹ���ʣ� �÷���������������������
	fimage.convertTo(image, CV_8UC1);
	double dctRate = countNonZero(image) / (512.0 * 512.0);
	cout << "the size becomes " << dctRate * 100 << "% of the original." << endl;
	imshow("ѹ��ͼ", fimage);
	//dct���任
	idct_img(fimage, A, mask);
	//��ʾ��ԭ��ͼ��
	fimage.convertTo(image, CV_8UC1);
	imshow("��ԭͼ", image);
	waitKey(0);
}
