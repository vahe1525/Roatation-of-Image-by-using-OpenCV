cmake_minimum_required(VERSION 2.8)
project( RotateImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( RotateImage Main.cpp Matrix.hpp  BMPExporter.hpp Constants.hpp Pixel.cpp Point.cpp Webcam.cpp CvMatConverter.hpp)
target_link_libraries( RotateImage ${OpenCV_LIBS} )

