#ifndef EXTRACT_FEATURES_H_INCLUDED
#define EXTRACT_FEATURES_H_INCLUDED

#include<iostream>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>

#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"

using namespace std;
using namespace cv;

void extract_features(int pixel_x,int pixel_y);
void calculate_sum(Rect roi,Mat img,ofstream &fout);

#endif // EXTRACT_FEATURES_H_INCLUDED
