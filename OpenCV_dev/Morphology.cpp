//
//  Morphology.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/26.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include "Morphology.hpp"
#include "global.hpp"

void Affichage(){
    cout<<"ESC/Q to exit"<<endl<<"R for Rectangle element"<<endl<<"E for Elliptic element"<<endl<<"C for Cross-shaped element"<<endl;
}

void on_OpenClose(int, void*){
    OpenClose_process();
}

void on_TopBlackHat(int, void*){
    TopBlackHat_process();
}

void on_ErodeDilate(int, void*){
    ErodeDilate_process();
}

void on_SwitchOpenClose(int, void*){
    OpenClose_process();
}

void on_SwitchErodeDilate(int, void*){
    ErodeDilate_process();
}

void on_SwitchTopBlackHat(int, void*){
    TopBlackHat_process();
}

void ErodeDilate_process(){
    Mat element=getStructuringElement(g_nElementType, Size(2*g_nErodeDilate+1,2*g_nErodeDilate+1), Point(g_nErodeDilate,g_nErodeDilate));
    if(g_SwitchErodeDilate==0){
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_ERODE, element);
    }
    else{
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_DILATE, element);
    }
    imshow("Erode&Dilate", g_dstImage);
}

void OpenClose_process(){
    Mat element=getStructuringElement(g_nElementType, Size(2*g_nOpenClose+1,2*g_nOpenClose+1), Point(g_nOpenClose,g_nOpenClose));
    if(g_SwitchOpenClose==0){
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_OPEN, element);
    }
    else{
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_CLOSE, element);
    }
    imshow("Open&Close", g_dstImage);
}

void TopBlackHat_process(){
    Mat element=getStructuringElement(g_nElementType, Size(2*g_nTopBlackHat+1,2*g_nTopBlackHat+1), Point(g_nTopBlackHat,g_nTopBlackHat));
    if(g_SwitchTopBlackHat==0){
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_TOPHAT, element);
    }
    else{
        morphologyEx(g_srcImage, g_dstImage, CV_MOP_BLACKHAT, element);
    }
    imshow("TopHat&BlackHat", g_dstImage);
}

