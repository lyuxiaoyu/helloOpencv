// HellpOpencv.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;


bool readShowImage()
{
	char imgName[] = "image/Cheng.jpg";

	// 读入一张图片
	Mat img = imread(imgName);
	if (!img.data)
	{
		std::cout << "读取图片失败";
		return false;
	}
	// 创建一个名为 "xxxx"窗口  
	namedWindow(imgName);
	// 在窗口中显示
	imshow(imgName, img);
	// 等待6000 ms后窗口自动关闭  
	waitKey(6000);

	return true;
}


bool ROI_LinearBlending()
{
	char imgName1[] = "image/Cheng.jpg";
	char imgName2[] = "image/Logo.jpg";
	
	Mat img1 = imread(imgName1);
	Mat imgROI;
	Mat img2 = imread(imgName2);

	if (!img1.data || !img2.data)
	{
		std::cout << "读取图片失败\n";
		return false;
	}

	namedWindow(imgName1);
	imshow(imgName1, img1);
	
	namedWindow(imgName2);
	imshow(imgName2, img2);

	// ROI（region of interest）
	imgROI = img1(Rect(1, 1, img2.cols, img2.rows));	// get ROI from img1, img1 will be changed with ROI changed.
	
	addWeighted(imgROI, 0.5, img2, 0.5, 0, imgROI);		// dst = src1[I]*alpha+ src2[I]*beta + gamma;  Here dst is imgROI

	namedWindow("ROI");
	imshow("ROI", img1);

	waitKey(6000);

	return true;
}

bool splitMerge()
{
	// split
	// merge
	return true;
}

int main()
{
	// readShowImage();

	ROI_LinearBlending();

	std::cout << "hellp opencv\n";
    return 0;
}

