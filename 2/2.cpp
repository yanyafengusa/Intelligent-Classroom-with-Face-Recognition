// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main(int argc, char **argv)
{
	const char* filename = "bee.jpg";
	Mat srcImg = imread(filename, CV_LOAD_IMAGE_COLOR);
	if(srcImg.empty())
		return -1;
	//imshow("source", srcImg);
 
	double timeSpent = (double)getTickCount();
 
	//-----------------------------------
 
	Mat tmp1Img(srcImg.size(),CV_8UC1);
	Mat tmp3Img(srcImg.size(),CV_8UC3);
	cvtColor(srcImg,tmp1Img,CV_RGB2GRAY);
	cvtColor(tmp1Img,tmp3Img,CV_GRAY2RGB);
 
	Mat dstImg(srcImg.size(), CV_8UC3);
 
	double blender;
 
	for(int i=0; i<100; i++)
	{
		blender = (double)i/100.0;
		addWeighted(srcImg,1-blender,tmp3Img,blender,0,dstImg);
		imshow("result",dstImg);
 
		waitKey(30);
	}
 
	//------------------------------------
 	timeSpent = ((double)getTickCount() - timeSpent)/getTickFrequency();
 	cout << "Time spent in milliseconds: " << timeSpent*1000 << endl;
 
	waitKey(0);
 
	return 0;
}

