//
//  RemapFunction.cpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/29.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#include "RemapFunction.hpp"

void update_map(int key){
    for(int j = 0; j<g_dstImage.rows;j++){
        for(int i=0;i<g_dstImage.cols;i++){
            switch (key) {
                case 'a':
                    g_map_x.at<float>(j,i)=static_cast<float>(i);
                    g_map_y.at<float>(j,i)=static_cast<float>(g_dstImage.rows-j);
                    break;
                case 'z':
                    g_map_x.at<float>(j,i)=static_cast<float>(g_dstImage.cols-i);
                    g_map_y.at<float>(j,i)=static_cast<float>(j);
                    break;
                case 'e':
                    g_map_x.at<float>(j,i)=static_cast<float>(g_dstImage.cols-i);
                    g_map_y.at<float>(j,i)=static_cast<float>(g_dstImage.rows-j);
                    break;
                case 'r':
                    if(j>g_dstImage.rows*0.25 && j<g_dstImage.rows*0.75 && i>g_dstImage.cols*0.25 && i<g_dstImage.cols*0.75){
                        g_map_x.at<float>(j,i)=static_cast<float>(2*( i - g_dstImage.cols*0.25 ));
                        g_map_y.at<float>(j,i)=static_cast<float>(2*( j - g_dstImage.rows*0.25 ));
                    }
                    else{
                        g_map_x.at<float>(j,i)=static_cast<float>(0);
                        g_map_y.at<float>(j,i)=static_cast<float>(0);
                    }
                    break;
                case 't':
                        g_map_x.at<float>(j,i)=static_cast<float>(i/2 + 0.25*g_dstImage.cols);
                        g_map_y.at<float>(j,i)=static_cast<float>(j/2 + 0.25*g_dstImage.rows);
                    break;
                case 'y':
                    if(j>g_dstImage.rows*0.3 && j<g_dstImage.rows*0.7 && i>g_dstImage.cols*0.3 && i<g_dstImage.cols*0.7){
                        g_map_x.at<float>(j,i)=static_cast<float>(2.5*( i - g_dstImage.cols*0.3 ));
                        g_map_y.at<float>(j,i)=static_cast<float>(2.5*( j - g_dstImage.rows*0.3 ));
                    }
                    else{
                        g_map_x.at<float>(j,i)=static_cast<float>(0);
                        g_map_y.at<float>(j,i)=static_cast<float>(0);
                        break;
                    }
                case 'u':
                    g_map_x.at<float>(j,i)=static_cast<float>(i*0.4 + 0.3*g_dstImage.cols);
                    g_map_y.at<float>(j,i)=static_cast<float>(j*0.4 + 0.3*g_dstImage.rows);
                    break;
            }
        }
    }
    switch (key){
        case 'a':
            cout<<"水平翻转"<<endl;
            break;
        case 'z':
            cout<<"垂直翻转"<<endl;
            break;
        case 'e':
            cout<<"水平垂直翻转"<<endl;
            break;
        case 'r':
            cout<<"缩小2倍"<<endl;
            break;
        case 't':
            cout<<"放大2倍"<<endl;
            break;
        case 'y':
            cout<<"缩小3倍"<<endl;
            break;
        case 'u':
            cout<<"放大3倍"<<endl;
            break;
    }
}
