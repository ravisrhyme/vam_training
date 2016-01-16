/********************************************************************************************************
* File:Color_feature.cpp
* Purpose:To find R,G,B components,pyramids and color featuremaps[RG,BY] and color conspicuitymap
* Language Used:C++ bindings
* Author(s):RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/

/*****************************PreDefined*******************************************************/
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
#include<math.h>
using namespace std;
using namespace cv;

/*****************************User Defined******************************************************/
#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"

/******************************************************
 *                Global Variables                    *
 *****************************************************/
Mat r,g,b,y;//to store r,g,b,y components
vector<Mat> cr_pyramid,cg_pyramid,cb_pyramid,cy_pyramid;//to store pyramids

Mat cr_cent;//to store r-center
Mat cr_srnd1,cr_srnd2;//surrounds
Mat cg_cent;//to store g-center
Mat cg_srnd1,cg_srnd2;//g-surround
Mat crg_fmap1,crg_fmap2,crg_fmapavg;
Mat cb_cent;
Mat cb_srnd1,cb_srnd2;
Mat cy_cent;
Mat cy_srnd1,cy_srnd2;
Mat cby_fmap1,cby_fmap2,cby_fmapavg;
Mat color_consmap;

void color_feature()
{


      Mat temp;
      double min,max;//local variable to find min and max in each map
      Mat temp_crg_fmap1,temp_crg_fmap2;//to store feature maps temporarily before conversion to 0-1 scale.
      Mat temp_cby_fmap1,temp_cby_fmap2;//to store feature maps temporarily before conversion to 0-1 scale
	 r=((rgb_channels[0]-(rgb_channels[1]+rgb_channels[2]))/2);

     g=((rgb_channels[1]-(rgb_channels[0]+rgb_channels[2]))/2);

     b=((rgb_channels[2]-(rgb_channels[0]+rgb_channels[1]))/2);

     y=rgb_channels[0]+rgb_channels[1]-2*(abs(rgb_channels[0]-rgb_channels[1])+rgb_channels[2]);

/***********************************Pyramid construction*****************************************/
        buildPyramid(r,cr_pyramid,3);
        buildPyramid(g,cg_pyramid,3);
        buildPyramid(b,cb_pyramid,3);
        buildPyramid(y,cy_pyramid,3);



/*** Upscaling pyramids for Red-component pyramids and fixing center and surround*******/
	      cr_cent=cr_pyramid[1];
	      pyrUp(cr_pyramid[2],cr_srnd1,cr_cent.size());
	      pyrUp(cr_pyramid[3],temp,cr_pyramid[2].size());
	      pyrUp(temp,cr_srnd2,cr_cent.size());


/****Upscaling pyramids for Green-component pyramids and fixing center and surround*******/

	      cg_cent=cg_pyramid[1];

	      pyrUp(cg_pyramid[2],cg_srnd1,cg_cent.size());
	      pyrUp(cg_pyramid[3],temp,cg_pyramid[2].size());
	      pyrUp(temp,cg_srnd2,cg_cent.size());

/**********************CENTER SURROUND DIFF FR RG***************************************/

	      absdiff((cr_cent-cg_cent),(cg_srnd1-cr_srnd1),temp_crg_fmap1);
	      absdiff((cr_cent-cg_cent),(cg_srnd2-cr_srnd2),temp_crg_fmap2);


	     minMaxLoc(temp_crg_fmap1,&min,&max);
	     temp_crg_fmap1.convertTo(crg_fmap1, CV_32F,1.0/max,0);


	    minMaxLoc(temp_crg_fmap2,&min,&max);

	    temp_crg_fmap2.convertTo(crg_fmap2, CV_32F,1.0/max,0);
        crg_fmapavg=(crg_fmap1+crg_fmap2)/2;




/****Upscaling pyramids for Blue-component pyramids and fixing center and surround*******/


          cb_cent=cb_pyramid[1];

	      pyrUp(cb_pyramid[2],cb_srnd1,cb_cent.size());
	      pyrUp(cb_pyramid[3],temp,cb_pyramid[2].size());
	      pyrUp(temp,cb_srnd2,cb_cent.size());


/****Upscaling pyramids for yellow-component pyramids and fixing center and surround*******/


	      cy_cent=cy_pyramid[1];

	      pyrUp(cy_pyramid[2],cy_srnd1,cy_cent.size());
	      pyrUp(cy_pyramid[3],temp,cy_pyramid[2].size());
	      pyrUp(temp,cy_srnd2,cy_cent.size());


/**********************CENTER SURROUND DIFF FR RG***************************************/


	      absdiff((cb_cent-cy_cent),(cy_srnd1-cb_srnd1),temp_cby_fmap1);
	      absdiff((cb_cent-cy_cent),(cy_srnd2-cb_srnd2),temp_cby_fmap2);

	      minMaxLoc(temp_cby_fmap1,&min,&max);
	      temp_cby_fmap1.convertTo(cby_fmap1, CV_32F,1.0/max,0);

	      minMaxLoc(temp_cby_fmap2,&min,&max);
	      temp_cby_fmap2.convertTo(cby_fmap2, CV_32F,1.0/max,0);


          cby_fmapavg=(cby_fmap1+cby_fmap2)/2;

          color_consmap=(crg_fmapavg+cby_fmapavg)/2;

          //imshow("color_conspicuity",color_consmap);
}

