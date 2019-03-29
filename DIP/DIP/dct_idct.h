#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void init_dct(Mat &A);

void dct_img(Mat &image, const Mat &A, const Mat &mask);

void idct_img(Mat &image, const Mat &A, const Mat &mask);

void show_dct_idct();