// opencv_video.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;
int main()
{
	VideoCapture capture("D:/movie/surface.mp4");	//捕获视频
	if (!capture.isOpened())
		return 1;	
	double rate = capture.get(CV_CAP_PROP_FPS);	//获取视频参数	
	bool stop(false);
	Mat frame;		//声明图像格式变量
	namedWindow("Canny Video");		
	int delay = 100 / rate;
	
	while (!stop)
	{
	if (!capture.read(frame))
		break;
		Mat result;		
		Canny(frame, result, 100, 180);	//输入，输出，阈值1，阈值2
		threshold(result, result, 128, 255, THRESH_BINARY);
		imshow("Canny Video", result);

		if (waitKey(delay) >= 0)
		stop = true;
	}
	capture.release();
}
