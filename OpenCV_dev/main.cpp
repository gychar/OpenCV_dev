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
#include "global.hpp"

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
static void Affichage();
static void on_OpenClose(int, void*);
static void on_TopBlackHat(int, void*);
static void on_ErodeDilate(int, void*);
static void on_SwitchOpenClose(int, void*);
static void on_SwitchErodeDilate(int, void*);
static void on_SwitchTopBlackHat(int, void*);
static void OpenClose_process();
static void ErodeDilate_process();
static void TopBlackHat_process();

Mat g_srcImage, g_dstImage;

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
    
    
    g_srcImage=imread("/Users/char/Documents/学习/OpenCV/测试图/dota2.jpg");
    
//    namedWindow("BoxFilter");
//    namedWindow("BlurFilter");
//    namedWindow("GaussianFilter");
//    namedWindow("MedianFilter");
//    namedWindow("BilateralFilter");
//    namedWindow("Morphology");
//
//    createTrackbar("Size", "BoxFilter", &g_nBoxfilter, 20, on_BoxFilter);
//    createTrackbar("Size", "BlurFilter", &g_nBlurfilter, 20, on_BlurFilter);
//    createTrackbar("Size", "GaussianFilter", &g_nGaussianFilter, 20, on_GaussianFilter);
//    createTrackbar("Size", "MedianFilter", &g_nMedianFilter, 20, on_MedianFilter);
//    createTrackbar("Size", "BilateralFilter", &g_nBilateralFilter, 20, on_BilateralFilter);
//    createTrackbar("Switch Morphology", "Morphology", &g_Switch, 1, on_SwitchMorphology);
//    createTrackbar("Size", "Morphology", &g_nElementSize, 20, on_ElementSize);
//    on_BoxFilter(g_nBoxfilter, 0);
//    on_BlurFilter(g_nBlurfilter,0);
//    on_GaussianFilter(g_nGaussianFilter, 0);
//    on_MedianFilter(g_nMedianFilter, 0);
//    on_BilateralFilter(g_nBilateralFilter, 0);
//    on_SwitchMorphology(g_Switch, 0);
//    on_ElementSize(g_nElementSize, 0);
    
    Affichage();
    
    namedWindow("Erode&Dilate");
    namedWindow("Open&Close");
    namedWindow("TopHat&BlackHat");
    
    createTrackbar("Switch", "Erode&Dilate", &g_SwitchErodeDilate, 1, on_SwitchErodeDilate);
    createTrackbar("Size", "Erode&Dilate", &g_nErodeDilate, 20, on_ErodeDilate);
    createTrackbar("Switch", "Open&Close", &g_SwitchOpenClose, 1, on_SwitchOpenClose);
    createTrackbar("Size", "Open&Close", &g_nOpenClose, 20, on_OpenClose);
    createTrackbar("Switch", "TopHat&BlackHat", &g_SwitchTopBlackHat, 1, on_SwitchTopBlackHat);
    createTrackbar("Size", "TopHat&BlackHat", &g_nTopBlackHat, 20, on_TopBlackHat);

    on_SwitchErodeDilate(g_SwitchErodeDilate, 0);
    on_SwitchOpenClose(g_SwitchOpenClose, 0);
    on_SwitchTopBlackHat(g_SwitchTopBlackHat, 0);
    
    // Canny
    Mat cannytest = g_srcImage;
    Mat dst, gray, edge;
    dst.create(g_srcImage.size(), g_srcImage.type());
    cvtColor(g_srcImage, gray, CV_BGR2GRAY);
    blur(gray, edge, Size(3,3));
    Canny(edge, edge, 3, 9);
    dst = Scalar::all(0);
    g_srcImage.copyTo(dst, edge);
    imshow("Canny2", dst);
    Canny(g_srcImage, cannytest, 80, 150);
    imshow("Canny", cannytest);
