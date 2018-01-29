//
//  global.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/26.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include "global.hpp"

int g_nContrastValue = 0;
int g_nBrightnessValue = 0;
int g_nBoxfilter = 0;
int g_nBlurfilter = 0;
int g_nGaussianFilter = 0;
int g_nMedianFilter = 0;
int g_nBilateralFilter = 0;
int g_Switch = 0;
int g_nElementSize = 0;
int g_nErodeDilate = 0;
int g_nOpenClose = 0;
int g_nTopBlackHat = 0;
int g_SwitchOpenClose = 0;
int g_SwitchTopBlackHat = 0;
int g_SwitchErodeDilate = 0;
int g_nElementType = 0;
int g_nthreshold = 0;
int g_nFillMode = 1;
int g_nLowDiff = 20;
int g_nUpDiff = 20;
int g_nConnectivity = 4;
int g_nNewMaskVal = 255;
int g_nHarrisThresh = 100;
int g_nHarrisMaxVal = 0;

bool g_bIsColor = true;
bool g_bUseMask = false;

Mat g_srcImage, g_dstImage, g_tempImage, g_maskImage, g_grayImage;
Mat g_map_x, g_map_y;

string type2str(int type) {
    string r;
    
    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);
    
    switch ( depth ) {
        case CV_8U:  r = "8U"; break;
        case CV_8S:  r = "8S"; break;
        case CV_16U: r = "16U"; break;
        case CV_16S: r = "16S"; break;
        case CV_32S: r = "32S"; break;
        case CV_32F: r = "32F"; break;
        case CV_64F: r = "64F"; break;
        default:     r = "User"; break;
    }
    
    r += "C";
    r += (chans+'0');
    
    return r;
}

vector<Vec4i> g_lines;
