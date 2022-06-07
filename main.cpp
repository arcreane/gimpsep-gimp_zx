#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "definition.h"
using namespace std;
using namespace cv;

int main() 
{   //%%1.Erosion_Dilatation%%//
	
	Mat g_srcImage, g_dstImage;
	int g_nTrackbarNumer = 0;//0表示腐蚀erode, 1表示膨胀dilate
	int g_nStructElementSize = 3; //结构元素(内核矩阵)的尺寸
											  //载入原图
	g_srcImage = imread("eco.jpg");
	if (!g_srcImage.data) { printf("No image data~！ \n"); return false; }


	//显示原始图
	namedWindow("【Original Image】");
	imshow("【Original Image】", g_srcImage);

	//进行初次腐蚀操作并显示效果图
	namedWindow("【Original Image】");
	//获取自定义核
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1), Point(g_nStructElementSize, g_nStructElementSize));
	erode(g_srcImage, g_dstImage, element);
	imshow("【Dilatation/Erosion Image】", g_dstImage);

	//创建轨迹条
	//g_nTrackbarNumer的值从0~1，0表示腐蚀erode, 1表示膨胀dilate，相当于腐蚀和膨胀的切换开关
	createTrackbar("Dilatation/Erosion", "【Dilatation/Erosion Image】", &g_nTrackbarNumer, 1, on_TrackbarNumChange, &g_srcImage);
	createTrackbar("size of element", "【Dilatation/Erosion Image】", &g_nStructElementSize, 21, on_ElementSizeChange, &g_srcImage);

	//输出一些帮助信息
	//cout << endl << "\t运行成功，请调整滚动条观察图像效果~\n\n"
		//<< "\t按下“q”键时，程序退出。\n";

	//轮询获取按键信息，若下q键，程序退出
	//while (char(waitKey(1)) != 'q') {}

	//return 0;
	
	//%%2.Resizing%%//
	// let's downscale the image using new  width and height
	int down_width = 300;
	int down_height = 200;
	Mat resized_down;
	//resize down
	resize(g_srcImage, resized_down, Size(down_width, down_height), INTER_LINEAR);
	// let's upscale the image using new  width and height
	int up_width = 600;
	int up_height = 400;
	Mat resized_up;
	//resize up
	resize(g_srcImage, resized_up, Size(up_width, up_height), INTER_LINEAR);
	// Display Images and press any key to continue
	imshow("Resized Down by defining height and width", resized_down);
	waitKey();
	imshow("Resized Up image by defining height and width", resized_up);
	waitKey();
	destroyAllWindows();
	//return 0;
	
	//%%3.Lighten_Darken

	int g_slider1_pos = 10;
	int g_slider2_pos = 0;
	const char* windowName = "Contrast And Brightness";

	Mat srcImage = imread("eco.jpg");
	if (!srcImage.data) {
		cerr << "fail to load image" << endl;
		return -1;
	}
	namedWindow(windowName, WINDOW_AUTOSIZE);
	createTrackbar("Contrast", windowName, &g_slider1_pos, 300, ContrastAndBright,
		(void*)&srcImage); //对比度
	createTrackbar("Brightness", windowName, &g_slider2_pos, 100,
		ContrastAndBright, (void*)&srcImage); //亮度

	ContrastAndBright(g_slider1_pos, (void*)&srcImage);
	ContrastAndBright(g_slider2_pos, (void*)&srcImage);
	imshow(windowName, srcImage);
	waitKey();
	destroyAllWindows();
	return 0;
	//%%4.Panorama%%//
	Mat img1 = imread("KamenriderREVI.jpg");
	Mat img2 = imread("KamenriderVICE.jpg");
	if (img1.empty() || img2.empty())
	{
		cout << "Failed to load the image, please check whether the corresponding path image exists!" << endl;
		return 1;
	}
	imshow("src1", img1);
	imshow("src2", img2);
	int w1 = img1.cols; int h1 = img1.rows;
	int w2 = img2.cols; int h2 = img2.rows;
	int width = w1 + w2; int height = max(h1, h2);
	Mat  resultImg = Mat(height, width, CV_8UC3, Scalar::all(0));
	Mat ROI_1 = resultImg(Rect(0, 0, w1, h1));
	Mat ROI_2 = resultImg(Rect(w1, 0, w2, h2));
	img1.copyTo(ROI_1);
	img2.copyTo(ROI_2);
	imshow("result", resultImg);
	//imwrite("result.jpg", resultImg);
	waitKey(0);
	//return 0;

	//%%5.canny%%//
	Mat src = imread("KamenriderREVI.jpg");
	Mat src1 = src;
	Mat out;

	namedWindow("Original Image");
	imshow("Original Image", src);

	//方法一3以下的版本
	Canny(src, out, 150, 100);
	namedWindow("Effect diagram of method 1");
	imshow("Effect diagram of method 1", out);

	//方法二3以上的版本
	Mat dst, edge, gray;

	//创建一个与src1一样的矩阵
	dst.create(src1.size(), src1.type());

	//将原图像转为灰度
	cvtColor(src1, gray, COLOR_RGB2GRAY);

	//滤波(降噪)
	blur(gray, edge, Size(3, 3));

	//canny
	Mat out2;
	Canny(edge, out2, 15, 10);


	dst = Scalar::all(0);

	src1.copyTo(dst, out2);

	namedWindow("Effect diagram of method 2");
	imshow("Effect diagram of method 2", out2);

	waitKey();
	return 0;
}
