#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "definition.h"

int g_slider1_pos = 10;
int g_slider2_pos = 0;
const char* windowName = "Contrast And Brightness";
void ContrastAndBright(int pos, void* data) {
    Mat srcImage = *(Mat*)data;
    Mat dstImage = srcImage.clone();
    int rows = srcImage.rows;
    int cols = srcImage.cols;
    float alpha = (float)g_slider1_pos / 100;
    float beta = g_slider2_pos;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (srcImage.channels() == 1) {
                uchar pixel = srcImage.at<uchar>(i, j);
                dstImage.at<uchar>(i, j) = saturate_cast<uchar>(pixel * alpha + beta);
            }
            if (srcImage.channels() == 3) {
                float b = srcImage.at<Vec3b>(i, j)[0];
                float g = srcImage.at<Vec3b>(i, j)[1];
                float r = srcImage.at<Vec3b>(i, j)[2];
                dstImage.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(b * alpha + beta);
                dstImage.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(g * alpha + beta);
                dstImage.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(r * alpha + beta);
            }
        }
    }
    imshow(windowName, dstImage);
}
