/********************************************************************************************************
* File         :winner_takeall.cpp                                                                      *
* Purpose      :To find salient region                                                                  *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/

/*****************************PreDefined*******************************************************/
/*
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>

using namespace std;
using namespace cv;

/*****************************User Defined******************************************************/
/*
#include "color.h"
#include "intensity.h"
#include "orientation.h"
#include "saliency.h"
#include "winner_takeall.h"


#define BLOCK_SIZE 32 //size of block is 64*64
#define shift_size 10 //each time moves by 10 pixels either horizontally or vertically

Mat block; //to store current block of pixels
Scalar sum_of_intensity;//to store sum of intensities of each block

int saliency_width; //width of saliency map
int saliency_height; //height of saliency map


float test;
int pos_x,pos_y;

void winner_takeall()
{
    test=0;
    int i,j;
    int hor=0;
    int ver=0;
    float great=0;
    int pixel_x,pixel_y;
    char decision='y';

    int count=0;
    int count1=0;

    saliency_width=(saliency_map.cols);
    saliency_height=(saliency_map.rows);

    int high,wide;//to keep condition in loop so that we get exact last block

    high=(saliency_height-BLOCK_SIZE);

    wide=(saliency_width-BLOCK_SIZE);

    for(i=0;i<=high;i+=shift_size)
    {
        for(j=0;j<=wide;j+=shift_size)
        {
            count++;
        }
    }
    cout<<"number of Blocks are:"<<count<<endl;
    int size_decl;
    size_decl=sqrt(count);//to get the number of rows and columns in a column matrix
    cout<<size_decl<<endl;

    float intensity_sum[size_decl][size_decl];
    for(i=0;i<=high;i+=shift_size)
    {
        for(j=0;j<=wide;j+=shift_size)
        {
            Rect roi(i,j,BLOCK_SIZE,BLOCK_SIZE);
            block=saliency_map(roi);
            sum_of_intensity=sum(block);

            cout<<"intensities in "<<i<<"\t"<<j<<"\t"<<sum_of_intensity.val[0]<<endl;

            if(sum_of_intensity.val[0]>great)
            {
                great=sum_of_intensity.val[0];
                pixel_x=i;
                pixel_y=j;

            }
           intensity_sum[ver][hor]=sum_of_intensity.val[0];
            hor++;
        }
        ver++;   //to move to next line in a row
        hor=0;   //to return to start of next line
    }
    cout<<"Horizantal index is"<<hor<<endl;
    cout<<"vertical index is"<<ver<<endl;

    cout<<"pixel locations:"<<pixel_x<<" "<<pixel_y<<"\t"<<endl;
    cout<<"greatest intensity :"<<great<<endl;



    /*getting the region of max priority
    Rect roi(pixel_x,pixel_y,BLOCK_SIZE,BLOCK_SIZE);

    Mat xyz;
    xyz=saliency_map(roi);
    imshow("salient most",xyz);*/

/*   do
    {

        test=0;

        for(i=0;i<size_decl;i++)
        {
            for(j=0;j<size_decl;j++)
            {
               // cout<<(i*shift_size)<<"\t"<<(j*shift_size)<<"\t"<<intensity_sum[i][j]<<endl;
                if(intensity_sum[i][j]>test)
                {
                    test=intensity_sum[i][j];
                    pos_x=(i*shift_size);
                    pos_y=(j*shift_size);

                }
            }
        }
        Point p1(pos_x,pos_y);
        Point p2(pos_x+(BLOCK_SIZE-1),pos_y+(BLOCK_SIZE-1));
        //Scalar color(255,255,255);
        rectangle(saliency_map,p1,p2,CV_RGB(255,255,255),1,8,0);

        if(count1==0)
        {
            waitKey(1000);
            imshow("salient most inhibition",saliency_map);
            waitKey(1000);
        }

        else if(count1==1)
        {
            waitKey(1000);
            imshow("2nd most salient inhibition",saliency_map);
            waitKey(1000);
        }

            else if(count1==2)
            {
                waitKey(1000);
                imshow("3 most salient inhibition",saliency_map);
                waitKey(1000);
            }

            else if(count1==3)
            {
                waitKey(1000);
                imshow("4 most salient inhibition",saliency_map);
                waitKey(1000);
            }
            else if(count1==4)
            {
                waitKey(1000);
                imshow("5 most salient inhibition",saliency_map);
                waitKey(1000);
            }



        cout<<"do u waana proceed to next salient region(y or n):";
        cin>>decision;
        cout<<"the decision is:"<<decision<<endl;

        if(decision=='y')
        {
            count1++;
            cout<<"inside dec if"<<endl;
            cout<<pos_x<<"\t"<<pos_y<<endl;
            int inh1,inh2;
            inh1=(pos_x/shift_size);
            inh2=(pos_y/shift_size);


            intensity_sum[inh1][inh2]=0;
            cout<<"after replacement:"<<endl;

            cout<<intensity_sum[inh1][inh2]<<endl;
        }
        //test code
        /*if(decision=='y')
        {
            count1++;
            cout<<" x: "<<pixel_x<<"\t"<<"y: "<<pixel_y<<endl;
            for(i=pixel_x;i<(pixel_x+BLOCK_SIZE);i++)
            {
                for(j=pixel_y;j<(pixel_y+BLOCK_SIZE);j++)
                {
                    //cout<<i<<"\t"<<j<<"\t"<<"pixels are made zero"<<endl;
                     saliency_map.at<float>(i,j)=0;
                }
            }
            great=0;
          //  imshow("test",saliency_map);
        }*/

  /*  }while(decision=='y');
    imshow("saliency-mamamam",saliency_map);
}*/
