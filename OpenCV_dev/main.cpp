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
#include "Morphology.hpp"
#include "Pyramide.hpp"
#include "Hough.hpp"

using namespace std;
using namespace cv;

int main(){
    
    g_srcImage=imread("/Users/char/Documents/学习/OpenCV/测试图/china.jpg");
    g_dstImage=Mat::zeros(g_srcImage.size(), g_srcImage.type());
    
    /*    import image
    Mat dota=imread("/Users/char/Documents/学习/OpenCV/测试图/dota2.jpg");
    Mat yyf=imread("/Users/char/Documents/学习/OpenCV/测试图/yyf.jpg");
    namedWindow("RUA");
    Mat imgROI;
    imgROI=dota(Rect(300,50,yyf.cols,yyf.rows));
    addWeighted(imgROI, 0.5, yyf, 0.8, 0, imgROI);
    imshow("RUA", dota);
    imwrite("/Users/char/Documents/学习/OpenCV/测试图/RUA.jpg", dota);

    vector<Mat> channels;
    split(dota, channels);
    namedWindow("Screen");
    Mat splited_img=channels.at(2);
    imwrite("/Users/char/Documents/学习/OpenCV/测试图/split2.jpg", splited_img);
    imshow("Screen",splited_img);

    Mat dota2_merge;
    vector<Mat> chn(3);
    chn[0] = channels[1];
    chn[1] = channels[2];
    chn[2] = channels[0];
    merge(chn, dota2_merge);
    imwrite("/Users/char/Documents/学习/OpenCV/测试图/merge.jpg", dota2_merge);
    */
    
    /* Contrast & Brightness
     
    namedWindow("Modified Image",0);
    createTrackbar("Contrast", "Modified Image", &g_nContrastValue, 300,ContrastAndBrightness);
    createTrackbar("Brightness", "Modified Image", &g_nBrightnessValue, 200,ContrastAndBrightness);
     
    ContrastAndBrightness(g_nContrastValue, 0);
    ContrastAndBrightness(g_nBrightnessValue, 0);
    */
    
    /* Filter
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
    */
    
    /* Morphology
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
    */
    
    /* Edge Detection

    // Canny
    Mat cannytest = g_srcImage;
    Mat canny_dst, gray, edge;
    canny_dst.create(g_srcImage.size(), g_srcImage.type());
    cvtColor(g_srcImage, gray, CV_BGR2GRAY);
    blur(gray, edge, Size(3,3));
    Canny(edge, edge, 3, 9);
    canny_dst = Scalar::all(0);
    g_srcImage.copyTo(canny_dst, edge);
    imshow("Canny2", canny_dst);
    Canny(g_srcImage, cannytest, 80, 150);
    imshow("Canny", cannytest);

    // Sobel
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y, sobel_dst;
    Sobel(g_srcImage, grad_x, g_srcImage.depth(), 1, 0, 3);
    convertScaleAbs(grad_x, abs_grad_x);
    Sobel(g_srcImage, grad_y, g_srcImage.depth(), 0, 1, 3);
    convertScaleAbs(grad_y, abs_grad_y);
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, sobel_dst);
    imshow("Sobel", sobel_dst);

    // Laplace
    Mat laplace_dst, laplace_abs;
    GaussianBlur(g_srcImage, laplace_dst, Size(3,3), 0, 0);
//    cvtColor(laplace_dst, laplace_dst, CV_BGR2GRAY);
    Laplacian(laplace_dst, laplace_dst, g_srcImage.depth(), 3, 1, 0);
    convertScaleAbs(laplace_dst, laplace_abs);
    imshow("Laplace", laplace_abs);

    // Scharr ( Sobel size=3)
    Mat scharr_grad_x, scharr_grad_y, scharr_dst;
    Scharr(g_srcImage, scharr_grad_x, g_srcImage.depth(), 1, 0);
    Scharr(g_srcImage, scharr_grad_y, g_srcImage.depth(), 0, 1);
    convertScaleAbs(scharr_grad_x, scharr_grad_x);
    convertScaleAbs(scharr_grad_y, scharr_grad_y);
    addWeighted(scharr_grad_x, 0.5, scharr_grad_y, 0.5, 0, scharr_dst);
    imshow("Scharr", scharr_dst);
     
     while(1){
     int c;
     c=waitKey(0);
     if((char)c=='q'||(char)c==27)
     break;
     }
    */
    
    /* Pyramide
    Affichage_Pyramide();
    Mat temp_image = g_srcImage;
    while(1){
        int c;
        c=waitKey(1);
        switch (c) {
            case 27:
                return 0;
                break;
                
            case 'z':
                resize(temp_image, temp_image, Size(), 2, 2);
                cout<<"Zoom in by Resize *2"<<endl;
                break;
                
            case 's':
                resize(temp_image, temp_image, Size(), 0.5, 0.5);
                cout<<"Zoom out by Resize /2"<<endl;
                break;
            
            case 'q':
                pyrUp(temp_image, temp_image, Size(temp_image.cols*2,temp_image.rows*2));
                cout<<"Zoom in by PyrUp *2"<<endl;
                break;
                
            case 'd':
                pyrDown(temp_image, temp_image, Size(temp_image.cols/2,temp_image.rows/2));
                cout<<"Zoom out by PyrDown /2"<<endl;
                break;
        }
        imshow("Zoom", temp_image);
    }
    */

    /* Hough transform
    // Hough Line
    namedWindow("HoughLines");
    createTrackbar("Value", "HoughLines", &g_nthreshold, 200, on_HoughLines);
    
    Canny(g_srcImage, g_tempImage, 200, 400);
    cvtColor(g_tempImage, g_dstImage, CV_GRAY2BGR);
    on_HoughLines(g_nthreshold, 0);
//    HoughLinesP(g_tempImage, g_lines, 1, CV_PI/180, 80, 50, 10);
//    imshow("HoughLines", g_dstImage);
    
    // Hough Cercle
    namedWindow("HoughCercles");
    Mat cercleImage = g_srcImage.clone();
    cvtColor(cercleImage, cercleImage, CV_BGR2GRAY);
    GaussianBlur(cercleImage, cercleImage, Size(3,3), 2,2);
    vector<Vec3f> circles;
    HoughCircles(cercleImage, circles, CV_HOUGH_GRADIENT, 1.5, 10);
    for(size_t i = 0; i < circles.size();i++){
        Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
        int rayon = cvRound(circles[i][2]);
        circle(cercleImage, center, 3, Scalar(0,255,0),-1);
        circle(cercleImage, center, rayon, Scalar(0,200,100), 3);
    }
    imshow("HoughCercles", cercleImage);

    while(1){
        int c;
        c=waitKey(0);
        if((char)c=='q'||(char)c==27)
            break;
    }
    */
    
    // 
    
    
    return 0;
}
