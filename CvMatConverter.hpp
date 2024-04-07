#ifndef CVMATCONVERTOR
#define CVMATCONVERTOR

//Converter for converting Geetak Matrix to OpenCV Mat and vice versa

//OpenCV
#include <opencv2/opencv.hpp>

//Project Includes
#include "Matrix.hpp"

class CVMatConverter
{
private:

public:

    // Function to convert OpenCV Mat to Matrix image
    Matrix MatToMatrix(const cv::Mat& matImage)
    {
	// Get the dimensions of the Mat image
	int height = matImage.rows;
	int width = matImage.cols;

	// Create a Matrix object with the same dimensions as the Mat image
	Matrix matrixImage;
	matrixImage.Height = height;
	matrixImage.Width = width;

	// Iterate over the pixels in the Mat image and set the corresponding values in the Matrix image
	for (int i = 0; i < height; ++i)
	{
	    for (int j = 0; j < width; ++j)
	    {
		// Access the pixel values from the Mat image
		cv::Vec3b pixel = matImage.at<cv::Vec3b>(i, j);

		// Set the pixel values in the Matrix image
		matrixImage.Data[i][j].B = pixel[0];
		matrixImage.Data[i][j].G = pixel[1];
		matrixImage.Data[i][j].R = pixel[2];
	    }
	}

	return matrixImage;
    }

    // Function to convert Matrix image to OpenCV Mat
    cv::Mat MatrixToMat(const Matrix& matrixImage)
    {
	// Create an empty Mat object with the same dimensions as the Matrix image
	cv::Mat matImage(matrixImage.Height, matrixImage.Width, CV_8UC3);

	// Iterate over the pixels in the Matrix image and set the corresponding values in the Mat image
	for (int i = 0; i < matrixImage.Height; ++i)
	{
	    for (int j = 0; j < matrixImage.Width; ++j)
	    {
		// Access the pixel values from the Matrix
		Pixel pixel = matrixImage.Data[i][j];

		// Set the pixel values in the Mat image
		matImage.at<cv::Vec3b>(i, j) = cv::Vec3b(pixel.B, pixel.G, pixel.R);
	    }
	}

	return matImage;
    }

};

#endif // CVMATCONVERTOR
