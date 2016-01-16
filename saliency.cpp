/********************************************************************************************************
* File         :saliency.cpp
* Purpose      :To find saliency map
* Language Used:C++ bindings
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar
********************************************************************************************************/
/*****************************PreDefined*******************************************************/
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>

/*****************************User Defined******************************************************/
#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"

using namespace std;
using namespace cv;

Mat saliency_map;

void find_saliency()
{
    int i,j;
    saliency_map=(color_consmap+intensity_consmap+orient_conspicuitymap)/3;
    //imshow("saliency map np",saliency_map);
    for(i=0;i<9;i++)
     {
        for(j=110;j<256;j++)
        {
            saliency_map.at<float>(i,j)=0;
        }
     }
     for(i=0;i<14;i++)
     {
        for(j=230;j<256;j++)
        {
            saliency_map.at<float>(i,j)=0;
        }
     }
     imshow("saliency map",saliency_map);

}
