//
//  HarrisCorner.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/28.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include "HarrisCorner.hpp"

void on_HarrisCorner(int, void*){
    Mat src = g_srcImage.clone();
    Mat dst, gray, norm, scaled;
    cvtColor(src, gray, CV_BGR2GRAY);
    cornerHarris(gray, dst, 4, 3, 0.04);
    normalize(dst, norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(norm, scaled);
    for(int j = 0; j < norm.rows; j++){
        for(int i = 0; i < norm.cols; i++){
            if((int)norm.at<float>(j,i)>g_nHarrisThresh+80){
                circle(src, Point(i,j), 5, Scalar(10,10,255), 2);
                circle(scaled, Point(i,j), 5, Scalar(0,0,255), 2);
            }
        }
    }
    imshow("WIN1", src);
    imshow("WIN2", scaled);
}
