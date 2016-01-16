/********************************************************************************************************
* File:orientation_feature.cpp
* Purpose:To find orientation(0,45,90,135) and feature maps and conspicuity map
* Language Used:C++ bindings
* Author(s):RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/
 /*****************************PreDefined*******************************************************/
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
#include<math.h>
/*****************************User Defined******************************************************/
#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"
using namespace std;
using namespace cv;



 int orient_loop;
 int kernel_size=21;
 int pos_sigma= 5;
 int pos_lm = 50;
 int pos_th[4] ={0,45,90,135};
 int pos_psi = 90;
 Mat grayscale_img;
 Mat convol_src;
 Mat dest;
 Mat final_dest[4];
 Mat temp_orient;


 /******************************To store pyramids******************************************/
   vector<Mat> orient0_pyr,orient45_pyr,orient90_pyr,orient135_pyr;

 //to store center surroung differences
   Mat orient0_cent,orient45_cent,orient90_cent,orient135_cent;//centers for each orientation
   Mat orient0_srnd1,orient0_srnd2;
   Mat orient45_srnd1,orient45_srnd2;
   Mat orient90_srnd1,orient90_srnd2;
   Mat orient135_srnd1,orient135_srnd2;

  //to store center surroung differences
    Mat orient0_fmap1,orient0_fmap2;
    Mat orient45_fmap1,orient45_fmap2;
    Mat orient90_fmap1,orient90_fmap2;
    Mat orient135_fmap1,orient135_fmap2;



 //to store conspicuity map

   Mat orient0_fmapavg;
   Mat orient45_fmapavg;
   Mat orient90_fmapavg;
   Mat orient135_fmapavg;
   Mat orient_conspicuitymap;

