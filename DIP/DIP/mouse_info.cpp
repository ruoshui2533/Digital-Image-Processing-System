#include "mouse_info.h"

Point mouse_Point = Point(0, 0);

void on_mouse(int event, int x, int y, int flags, void * param)
{
	if (event == EVENT_MOUSEMOVE) // ����ƶ�ʱʵʱ����������굽ȫ�ֱ���mousePoint��
	{
		mouse_Point = Point(x, y);
	}
}

void show_mouse_info()
{
	Mat img = imread("Lena.bmp", 0);
	Mat temp;
	int n; // ��ȡ�Ҷ�ֵ
	while (1) // Esc��ASCII��Ϊ27
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
			setMouseCallback("Lena", on_mouse); // ����on_mouse�е����������Ϣ
			if (mouse_Point.x >= 0 && mouse_Point.x < temp.cols && mouse_Point.y >= 0 && mouse_Point.y < temp.rows)
			{
				n = temp.at<uchar>(mouse_Point.y, mouse_Point.x); // image.at<uchar>(i,j)��ȡ���Ҷ�ͼ����i��j�еĵ�
			}
			putText(
				temp,
				"(" + to_string(mouse_Point.x) + "," + to_string(mouse_Point.y) + ")",
				mouse_Point - Point(0, 8),
				FONT_HERSHEY_SIMPLEX,
				0.5,
				Scalar(0, 0, 0, 255)
			); // �����������Ϣ��ʾ��ͼ����
			putText(
				temp,
				"(" + String("Grayscale:") + to_string(n) + ")",
				mouse_Point + Point(0, 8),
				FONT_HERSHEY_SIMPLEX,
				0.5,
				Scalar(0, 0, 0, 255)
			); // ����������RGB��Ϣ��ʾ��ͼ����
			imshow("Lena", temp);
		}
	}
}
