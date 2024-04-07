
#ifndef MATRIX
#define MATRIX

// Standard libraries
#include <iostream>

// Project librarie
#include "Constants.hpp"
#include "Point.hpp"
#include "Pixel.hpp"

class Matrix
{
private:

public:
    // Dimentions
    int Width = 0;
    int Height = 0;

    // Center of the stamp
    //Point Center;

    //angles for camera distortion
    double alpha = 0;    //alpha is for Gyroscope X
    double betta = 0;	 //betta is for Gyroscope Y

    //current position of camera
    Point position;

    // Data
    Pixel Data[CAMERAHEIGHT][CAMERAWIDTH];

    Matrix()
    {
    
        Width = CAMERAWIDTH;
        Height = CAMERAHEIGHT;
    }

    //init Matrix
    void InitMatrix(double alfa, double betta, Point posPoint)
    {
	this->alpha = alfa;
	this->betta = betta;
	this->position = posPoint;
    }

    void operator= (const Matrix& copyMatrix)
    {
	Width = copyMatrix.Width;
	Height = copyMatrix.Height;

	for (int i = 0; i < CAMERAHEIGHT; ++i)
	{
	    for (int j = 0; j < CAMERAWIDTH; ++j)
	    {
		Data[i][j] = copyMatrix.Data[i][j];
	    }
	}

	//Gyro angles
	alpha = copyMatrix.alpha;
	betta = copyMatrix.betta;

	//position of matrix
	position = copyMatrix.position;
    }

    // Constructor
    Matrix(const Matrix& copyMatrix)
        : Width(copyMatrix.Width)
          , Height(copyMatrix.Height)
    {
	for (int i = 0; i < CAMERAHEIGHT; ++i)
	{
	    for (int j = 0; j < CAMERAWIDTH; ++j)
	    {
		Data[i][j] = copyMatrix.Data[i][j];
	    }
	}
    }
    
};

#endif // MATRIX