Mat mkKernel(int ks, double sig, double th, double lm, double ps)
 {

     int hks = (ks-1)/2;
     double theta = th*CV_PI/180;
     double psi = ps*CV_PI/180;
     double del = 2.0/(ks-1);
     double lmbd = lm;
     double sigma = sig/ks;
     double x_theta;
     double y_theta;
     Mat kernel(ks,ks, CV_32F);

     for (int y=-hks; y<=hks; y++)
     {
	 for (int x=-hks; x<=hks; x++)
	 {
	     x_theta = x*del*cos(theta)+y*del*sin(theta);
	     y_theta = -x*del*sin(theta)+y*del*cos(theta);
	     kernel.at<float>(hks+y,hks+x) = (float)exp(-0.5*(pow(x_theta,2)+pow(y_theta,2))/pow(sigma,2))* cos(2*CV_PI*x_theta/lmbd + psi);
	 }
     }
     return kernel;
 }

 void process(int theta_temp)
 {
     double sig = pos_sigma;
     double lm = 0.5+pos_lm/100.0;
     double th = theta_temp;
     double ps = pos_psi;

     Mat kernel = mkKernel(kernel_size, sig, th, lm, ps);

     filter2D(convol_src,dest, CV_32F, kernel); //convolution of grayscale image with kernel and stored in dest

     switch(orient_loop)
     {
	 case 0:
	     //imshow("Process window_0", dest);


	     pow(dest, 2.0, final_dest[orient_loop]);

	     //imshow("Mag_0", final_dest[orient_loop]);
	     break;

	 case 1:
	     //imshow("Process window_45", dest);


	     pow(dest, 2.0, final_dest[orient_loop]);

	     //imshow("Mag_45", final_dest[orient_loop]);
	     break;

	 case 2:
	     //imshow("Process window_90", dest);


	     pow(dest, 2.0, final_dest[orient_loop]);

	     //imshow("Mag_90", final_dest[orient_loop]);
	     break;

	 case 3:
	     //imshow("Process window_135", dest);


	     pow(dest, 2.0, final_dest[orient_loop]);

	     //imshow("Mag_135", final_dest[orient_loop]);
	     break;
     }


 }
 void find_pyramids()
 {
     // building pyramids

     buildPyramid(final_dest[0],orient0_pyr,3);
     buildPyramid(final_dest[1],orient45_pyr,3);
     buildPyramid(final_dest[2],orient90_pyr,3);
     buildPyramid(final_dest[3],orient135_pyr,3);


 }
 //0 degree maps
 void find_centersurround_0()
 {
     Mat temp_orient0_fmap1,temp_orient0_fmap2;
     orient0_cent=orient0_pyr[1];

     pyrUp(orient0_pyr[2],orient0_srnd1,orient0_cent.size());

     pyrUp(orient0_pyr[3],temp_orient,orient0_pyr[2].size());

     pyrUp(temp_orient,orient0_srnd2,orient0_cent.size());

     absdiff(orient0_cent,orient0_srnd1,temp_orient0_fmap1);
     absdiff(orient0_cent,orient0_srnd2,temp_orient0_fmap2);

     normalize(temp_orient0_fmap1,orient0_fmap1,255,0,NORM_MINMAX,-1);
     normalize(temp_orient0_fmap2,orient0_fmap2,255,0,NORM_MINMAX,-1);
     //imshow("orient0_fmap1",orient0_fmap1);
     //imshow("orient0_fmap2",orient0_fmap2);


     //imshow("normalized",orient0_fmap1);

     orient0_fmapavg=(orient0_fmap1+orient0_fmap2)/2;


     //imshow("average0",orient0_fmapavg);

 }
 //45 degree map
 void find_centersurround_45()
 {
     Mat temp_orient45_fmap1,temp_orient45_fmap2;

    orient45_cent=orient45_pyr[1];

     pyrUp(orient45_pyr[2],orient45_srnd1,orient45_cent.size());

     pyrUp(orient45_pyr[3],temp_orient,orient45_pyr[2].size());

     pyrUp(temp_orient,orient45_srnd2,orient45_cent.size());

     absdiff(orient45_cent,orient45_srnd1,temp_orient45_fmap1);
     absdiff(orient45_cent,orient45_srnd2,temp_orient45_fmap2);

     normalize(temp_orient45_fmap1,orient45_fmap1,255,0,NORM_MINMAX,-1);
     normalize(temp_orient45_fmap2,orient45_fmap2,255,0,NORM_MINMAX,-1);


     //imshow("orient45_fmap1",orient45_fmap1);
     //imshow("orient45_fmap2",orient45_fmap2);

     orient45_fmapavg=(orient45_fmap1+orient45_fmap2)/2;

     //imshow("average45",orient45_fmapavg);


 }
 //90 degree map
 void find_centersurround_90()
 {
     Mat temp_orient90_fmap1,temp_orient90_fmap2;
     orient90_cent=orient90_pyr[1];

     pyrUp(orient90_pyr[2],orient90_srnd1,orient90_cent.size());

     pyrUp(orient90_pyr[3],temp_orient,orient90_pyr[2].size());

     pyrUp(temp_orient,orient90_srnd2,orient90_cent.size());

     absdiff(orient90_cent,orient90_srnd1,temp_orient90_fmap1);
     absdiff(orient90_cent,orient90_srnd2,temp_orient90_fmap2);

     normalize(temp_orient90_fmap1,orient90_fmap1,255,0,NORM_MINMAX,-1);
     normalize(temp_orient90_fmap2,orient90_fmap2,255,0,NORM_MINMAX,-1);


     //imshow("orient90_fmap1",orient90_fmap1);
     //imshow("orient90_fmap2",orient90_fmap2);


     orient90_fmapavg=(orient90_fmap1+orient90_fmap2)/2;

     //imshow("average90",orient90_fmapavg);

 }
 //135 degree maps
 void find_centersurround_135()
 {
     Mat temp_orient135_fmap1,temp_orient135_fmap2;

     orient135_cent=orient135_pyr[1];
     pyrUp(orient135_pyr[2],orient135_srnd1,orient135_cent.size());

     pyrUp(orient135_pyr[3],temp_orient,orient135_pyr[2].size());

     pyrUp(temp_orient,orient135_srnd2,orient135_cent.size());

     absdiff(orient135_cent,orient135_srnd1,temp_orient135_fmap1);
     absdiff(orient135_cent,orient135_srnd2,temp_orient135_fmap2);

     normalize(temp_orient135_fmap1,orient135_fmap1,255,0,NORM_MINMAX,-1);
     normalize(temp_orient135_fmap2,orient135_fmap2,255,0,NORM_MINMAX,-1);


     //imshow("orient135_fmap1",orient135_fmap1);
     //imshow("orient135_fmap2",orient135_fmap2);

     orient135_fmapavg=(orient135_fmap1+orient135_fmap2)/2;


     //imshow("average135",orient135_fmapavg);


 }
 void find_conspicuity()
 {
     Mat temp_orient_conspicuitymap;
     temp_orient_conspicuitymap=(orient0_fmapavg+orient45_fmapavg+orient90_fmapavg+orient135_fmapavg)/4;

     normalize(temp_orient_conspicuitymap,orient_conspicuitymap,255,0,NORM_MINMAX,-1);



     //imshow("orientation consmap",temp_orient_conspicuitymap);
     //imshow("normalised consmap",orient_conspicuitymap);

 }

void orientation_feature()
{
    cvtColor(reduced_img, grayscale_img, CV_BGR2GRAY);

    Scalar intensity,intensity1;

    double min,max;
    minMaxLoc(grayscale_img,&min,&max);
    cout<<"min is :"<<min<<endl;
    cout<<"max is :"<<max<<endl;

    grayscale_img.convertTo(convol_src, CV_32F,1.0/max,0);

    if (!kernel_size%2)
     {
	 kernel_size+=1;
     }


    //function find orientation maps

     for(orient_loop=0;orient_loop<4;orient_loop++)
     {

	 process(pos_th[orient_loop]);

     }

    find_pyramids();
    find_centersurround_0();
    find_centersurround_45();
    find_centersurround_90();
    find_centersurround_135();
    find_conspicuity();

}
