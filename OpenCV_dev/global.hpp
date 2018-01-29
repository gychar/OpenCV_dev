//
//  global.hpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/26.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#ifndef global_hpp
#define global_hpp

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

extern int g_nContrastValue;
extern int g_nBrightnessValue;
extern int g_nBoxfilter;
extern int g_nBlurfilter;
extern int g_nGaussianFilter;
extern int g_nMedianFilter;
extern int g_nBilateralFilter;
extern int g_Switch;
extern int g_nElementSize;
extern int g_nErodeDilate, g_nOpenClose, g_nTopBlackHat;
extern int g_SwitchOpenClose, g_SwitchTopBlackHat, g_SwitchErodeDilate;
extern int g_nElementType;
extern int g_nthreshold;
extern int g_nFillMode;
extern int g_nLowDiff, g_nUpDiff;
extern int g_nConnectivity;
extern int g_nNewMaskVal;
extern int g_nHarrisThresh, g_nHarrisMaxVal;

extern bool g_bIsColor, g_bUseMask;

extern Mat g_srcImage, g_dstImage, g_tempImage, g_maskImage, g_grayImage;
extern Mat g_map_x, g_map_y;

extern vector<Vec4i> g_lines;

string type2str(int type);

#endif /* global_hpp */
