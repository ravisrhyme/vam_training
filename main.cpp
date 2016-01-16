/********************************************************************************************************
* File         :Main() pgm file for project                                                             *
* Purpose      :To Start the execution of project by making use of all other files.                     *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
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
#include "winner_takeall.h"
using namespace std;
using namespace cv;

//global variables

Mat original_img;   //to store original image
Mat filtered_img;   //to store filtered image
Mat reduced_img;    //to store reduced image
Mat display;
Mat rgb_channels[3];//to store each channel of image in one matrix

int main()
{

    original_img=imread("/home/ravikiran/Documents/testcodes/signboard/training images bikes_001-010/bike2.png",-1);
    //imshow("original",original_img);

    //filtering
    GaussianBlur(original_img,filtered_img,Size(3,3),0.5,0.5);
    //imshow("filtered",filtered_img);

    resize(filtered_img,reduced_img,Size(512,512),0,0,INTER_LINEAR);
    resize(filtered_img,display,Size(256,256),0,0,INTER_LINEAR);

	//imshow("resized",reduced_img);

	split(reduced_img,rgb_channels);//splitting to get each channel in RGB seperately

    color_feature();// for processign with respect to color features
    intensity_feature();//for processign with respect to color feature
    orientation_feature();//for processign with respect to orientation feature
    find_saliency(); //to find saliency map
    winner_takeall2();

    waitKey(0);
    return 0;
}
