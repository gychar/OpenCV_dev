//
//  Floodfill.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/28.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include "Floodfill.hpp"

void Affichage_Floodfill(){
    cout<<"Click to floodfill"<<endl<<"Q to quit"<<endl;
    cout<<"[a] to switch color/gray"<<endl;
    cout<<"[z] to show/hide mask"<<endl;
    cout<<"[e] to reset image"<<endl;
    cout<<"[r] to use null-range floodfill"<<endl;
    cout<<"[t] to use fixed-range floodfill"<<endl;
    cout<<"[y] to use floated-range floodfill"<<endl;
    cout<<"[u] to use 4-connected mode"<<endl;
    cout<<"[i] to use 8-connected mode"<<endl;
}

void onMouse(int event, int x, int y, int, void*){
    if(event!= CV_EVENT_LBUTTONDOWN)
        return;
    Point seed = Point(x,y);
    int LowDiff = g_nFillMode == 0 ? 0 : g_nLowDiff;
    int UpDiff = g_nFillMode == 0 ? 0 : g_nUpDiff;
    int flags = g_nConnectivity + (g_nNewMaskVal << 8) + (g_nFillMode = 1 ? CV_FLOODFILL_FIXED_RANGE : 0 );
    
    int b = (unsigned)theRNG()&255;
    int g = (unsigned)theRNG()&255;
    int r = (unsigned)theRNG()&255;

    Rect ccomp;
    
    Scalar newVal = g_bIsColor ? Scalar(b,g,r) : Scalar(r*0.299 + g*0.587 + b*0.114);
    
    Mat dst = g_bIsColor ? g_dstImage : g_grayImage;
    int area;
    
    if(g_bUseMask){
        threshold(g_maskImage, g_maskImage, 1, 128, CV_THRESH_BINARY);
        area = floodFill(dst, g_maskImage, seed, newVal, &ccomp, Scalar(LowDiff, LowDiff, LowDiff), Scalar(UpDiff, UpDiff, UpDiff), flags);
        imshow("mask", g_maskImage);
    }
    else{
        area = floodFill(dst, seed, newVal, &ccomp, Scalar(LowDiff, LowDiff, LowDiff), Scalar(UpDiff, UpDiff, UpDiff), flags);
    }
    imshow("Result", dst);
    cout<<area<<" pixels has been modified."<<endl;
    
}











