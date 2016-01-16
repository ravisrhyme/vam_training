/********************************************************************************************************
* File         :winner_takeall2.cpp                                                                     *
* Purpose      :To find salient region                                                                  *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/

/*****************************PreDefined*******************************************************/
#include<iostream>
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



Mat block; //to store current block of pixels
Scalar sum_of_intensity;//to store sum of intensities of each block

int saliency_width; //width of saliency map
int saliency_height; //height of saliency map
char decision='y';

void winner_takeall2()
{
    float great=0;
    int pixel_x,pixel_y;
    saliency_width=(saliency_map.cols);
    saliency_height=(saliency_map.rows);
    int i,j;
    int count1=0;

    int high,wide;//to keep condition in loop so that we get exact last block

    high=(saliency_height-BLOCK_SIZE);

    wide=(saliency_width-BLOCK_SIZE);

    do
    {
        for(i=0;i<=high;i+=shift_size)
        {
            for(j=0;j<=wide;j+=shift_size)
            {
                Rect roi(i,j,BLOCK_SIZE,BLOCK_SIZE);
                block=saliency_map(roi);
                sum_of_intensity=sum(block);

                //cout<<"intensities in "<<i<<"\t"<<j<<"\t"<<sum_of_intensity.val[0]<<endl;

                if(sum_of_intensity.val[0]>great)
                {
                    great=sum_of_intensity.val[0];
                    pixel_x=i;
                    pixel_y=j;

                }
            }
        }
        cout<<"pixel locations with greatest intensity are:"<<pixel_x<<" "<<pixel_y<<"\t"<<endl;
        cout<<"greatest intensity :"<<great<<endl;
        Point p1(pixel_x,pixel_y);
        Point p2(pixel_x+(BLOCK_SIZE-1),pixel_y+(BLOCK_SIZE-1));
        //Scalar color(255,255,255);
        rectangle(saliency_map,p1,p2,CV_RGB(255,255,255),1,8,0);
        rectangle(display,p1,p2,CV_RGB(255,0,0),1,8,0);

        if(count1==0)
        {
            waitKey(1000);
            imshow("salient most inhibition",saliency_map);
            waitKey(1000);
            extract_features(pixel_x,pixel_y);
        }

        else if(count1==1)
        {
            waitKey(1000);
            imshow("2nd most salient inhibition",saliency_map);
            waitKey(1000);
            extract_features(pixel_x,pixel_y);
        }

        else if(count1==2)
        {
            waitKey(1000);
            imshow("3 most salient inhibition",saliency_map);
            waitKey(1000);
            extract_features(pixel_x,pixel_y);
        }

        else if(count1==3)
        {
            waitKey(1000);
            imshow("4 most salient inhibition",saliency_map);
            waitKey(1000);
            extract_features(pixel_x,pixel_y);
        }
        else if(count1==4)
        {
            waitKey(1000);
            imshow("5 most salient inhibition",saliency_map);
            waitKey(1000);
            extract_features(pixel_x,pixel_y);
        }
        else if(count1==5)
        {
            waitKey(1000);
            imshow("6th most salient inhibition",saliency_map);
            waitKey(1000);
            extract_features(pixel_x,pixel_y);
        }
        cout<<"do u waana proceed to next salient region(y or n):";
        cin>>decision;
        cout<<"the decision is:"<<decision<<endl;

         if(decision=='y')
        {
            count1++;
            //cout<<"pixels carried are :"<<pixel_x<<"\t"<<pixel_y<<endl;

            for(i=pixel_y;i<(pixel_y+BLOCK_SIZE);i++)//(pixel_x+BLOCK_SIZE)
            {
                for(j=pixel_x;j<(pixel_x+BLOCK_SIZE);j++)
                {
                    //cout<<i<<"\t"<<j<<"\t"<<"pixels are made zero"<<endl;

                     saliency_map.at<float>(i,j)=0;
                     Scalar abc=saliency_map.at<float>(i,j);
                    //cout<<"modified pixel values at :"<<i<<"\t"<<j<<" "<<abc.val[0]<<endl;

                }
            }
                //imshow("testing",saliency_map);
                /*Rect roi(100,220,BLOCK_SIZE,BLOCK_SIZE);
                Mat block1;
                Scalar sum_of_intensity1;
                block1=saliency_map(roi);
                sum_of_intensity1=sum(block1);
                cout<<"intensity of inhibited block is "<<pixel_x<<"\t"<<pixel_y<<"\t"<<sum_of_intensity1.val[0]<<endl;
                */great=0;
                pixel_x=0;
                pixel_y=0;
        }

    }while(decision=='y');
     imshow("total-maps",display);
}
