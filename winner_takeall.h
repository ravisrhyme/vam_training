/********************************************************************************************************
* File         :winner_takeall.h
* Purpose      :To declare variables and functions used by winner_takeall.cpp
* Language Used:C++ bindings
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/
#ifndef WINNER_TAKEALL_H_INCLUDED
#define WINNER_TAKEALL_H_INCLUDED

#include<iostream>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>

#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"
#include "extract_features.h"
using namespace std;
using namespace cv;

#define BLOCK_SIZE 32 //size of block is 64*64
#define shift_size 10 //each time moves by 10 pixels either horizontally or vertically

extern Mat block;//to store each block of size 32*32
extern Mat display;

extern Scalar sum_of_intensity;//to store sum of intensties in each block

void winner_takeall();//to implement
void winner_takeall2();

#endif // WINNER_TAKEALL_H_INCLUDED
