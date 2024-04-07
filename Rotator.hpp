#ifndef ROTATOR_HPP
#define ROTATOR_HPP

//OpenCV
#include <opencv2/opencv.hpp>

using namespace cv;

class Rotator
{
private:

public:

    Mat rotateImage(const Mat& image, double angle)
    {
	// Get image center
	Point2f center(image.cols / 2.0, image.rows / 2.0);

	// Compute rotation matrix
	Mat rotationMatrix = getRotationMatrix2D(center, angle, 1.0);

	// Rotate the image
	Mat rotatedImage;

	warpAffine(image, rotatedImage, rotationMatrix, image.size());

	return rotatedImage;
    }

};

#endif //ROTATOR_HPP
