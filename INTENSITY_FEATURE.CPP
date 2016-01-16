/********************************************************************************************************
* File         :Intensity_feature.cpp
* Purpose      :To find IntensityImage pyramids and Intensityfeaturemaps and Intensity conspicuitymap
* Language Used:C++ bindings
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/

/*****************************PreDefined****************************/
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>

/*****************************User Defined**************************/
#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"
using namespace std;
using namespace cv;
/******************************************************
 *                Global Variables                    *
 *****************************************************/

     Mat intensity_img; //to store intensity image
     vector<Mat> intensity_pyramid; //to store pyramids
     Mat intensity_cent;//to store  center
     Mat intensity_srnd1,intensity_srnd2;//to store surrounds
     Mat intensity_fmap1,intensity_fmap2;//to store feature maps
     Mat intensity_fmapavg;//
     Mat intensity_consmap;//to store consmap


void intensity_feature()
{
        Mat temp;
        Mat temp_intensity_fmap1,temp_intensity_fmap2;
        double min,max;
	    intensity_img=((rgb_channels[0]+rgb_channels[1]+rgb_channels[2])/3);


	    //imshow("intensity",intensity_img);

/****************************Intensity pyramids**********************************************/

        buildPyramid(intensity_img,intensity_pyramid,3);

        /*imshow("int_pyr_src",I_pyramid[0]);
		imshow("int_pyr1",I_pyramid[1]);
		imshow("int_pyr2",I_pyramid[2]);
		imshow("int_pyr3",I_pyramid[3]);*/

 /*********************FEATURE MAPS CONSTRUCTION******************************************/

        intensity_cent=intensity_pyramid[1];

	    pyrUp(intensity_pyramid[2],intensity_srnd1,intensity_cent.size());
	    pyrUp(intensity_pyramid[3],temp,intensity_pyramid[2].size());
	    pyrUp(temp,intensity_srnd2,intensity_cent.size());



	    /*imshow("I_surround1",I_srnd1);
        imshow("I_surround2",I_srnd2);*/
/******************************Center-surround Differences************************************/

	    absdiff(intensity_cent,intensity_srnd1,temp_intensity_fmap1);
	    absdiff(intensity_cent,intensity_srnd2,temp_intensity_fmap2);

	    minMaxLoc(temp_intensity_fmap1,&min,&max);
	    temp_intensity_fmap1.convertTo(intensity_fmap1,CV_32F,1.0/max,0);


	    minMaxLoc(temp_intensity_fmap2,&min,&max);
	    temp_intensity_fmap2.convertTo(intensity_fmap2,CV_32F,1.0/max,0);

        //imshow("conv fmap1",intensity_fmap1);
        //imshow("conv fmap2",intensity_fmap2);

        intensity_consmap=(intensity_fmap1+intensity_fmap2)/2;

        //imshow("intensity_conspicuity",intensity_consmap);

}
