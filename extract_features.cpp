/********************************************************************************************************
* File         :extract_features.cpp                                                                    *
* Purpose      :To extract features(sum of intensities)and write it into a file                         *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/

/*****************************PreDefined*******************************************************/
#include<iostream>
#include<fstream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>

using namespace std;
using namespace cv;

/*****************************User Defined******************************************************/
#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"
#include "winner_takeall.h"
#include "extract_features.h"


bool obj_class;

Mat block_sum;


void calculate_sum(Rect roi,Mat img,ofstream &fout)
{
    block_sum=img(roi);
    sum_of_intensity=sum(block_sum);
    fout<<sum_of_intensity.val[0]<<',';
}
void extract_features(int pixel_x,int pixel_y)
{
    //cout<<pixel_x<<"\t"<<pixel_y<<endl;
    ofstream fout("features.arff",ios::binary|ios::app);

    Rect roi(pixel_x,pixel_y,BLOCK_SIZE,BLOCK_SIZE);


    calculate_sum(roi,crg_fmap1,fout);
    calculate_sum(roi,crg_fmap2,fout);
    calculate_sum(roi,cby_fmap1,fout);
    calculate_sum(roi,cby_fmap2,fout);


    calculate_sum(roi,intensity_fmap1,fout);
    calculate_sum(roi,intensity_fmap2,fout);


    calculate_sum(roi,orient0_fmap1,fout);
    calculate_sum(roi,orient0_fmap2,fout);
    calculate_sum(roi,orient45_fmap1,fout);
    calculate_sum(roi,orient45_fmap2,fout);
    calculate_sum(roi,orient90_fmap1,fout);
    calculate_sum(roi,orient90_fmap2,fout);
    calculate_sum(roi,orient135_fmap1,fout);
    calculate_sum(roi,orient135_fmap2,fout);

    calculate_sum(roi,color_consmap,fout);
    calculate_sum(roi,intensity_consmap,fout);
    calculate_sum(roi,orient_conspicuitymap,fout);

    calculate_sum(roi,saliency_map,fout);

    cout<<"enter the class(0 for non signboard and 1 for signboard) :";
    cin>>obj_class;

    fout<<obj_class<<endl;
    fout.close();

    //fout<<sum_of_intensity.val[0]<<',';
}
