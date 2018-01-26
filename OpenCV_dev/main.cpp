//
//  main.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/26.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>


using namespace std;
using namespace cv;

static void ContrastAndBrightness(int, void*);
static void on_BoxFilter(int, void*);
static void on_BlurFilter(int, void*);
static void on_GaussianFilter(int, void*);
static void on_MedianFilter(int, void*);
static void on_BilateralFilter(int, void*);
static void on_SwitchMorphology(int, void*);
static void on_ElementSize(int, void*);
static void Process();

int g_nContrastValue;
int g_nBrightnessValue;
int g_nBoxfilter;
int g_nBlurfilter;
int g_nGaussianFilter;
int g_nMedianFilter;
int g_nBilateralFilter;
int g_Switch;
int g_nElementSize;

Mat g_srcImage, g_dstImage;
Mat g_boxfilter_image;
Mat g_blurfilter_image;
Mat g_gaussian_image;
Mat g_median_image;
Mat g_bilateral_image;
Mat g_Morphology_image;

int main(){
    
    //    Mat dota=imread("/Users/char/Documents/学习/OpenCV/测试图/dota2.jpg");
    //    Mat yyf=imread("/Users/char/Documents/学习/OpenCV/测试图/yyf.jpg");
    //    namedWindow("RUA");
    //    Mat imgROI;
    //    imgROI=dota(Rect(300,50,yyf.cols,yyf.rows));
    //    addWeighted(imgROI, 0.5, yyf, 0.8, 0, imgROI);
    //    imshow("RUA", dota);
    //    imwrite("/Users/char/Documents/学习/OpenCV/测试图/RUA.jpg", dota);
    //
    //    vector<Mat> channels;
    //    split(dota, channels);
    //    namedWindow("Screen");
    //    Mat splited_img=channels.at(2);
    //    imwrite("/Users/char/Documents/学习/OpenCV/测试图/split2.jpg", splited_img);
    //    imshow("Screen",splited_img);
    //
    //    Mat dota2_merge;
    //    vector<Mat> chn(3);
    //    chn[0] = channels[1];
    //    chn[1] = channels[2];
    //    chn[2] = channels[0];
    //    merge(chn, dota2_merge);
    //    imwrite("/Users/char/Documents/学习/OpenCV/测试图/merge.jpg", dota2_merge);
    
    system("color5E");
    //    g_srcImage=imread("/Users/char/Documents/学习/OpenCV/测试图/dota2.jpg");
    //    g_dstImage=Mat::zeros(g_srcImage.size(), g_srcImage.type());
    //    g_nContrastValue=80;
    //    g_nBrightnessValue=80;
    //
    //    namedWindow("Modified Image",0);
    //    createTrackbar("Contrast", "Modified Image", &g_nContrastValue, 300,ContrastAndBrightness);
    //    createTrackbar("Brightness", "Modified Image", &g_nBrightnessValue, 200,ContrastAndBrightness);
    //
    //    ContrastAndBrightness(g_nContrastValue, 0);
    //    ContrastAndBrightness(g_nBrightnessValue, 0);
    //
    
    
    g_srcImage=imread("/Users/char/Documents/学习/OpenCV/测试图/yyf.jpg");
    
    g_boxfilter_image = g_srcImage.clone();
    g_blurfilter_image = g_srcImage.clone();
    g_gaussian_image = g_srcImage.clone();
    g_median_image = g_srcImage.clone();
    g_bilateral_image = g_srcImage.clone();
    g_Morphology_image = g_srcImage.clone();
    
    namedWindow("BoxFilter");
    namedWindow("BlurFilter");
    namedWindow("GaussianFilter");
    namedWindow("MedianFilter");
    namedWindow("BilateralFilter");
    namedWindow("Morphology");
    
    createTrackbar("Size", "BoxFilter", &g_nBoxfilter, 20, on_BoxFilter);
    createTrackbar("Size", "BlurFilter", &g_nBlurfilter, 20, on_BlurFilter);
    createTrackbar("Size", "GaussianFilter", &g_nGaussianFilter, 20, on_GaussianFilter);
    createTrackbar("Size", "MedianFilter", &g_nMedianFilter, 20, on_MedianFilter);
    createTrackbar("Size", "BilateralFilter", &g_nBilateralFilter, 20, on_BilateralFilter);
    createTrackbar("Switch Morphology", "Morphology", &g_Switch, 1, on_SwitchMorphology);
    createTrackbar("Size", "Morphology", &g_nElementSize, 20, on_ElementSize);
    on_BoxFilter(g_nBoxfilter, 0);
    on_BlurFilter(g_nBlurfilter,0);
    on_GaussianFilter(g_nGaussianFilter, 0);
    on_MedianFilter(g_nMedianFilter, 0);
    on_BilateralFilter(g_nBilateralFilter, 0);
    on_SwitchMorphology(g_Switch, 0);
    on_ElementSize(g_nElementSize, 0);
    
    
    
    cout<<"Press Q to quit."<<endl;
    while(char(waitKey(1))!='q'){}
    return 0;
}

static void ContrastAndBrightness(int, void *){
    
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

static void on_BoxFilter(int, void*){
    boxFilter(g_srcImage, g_boxfilter_image, -1, Size(g_nBoxfilter+1,g_nBoxfilter+1));
    imshow("BoxFilter", g_boxfilter_image);
}

static void on_BlurFilter(int, void*){
    blur(g_srcImage, g_blurfilter_image, Size(g_nBlurfilter+1,g_nBlurfilter+1));
    imshow("BlurFilter", g_blurfilter_image);
}

static void on_GaussianFilter(int, void*){
    GaussianBlur(g_srcImage, g_gaussian_image, Size(g_nGaussianFilter*2+1,g_nGaussianFilter*2+1), 0,0);
    imshow("GaussianFilter", g_gaussian_image);
}

static void on_MedianFilter(int, void*){
    medianBlur(g_srcImage, g_median_image, g_nMedianFilter*2+1);
    imshow("MedianFilter", g_median_image);
}

static void on_BilateralFilter(int, void*){
    bilateralFilter(g_srcImage, g_bilateral_image, g_nBilateralFilter, g_nBilateralFilter*2, g_nBilateralFilter/2);
    imshow("BilateralFilter", g_bilateral_image);
}

static void on_SwitchMorphology(int, void*){
    Process();
}

static void on_ElementSize(int, void*){
    Process();
}

static void Process(){
    Mat element = getStructuringElement(MORPH_RECT, Size(2*g_nElementSize+1,2*g_nElementSize+1), Point(g_nElementSize, g_nElementSize));
    if(g_Switch==0){
        erode(g_srcImage, g_Morphology_image, element);
    }
    else{
        dilate(g_srcImage, g_Morphology_image, element);
    }
    imshow("Morphology", g_Morphology_image);
}






