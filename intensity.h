/********************************************************************************************************
* File         :Intensity.h
* Purpose      :To declare variables and functions used by Intensity_feature.cpp
* Language Used:C++ bindings
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/

#ifndef INTENSITY_H_INCLUDED
#define INTENSITY_H_INCLUDED

    #include<cv.h>
    #include<highgui.h>
    #include<cxcore.h>

    using namespace cv;

     extern Mat intensity_img; // INTENSITY INFORMATION OF ORIGINAL IMAGE
//TO FIND CENTER SURROUND DIFF FOR INTENSITY
    extern vector<Mat> intensity_pyramid;
    extern Mat intensity_cent;
    extern Mat intensity_srnd1,intensity_srnd2;
    extern Mat intensity_fmap1,intensity_fmap2;


    extern Mat intensity_consmap; //TO store CONSPICUITY MAPS

    void intensity_feature();

#endif // INTENSITY_H_INCLUDED
