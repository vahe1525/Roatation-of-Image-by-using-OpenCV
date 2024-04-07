
//OpenCV include
#include <opencv2/opencv.hpp>

//Standart Libraries
#include <iostream>

//Project includes 
#include "Matrix.hpp" 
#include "Webcam.hpp" 
#include "Rotator.hpp" 
#include "BMPExporter.hpp" 
#include "CvMatConverter.hpp" 

using namespace cv;

int main()
{
    // Webcam & Exporter objects
    Webcam webcam;
    BMPExporter exporter;

    //CV Mat converter object & Rotator Object
     CVMatConverter converter;
     Rotator rot;

    //variable for rotation angle
    double angle = 0;

    //Geetak Matrix 
    Matrix matrix = webcam.Frame();

    //inserting angle for rotation
    std::cout << " insert angle = ";
    std::cin >> angle;

   //Converting To CV Mat Image
    Mat image = converter.MatrixToMat(matrix);
    
    // Rotating Image
    Mat rotatedImage = rot.rotateImage(image, angle);

    //Converting To CV Mat Image
    Matrix rotatedMatrix = converter.MatToMatrix(rotatedImage);

    //Exporting 
    exporter.Export(matrix, "Output/originalPicture");
    exporter.Export(rotatedMatrix, "Output/rotatedPicture");
}
