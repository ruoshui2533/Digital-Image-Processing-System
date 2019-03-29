#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

extern Point mouse_Point; // 用来存储鼠标实时坐标

void on_mouse(int event, int x, int y, int flags, void* param); // 通过回调函数setMouseCallback传输鼠标实时坐标

void show_mouse_info(); // 实时显示图像上鼠标定位的每个点的坐标和RGB信息
