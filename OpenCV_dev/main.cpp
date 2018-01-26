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
#include "Filter.hpp"
#include "EdgeDetection.hpp"

using namespace std;
using namespace cv;



int main(){
    
    /*    import image
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
    */
    
    system("color5E");
        g_srcImage=imread("/Users/char/Documents/学习/OpenCV/测试图/dota2.jpg");
        g_dstImage=Mat::zeros(g_srcImage.size(), g_srcImage.type());
        g_nContrastValue=80;
        g_nBrightnessValue=80;
    
        namedWindow("Modified Image",0);
        createTrackbar("Contrast", "Modified Image", &g_nContrastValue, 300,ContrastAndBrightness);
        createTrackbar("Brightness", "Modified Image", &g_nBrightnessValue, 200,ContrastAndBrightness);
    
        ContrastAndBrightness(g_nContrastValue, 0);
        ContrastAndBrightness(g_nBrightnessValue, 0);
    
    
    g_srcImage=imread("/Users/char/Documents/学习/OpenCV/测试图/dota2.jpg");

    /* Filter
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
    */
     
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
