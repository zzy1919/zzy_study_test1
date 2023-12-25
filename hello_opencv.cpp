#include "opencv2/opencv.hpp"
#include "iostream"

using namespace std;
using namespace cv;

int func1();
void MouseCvTest();
void MyMouseCallback(int event, int x, int y, int flags, void* userdata);
void MyTrackbarCallback();
void mySetImg(cv::Mat& img, int x=0, int y=0, int z=0);


int main(int argc, char const *argv[]){

	// cv::VideoCapture capture(0);

	// while (true)
	// {
	// 	Mat frame;
	// 	capture >> frame;
	// 	imshow("读取视频", frame);
	// 	waitKey(30);	//延时30
	// }

	// func1();
	MouseCvTest();


	cout << "111" << endl;
    // system("Pause");
	return 0;
}

int func1(){
	cv::Mat img = cv::imread("../x1.png", IMREAD_GRAYSCALE);
	cout <<  cv::imread("../x1.png", IMREAD_GRAYSCALE).type() <<endl;
	cout <<  img.type() << endl;

	cv::namedWindow("Origin", WINDOW_NORMAL);
	cv::resizeWindow("Origin", 800, 600);

	if (img.empty())
		std::cout << "image is empty or the path is invalid!" << std::endl;
	cv::imshow("Origin", img);
	int key = cv::waitKey(0);
	cout << key << " " << key+1 << endl;

	cv::imwrite("D:\\gitcode\\zzy_study_test1\\grayimg1.png", img);

	cv::destroyAllWindows();


	cv::namedWindow("video", WINDOW_NORMAL);
	cv::resizeWindow("video", 640, 480);
	cv::VideoCapture cap = cv::VideoCapture(0);
	if (!cap.isOpened()) {cout << "failed open" << endl; return -1;}
	cv::VideoWriter vc = cv::VideoWriter("./out.mp4", cv::VideoWriter::fourcc('M','J','P','G'), 30, Size(1280, 720));
	while (1)
	{
		cv::Mat frame;
		cap.read(frame);
		cv::imshow("video", frame);
		if (!vc.isOpened()) {
			std::cout << "Failed to create video writer." << std::endl;
			return -1;
    	}
		vc.write(frame);

		int key2 = cv::waitKey(0);
		cout << key2 << " " << endl;
		if (key2 == 113){
			break;
		}
	}
	cap.release();
	vc.release();
	cv::destroyAllWindows();
	return 0;
}

void MyMouseCallback(int event, int x, int y, int flags, void* userdata){
	if (event == cv::EVENT_LBUTTONDOWN){
		cout << "鼠标点击右键" << event << " " << x << " " << y << " " << flags << " " << userdata << endl;
	}
	// cout << event << " " << x << " " << y << " " << flags << " " << userdata << endl;
}

void MyTrackbarCallback(int value, void* userdata){
	// cout << "my trackbar callback" << endl;
	int i=0;
}

void MouseCvTest(){
	// cv::Mat img(640, 640, CV_8UC3);
	// cv::namedWindow("mousecvtest", WINDOW_NORMAL);
	// cv::resizeWindow("mousecvtest", 640, 640);

	// cv::setMouseCallback("mousecvtest", MyMouseCallback);

	// while (true){
	// 	cv::imshow("mousecvtest", img);
	// 	if (cv::waitKey(1) == 113) break;
	// }
	// cv::destroyAllWindows();


	cv::namedWindow("trackbarwin", cv::WINDOW_NORMAL);
	cv::resizeWindow("trackbarwin", 640, 480);
	cv::createTrackbar("trackbar1", "trackbarwin", 0, 255, MyTrackbarCallback);
	cv::Mat img(480, 640, CV_8UC3);
	cout << img.size << " " << img.dims  << " " << img.type() << " " << img.channels() << endl;
	vector<cv::Mat> vec_channel;	
	cv::split(img, vec_channel);
	cout << vec_channel[0].size << " " << vec_channel[0].dims  << " " << vec_channel[0].channels() << endl;
	for (int i = 0; i < vec_channel[0].rows; i++) {
		for (int j = 100; j < 110; j++) {
			// 修改像素值为 255（白色）
			vec_channel[0].at<uchar>(i, j) = 255;
		}
    }
	cv::imshow("b", vec_channel[0]);
	
	cv::merge(vec_channel, img);
	cv::imshow("new", img);

	// mySetImg(img, 0, 0, 0);

	while (true){
		cv::resizeWindow("trackbarwin", img.cols, img.rows);
		int color = cv::getTrackbarPos("trackbar1", "trackbarwin");
		mySetImg(img, color, color, color);
		
		cv::imshow("trackbarwin", img);
		int key = cv::waitKey(1);
		if (key == 113) {break;}
	}
	cv::destroyAllWindows();
}

void mySetImg(cv::Mat& img, int x, int y, int z){
	for (int i=0; i < img.rows; i++){
		for (int j=0; j < img.cols; j++){
			img.at<cv::Vec3b>(i, j) = cv::Vec3b(x, y, z);
		}
	}
}
