// HistEq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;


int main(int argc, const char** argv[])
{
	cv::Mat inp_img = cv::imread("el4.jpg");
	if (!inp_img.data){
		cout << "Something Wrong";
		return -1;
	}
	namedWindow("Input Image", CV_WINDOW_AUTOSIZE);
	imshow("Input Image", inp_img);

	vector<Mat> channels;
	Mat histeq_img;
	cvtColor(inp_img, histeq_img, CV_BGR2YCrCb);
	split(histeq_img, channels);
	equalizeHist(channels[0], channels[0]);
	merge(channels, histeq_img);
	cvtColor(histeq_img, histeq_img, CV_YCrCb2BGR);

	namedWindow("Histogram Equalized Image", CV_WINDOW_AUTOSIZE);
	imshow("Histogram Equalized Image", histeq_img);
	imwrite("out.jpg", histeq_img);
	waitKey(0);
	destroyAllWindows();
	
	return 0;
}

