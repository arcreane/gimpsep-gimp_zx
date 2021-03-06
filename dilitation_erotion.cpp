#//---------------------------------【头文件、命名空间包含部分】-----------------------------
//		描述：包含程序所使用的头文件和命名空间
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "definition.h"
using namespace std;
using namespace cv;


//-----------------------------------【全局变量声明部分】--------------------------------------
//		描述：全局变量声明
//-----------------------------------------------------------------------------------------------
Mat* g_srcImage, g_dstImage;//原始图和效果图
int g_nTrackbarNumer = 0;//0表示腐蚀erode, 1表示膨胀dilate
int g_prevValue;

//-----------------------------------【全局函数声明部分】--------------------------------------
//		描述：全局函数声明
//-----------------------------------------------------------------------------------------------
//void Process();//膨胀和腐蚀的处理函数
//void on_TrackbarNumChange(int, void*);//回调函数
//void on_ElementSizeChange(int, void*);//回调函数

//-----------------------------------【main( )函数】--------------------------------------------
//		描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------------------------------------------

//-----------------------------【Process( )函数】------------------------------------
//		描述：进行自定义的腐蚀和膨胀操作
//-----------------------------------------------------------------------------------------
void Process(int value, void * img)
{
	//获取自定义核
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * value + 1, 2 * value + 1), Point(value, value));
	g_srcImage = (Mat*)img;
	//进行腐蚀或膨胀操作
	if (g_nTrackbarNumer == 0) {//0erode
		erode(*g_srcImage, g_dstImage, element);
	}
	else {//1dilate
		dilate(*g_srcImage, g_dstImage, element);
	}

	//显示效果图
	imshow("【Dilatation/Erosion Image】", g_dstImage);
	g_prevValue = value;
}


//-----------------------------【on_TrackbarNumChange( )函数】------------------------------------
//		描述：腐蚀和膨胀之间切换开关的回调函数
//-----------------------------------------------------------------------------------------------------
void on_TrackbarNumChange(int value, void* img)
{
	//腐蚀和膨胀之间效果已经切换，回调函数体内需调用一次Process函数，使改变后的效果立即生效并显示出来
	g_nTrackbarNumer = value; 
	Process(g_prevValue, img);
}


//-----------------------------【on_ElementSizeChange( )函数】-------------------------------------
//		描述：腐蚀和膨胀操作内核改变时的回调函数
//-----------------------------------------------------------------------------------------------------
void on_ElementSizeChange(int value, void* img)
{
	
	//内核尺寸已改变，回调函数体内需调用一次Process函数，使改变后的效果立即生效并显示出来
	Process(value, img);
}

//int main()
//{
	//载入原图
	//g_srcImage = imread("eco.jpg");
	//if (!g_srcImage.data) { printf("No image data~！ \n"); return false; }


	//显示原始图
	//namedWindow("【Original Image】");
	//imshow("【Original Image】", g_srcImage);

	//进行初次腐蚀操作并显示效果图
	//namedWindow("【Original Image】");
	//获取自定义核
	//Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1), Point(g_nStructElementSize, g_nStructElementSize));
	//erode(g_srcImage, g_dstImage, element);
	//imshow("【Dilatation/Erosion Image】", g_dstImage);

	//创建轨迹条
	//g_nTrackbarNumer的值从0~1，0表示腐蚀erode, 1表示膨胀dilate，相当于腐蚀和膨胀的切换开关
	//createTrackbar("Dilatation/Erosion", "【Dilatation/Erosion Image】", &g_nTrackbarNumer, 1, on_TrackbarNumChange);
	//createTrackbar("size of element", "【Dilatation/Erosion Image】", &g_nStructElementSize, 21, on_ElementSizeChange);

	//输出一些帮助信息
	//cout << endl << "\t运行成功，请调整滚动条观察图像效果~\n\n"
		//<< "\t按下“q”键时，程序退出。\n";

	//轮询获取按键信息，若下q键，程序退出
	//while (char(waitKey(1)) != 'q') {}

	//return 0;
//}

