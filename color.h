/********************************************************************************************************
* File name    :color.h
* Purpose      :To declare variables and functions used by color_feature.cpp
* Language Used:C++ bindings
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include<cv.h>
using namespace cv;


    extern Mat rgb_channels[3];// 3 MATRICES STORING SEPARATED R,G,B CHANNEL EACH
    extern Mat r,g,b,y;    //



//TO FIND CENTER SURROUND DIFF RG AND BY

extern vector<Mat> cr_pyramid,cg_pyramid,cb_pyramid,cy_pyramid;
extern Mat temp;
extern Mat cr_cent;
extern Mat cr_srnd1,cr_srnd2;
extern Mat cg_cent;
extern Mat cg_srnd1,cg_srnd2;
extern Mat crg_fmap1,crg_fmap2,crg_fmapavg;
extern Mat cb_cent;
extern Mat cb_srnd1,cb_srnd2;
extern Mat cy_cent;
extern Mat cy_srnd1,cy_srnd2;
extern Mat cby_fmap1,cby_fmap2,cby_fmapavg;




//TO FIND CONSPICUITY MAPS
    extern Mat color_consmap;

    void color_feature();


#endif // COLOR_H_INCLUDED
