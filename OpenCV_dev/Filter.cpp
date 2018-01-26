//
//  Filter.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/26.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include "Filter.hpp"

void ContrastAndBrightness(int, void *){
    
    namedWindow("Original Image",0);
    
    for(int y=0;y<g_srcImage.rows;y++){
        for(int x=0;x<g_srcImage.cols;x++){
            for(int c=0;c<3;c++){
                g_dstImage.at<Vec3b>(y,x)[c]=saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y,x)[c])+g_nBrightnessValue);
            }
        }
    }
    imshow("Original Image",g_srcImage);
    imshow("Modified Image",g_dstImage);
}

void on_BoxFilter(int, void*){
    boxFilter(g_srcImage, g_dstImage, -1, Size(g_nBoxfilter+1,g_nBoxfilter+1));
    imshow("BoxFilter", g_dstImage);
}

void on_BlurFilter(int, void*){
    blur(g_srcImage, g_dstImage, Size(g_nBlurfilter+1,g_nBlurfilter+1));
    imshow("BlurFilter", g_dstImage);
}

void on_GaussianFilter(int, void*){
    GaussianBlur(g_srcImage, g_dstImage, Size(g_nGaussianFilter*2+1,g_nGaussianFilter*2+1), 0,0);
    imshow("GaussianFilter", g_dstImage);
}

void on_MedianFilter(int, void*){
    medianBlur(g_srcImage, g_dstImage, g_nMedianFilter*2+1);
    imshow("MedianFilter", g_dstImage);
}

void on_BilateralFilter(int, void*){
    bilateralFilter(g_srcImage, g_dstImage, g_nBilateralFilter, g_nBilateralFilter*2, g_nBilateralFilter/2);
    imshow("BilateralFilter", g_dstImage);
}

void on_SwitchMorphology(int, void*){
    Process();
}

void on_ElementSize(int, void*){
    Process();
}

void Process(){
    Mat element = getStructuringElement(MORPH_RECT, Size(2*g_nElementSize+1,2*g_nElementSize+1), Point(g_nElementSize, g_nElementSize));
    if(g_Switch==0){
        erode(g_srcImage, g_dstImage, element);
    }
    else{
        dilate(g_srcImage, g_dstImage, element);
    }
    imshow("Morphology", g_dstImage);
}


