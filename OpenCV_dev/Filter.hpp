//
//  Filter.hpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/26.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#ifndef Filter_hpp
#define Filter_hpp

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "global.hpp"

using namespace std;
using namespace cv;

void ContrastAndBrightness(int, void*);
void on_BoxFilter(int, void*);
void on_BlurFilter(int, void*);
void on_GaussianFilter(int, void*);
void on_MedianFilter(int, void*);
void on_BilateralFilter(int, void*);
void on_SwitchMorphology(int, void*);
void on_ElementSize(int, void*);
void Process();

#endif /* Filter_hpp */
