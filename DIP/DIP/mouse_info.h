#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

extern Point mouse_Point; // �����洢���ʵʱ����

void on_mouse(int event, int x, int y, int flags, void* param); // ͨ���ص�����setMouseCallback�������ʵʱ����

void show_mouse_info(); // ʵʱ��ʾͼ������궨λ��ÿ����������RGB��Ϣ
