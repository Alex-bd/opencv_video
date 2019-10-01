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
	std::cout <<"读取千峰教育python视频";
	VideoCapture capure("D:1.MP4");		//创建视频对象
	if(!capure.isOpened())		//判断是否正常打开视频
	{
		return 1;
	}
	double rate = capure.get(CV_CAP_PROP_FPS);	//获取帧率
	bool stop(false);
	Mat frame;	//当前视频帧
	namedWindow("Extracted Frame");
	
	int delay = 1000 / rate;	
	while (!stop)		//如果不到视频最后，就一直循环帧
	{
		if (!capure.read(frame))	//把capure的视频帧读到frame图片上
		{
			break;
		}
		//resizeWindow("Extracted Frame", 800, 600);
		imshow("Extracted Frame", frame);	//在窗口中显示出来
		if (waitKey(delay)>= 0)//允许通过任意键来中断读取
			//如果延迟参数设置为0，则会无限等待用户按键
		{
			stop = true;
		}
	}
	capure.release();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
