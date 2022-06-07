#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
	Mat src = imread("KamenriderREVI.jpg");
	Mat src1 = src;
	Mat out;

	namedWindow("原图");
	imshow("原图", src);

	//方法一3以下的版本
	Canny(src, out, 150, 100);
	namedWindow("方法一的效果图");
	imshow("方法一的效果图", out);

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

	namedWindow("方法二的效果图");
	imshow("方法二的效果图", out2);

	waitKey();
	return 0;
}