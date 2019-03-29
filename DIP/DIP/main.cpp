#include "mouse_info.h"
#include "image_info.h"
#include "histogram_equal.h"
#include "saltpep_median_sobel.h"
#include "rotate.h"
#include "dct_idct.h"

int main()
{
	while (1)
	{
		cout << "||-数字图像处理系统-" << endl;
		cout << "||1.计算图像统计参数" << endl;
		cout << "||2.实时显示坐标灰度" << endl;
		cout << "||3.显示直方图并均衡" << endl;
		cout << "||4.图像平滑中值滤波" << endl;
		cout << "||5.图像锐化：Sobel" << endl; 
		cout << "||6.图像旋转任意角度" << endl;
		cout << "||7.DCT变换以及还原" << endl;
		cout << "||8.退出图像处理系统" << endl;
		cout << "||  请输入你的选择" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1 :
			show_image_info();
			break;
		case 2 :
			show_mouse_info();
			break;
		case 3 :
			show_hist_equal();
			break;
		case 4 :
			cout << "请输入中值滤波模板大小(1-9):";
			int m;
			cin >> m;
			median_blur(m);
			break;
		case 5 :
			sobel();
			break;
		case 6 :
			cout << "请输入旋转角度的大小:";
			double angle;
			cin >> angle;
			img_rotate(angle);
			break;
		case 7 :
			show_dct_idct();
			break;
		case 8 :
			return 0;
		}
	}
}