//    cout<<"Press Q to quit."<<endl;
//    while(char(waitKey(1))!='q'){}
    
    while(1){
        int c;
 
        on_ErodeDilate(g_nErodeDilate, 0);
        on_OpenClose(g_nOpenClose, 0);
        on_TopBlackHat(g_nTopBlackHat, 0);

        c=waitKey(0);
        if((char)c=='q'||(char)c==27)
            break;
        if((char)c=='r') // R
            g_nElementType=MORPH_RECT;
        else if((char)c=='e') // E
            g_nElementType=MORPH_ELLIPSE;
        else if((char)c=='c') // C
            g_nElementType=MORPH_CROSS;
    }

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
    boxFilter(g_srcImage, g_dstImage, -1, Size(g_nBoxfilter+1,g_nBoxfilter+1));
    imshow("BoxFilter", g_dstImage);
}

static void on_BlurFilter(int, void*){
    blur(g_srcImage, g_dstImage, Size(g_nBlurfilter+1,g_nBlurfilter+1));
    imshow("BlurFilter", g_dstImage);
}

static void on_GaussianFilter(int, void*){
    GaussianBlur(g_srcImage, g_dstImage, Size(g_nGaussianFilter*2+1,g_nGaussianFilter*2+1), 0,0);
    imshow("GaussianFilter", g_dstImage);
}

static void on_MedianFilter(int, void*){
    medianBlur(g_srcImage, g_dstImage, g_nMedianFilter*2+1);
    imshow("MedianFilter", g_dstImage);
}

static void on_BilateralFilter(int, void*){
    bilateralFilter(g_srcImage, g_dstImage, g_nBilateralFilter, g_nBilateralFilter*2, g_nBilateralFilter/2);
    imshow("BilateralFilter", g_dstImage);
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
        erode(g_srcImage, g_dstImage, element);
    }
    else{
        dilate(g_srcImage, g_dstImage, element);
    }
    imshow("Morphology", g_dstImage);
}

static void on_OpenClose(int, void*){
    OpenClose_process();
}

static void on_TopBlackHat(int, void*){
    TopBlackHat_process();
}

static void on_ErodeDilate(int, void*){
    ErodeDilate_process();
}

static void on_SwitchOpenClose(int, void*){
    OpenClose_process();
}

static void on_SwitchErodeDilate(int, void*){
    ErodeDilate_process();
}

static void on_SwitchTopBlackHat(int, void*){
    TopBlackHat_process();
}

static void ErodeDilate_process(){
    Mat element=getStructuringElement(g_nElementType, Size(2*g_nErodeDilate+1,2*g_nErodeDilate+1), Point(g_nErodeDilate,g_nErodeDilate));
    if(g_SwitchErodeDilate==0){
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_ERODE, element);
    }
    else{
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_DILATE, element);
    }
    imshow("Erode&Dilate", g_dstImage);
}

static void OpenClose_process(){
    Mat element=getStructuringElement(g_nElementType, Size(2*g_nOpenClose+1,2*g_nOpenClose+1), Point(g_nOpenClose,g_nOpenClose));
    if(g_SwitchOpenClose==0){
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_OPEN, element);
    }
    else{
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_CLOSE, element);
    }
    imshow("Open&Close", g_dstImage);
}

static void TopBlackHat_process(){
    Mat element=getStructuringElement(g_nElementType, Size(2*g_nTopBlackHat+1,2*g_nTopBlackHat+1), Point(g_nTopBlackHat,g_nTopBlackHat));
    if(g_SwitchTopBlackHat==0){
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_TOPHAT, element);
    }
    else{
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_BLACKHAT, element);
    }
    imshow("TopHat&BlackHat", g_dstImage);
}

static void Affichage(){
    cout<<"ESC/Q to exit"<<endl<<"R for Rectangle element"<<endl<<"E for Elliptic element"<<endl<<"C for Cross-shaped element"<<endl;
}
