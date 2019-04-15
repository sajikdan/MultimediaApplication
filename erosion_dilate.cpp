#include "erosion_dilate.h"

using namespace cv;
using namespace std;

int erosion_dilate(Mat image) {
	Mat image_dst;
	String window_image;
	int ret = 0;

	if (!image.data) {
		cout << "Failed to read images";
		return EXIT_FAILURE;
	}
	//Check for failure
	
	int pos = 1;
	int max = 25;

	while (!ret) {
		cout << "1. Erode" << endl;
		cout << "2. Dilate" << endl;

		char c;
		cin >> c;

		switch (c) {
		case '1': 
			ret = 1;
			window_image = String("erode");
			namedWindow(window_image, WINDOW_AUTOSIZE);
			createTrackbar("Erode", window_image, &pos, max, tb_erosion, &image);
			imshow(window_image, image);
			break;
		case '2': 
			ret = 2;
			window_image = String("dilate");
			namedWindow(window_image, WINDOW_AUTOSIZE);
			createTrackbar("Dilate", window_image, &pos, max, tb_dilate, &image);
			imshow(window_image, image);
			break;
		}
	}
	
	waitKey(0);

	destroyAllWindows();

	return EXIT_SUCCESS;
}

void tb_erosion(int value, void* userdata) {
	Mat image_dst;

	if (value <= 0) {
		value = 1;
	}

	Mat mask = getStructuringElement(MORPH_RECT, Size(value, value));
	erode(*(Mat*)userdata, image_dst, mask);

	imshow("erode", image_dst);
}

void tb_dilate(int value, void* userdata) {
	Mat image_dst;

	if (value <= 0) {
		value = 1;
	}

	Mat mask = getStructuringElement(MORPH_RECT, Size(value, value));
	dilate(*(Mat*)userdata, image_dst, mask);

	imshow("dilate", image_dst);
}
