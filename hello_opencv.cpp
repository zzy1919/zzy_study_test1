#include "opencv2/opencv.hpp"
#include "iostream"

using namespace std;
 using namespace cv;

int func1();


int main(int argc, char const *argv[]){

	cv::VideoCapture capture(0);
	// if (!capture.isOpened()){
	// 	cout << "not open" << endl;
	// 	return 0;
	// }
	// cout << "open" << endl;

	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("读取视频", frame);
		waitKey(30);	//延时30
	}

	cout << "111" << endl;
    system("Pause");
	return 0;

}


int func1(){
	cv::Mat img = cv::imread("./x1.png");
	if (img.empty())
		std::cout << "image is empty or the path is invalid!" << std::endl;
	cv::imshow("Origin", img);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}