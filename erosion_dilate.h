#ifndef _erosion_dilate_
#define _erosion_dilate_

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int erosion_dilate(Mat image);

void tb_erosion(int value, void* userdata);

void tb_dilate(int value, void* userdata);

#endif
