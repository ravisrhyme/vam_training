/********************************************************************************************************
* File         :orientation.h
* Purpose      :To declare variables and functions used by orientation_feature.cpp
* Language Used:C++ bindings
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/

#ifndef ORIENTATION_H_INCLUDED
#define ORIENTATION_H_INCLUDED

#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
using namespace cv;

 extern Mat reduced_img; //declared again in main() file

 extern int orient_loop;
 extern int kernel_size;
 extern int pos_sigma;
 extern int pos_lm;
 extern int pos_th[4];
 extern int pos_psi;
 extern Mat grayscale_img;
 extern Mat convol_src;//to store image to be convoluted.
 extern Mat dest;
 extern Mat final_dest[4];

 //to store pyramids
  extern vector<Mat> orient0_pyr,orient45_pyr,orient90_pyr,orient135_pyr;

 //to store center surroung differences
  extern Mat orient0_cent,orient45_cent,orient90_cent,orient135_cent;//centers for each orientation
  extern Mat orient0_srnd1,orient0_srnd2;
  extern Mat orient45_srnd1,orient45_srnd2;
  extern Mat orient90_srnd1,orient90_srnd2;
  extern Mat orient135_srnd1,orient135_srnd2;

  //to store center surroung differences
   extern Mat orient0_fmap1,orient0_fmap2;
   extern Mat orient45_fmap1,orient45_fmap2;
   extern Mat orient90_fmap1,orient90_fmap2;
   extern Mat orient135_fmap1,orient135_fmap2;

 //to store conspicuity map
   extern Mat orient0_fmapavg;
   extern Mat orient45_fmapavg;
   extern Mat orient90_fmapavg;
   extern Mat orient135_fmapavg;

  extern Mat orient_conspicuitymap;



 void orientation_feature();

 Mat mkKernel(int ks, double sig, double th, double lm, double ps);//to make kernel to convolute in image
 void process(int theta_temp);
 void find_centersurround_0();
 void find_centersurround_45();
 void find_centersurround_90();
 void find_centersurround_135();
 void find_conspicuity();

#endif // ORIENTATION_H_INCLUDED
