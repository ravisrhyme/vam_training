/********************************************************************************************************
* File         :saliency.h                                                                              *
* Purpose      :To declare variables and functions used by saliency.cpp                                 *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/

#ifndef SALIENCY_H_INCLUDED
#define SALIENCY_H_INCLUDED

#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
using namespace cv;

#include"intensity.h"
#include"color.h"
#include"orientation.h"

extern Mat saliency_map;//to store saliency map

void find_saliency();

#endif // SALIENCY_H_INCLUDED
