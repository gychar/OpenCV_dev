//
//  Morphology.hpp
//  OpenCV_dev
//
//  Created by CHAR on 2018/1/26.
//  Copyright © 2018年 CHAR. All rights reserved.
//

#ifndef Morphology_hpp
#define Morphology_hpp

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "global.hpp"

using namespace std;
using namespace cv;

extern void Affichage();
extern void on_OpenClose(int, void*);
extern void on_TopBlackHat(int, void*);
extern void on_ErodeDilate(int, void*);
extern void on_SwitchOpenClose(int, void*);
extern void on_SwitchErodeDilate(int, void*);
extern void on_SwitchTopBlackHat(int, void*);
extern void OpenClose_process();
extern void ErodeDilate_process();
extern void TopBlackHat_process();

#endif /* Morphology_hpp */
