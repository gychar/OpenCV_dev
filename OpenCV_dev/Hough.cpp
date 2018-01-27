//
//  Hough.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/27.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include "Hough.hpp"

void on_HoughLines(int, void*){
    Mat dst = g_dstImage.clone();
    Mat temp = g_tempImage.clone();
    
    vector<Vec4i> mylines;
    HoughLinesP(temp, mylines, 1, CV_PI/180, g_nthreshold+1, 50, 10);
    
    for(size_t i=0; i<mylines.size();i++){
        Vec4i l=mylines[i];
        line(dst, Point(l[0],l[1]), Point(l[2],l[3]), Scalar(18, 0, 215), 1, CV_AA);
    }
    imshow("HoughLines", dst);
    
}
