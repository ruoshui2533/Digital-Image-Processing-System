#include "mouse_info.h"

Point mouse_Point = Point(0, 0);

void on_mouse(int event, int x, int y, int flags, void * param)
{
	if (event == EVENT_MOUSEMOVE) // 鼠标移动时实时传输鼠标坐标到全局变量mousePoint中
	{
		mouse_Point = Point(x, y);
	}
}

void show_mouse_info()
{
	Mat img = imread("Lena.bmp", 0);
	Mat temp;
	int n; // 存取灰度值
	while (1) // Esc的ASCII码为27
	{
		if (waitKey(30) == 27)
		{
			destroyWindow("Lena");
			break;
		}
		else
		{
			img.copyTo(temp);
			namedWindow("Lena");
			setMouseCallback("Lena", on_mouse); // 接收on_mouse中的鼠标坐标信息
			if (mouse_Point.x >= 0 && mouse_Point.x < temp.cols && mouse_Point.y >= 0 && mouse_Point.y < temp.rows)
			{
				n = temp.at<uchar>(mouse_Point.y, mouse_Point.x); // image.at<uchar>(i,j)：取出灰度图像中i行j列的点
			}
			putText(
				temp,
				"(" + to_string(mouse_Point.x) + "," + to_string(mouse_Point.y) + ")",
				mouse_Point - Point(0, 8),
				FONT_HERSHEY_SIMPLEX,
				0.5,
				Scalar(0, 0, 0, 255)
			); // 将鼠标坐标信息显示在图像上
			putText(
				temp,
				"(" + String("Grayscale:") + to_string(n) + ")",
				mouse_Point + Point(0, 8),
				FONT_HERSHEY_SIMPLEX,
				0.5,
				Scalar(0, 0, 0, 255)
			); // 将鼠标坐标的RGB信息显示在图像上
			imshow("Lena", temp);
		}
	}
}
