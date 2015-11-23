#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// Global variables

Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char *window_name = "Vision Test";
char *filename = "/home/noah/Pictures/SampleImages/image.jpg";

// Used for distance calculations
float const knownWidth = 7.0; // The known length of the objects(size of vision tape)
float const focalLength = 7.9; // The focal length of the camera(in the case of my MacPro, it is 7.9mm)
float const perWidth = 1.0; // The perceived width in pixels of the object

/**
 * @function CannyThreshold
 * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
 */
void CannyThreshold(int, void *) {
  /// Reduce noise with a kernel 3x3
  blur(src_gray, detected_edges, Size(3, 3));

  /// Canny detector
  Canny(detected_edges, detected_edges, 100, 100 * ratio, kernel_size);

  /// Using Canny's output as a mask, we display our result
  dst = Scalar::all(0);

  //double distanceToTote = findDistance();

  src.copyTo(dst, detected_edges);
  imshow(window_name, dst);
}

double findDistance(float knownWidth, float focalLength, float perWidth) {
  /*
  distance to object (mm) = focal length (mm) * real height of the object (mm) * image height (pixels)
                          ---------------------------------------------------------------------------
                                    object height (pixels) * sensor height (mm)
  */

  return (knownWidth * focalLength) / perWidth; 
}

/** @function main */
int main(int argc, char **argv) {
  /// Load an image
  src = imread(filename);

  if (!src.data) {
    return -1;
  }

  /// Create a matrix of the same type and size as src (for dst)
  dst.create(src.size(), src.type());

  /// Convert the image to grayscale
  cvtColor(src, src_gray, CV_BGR2GRAY);

  /// Create a window
  namedWindow(window_name, CV_WINDOW_AUTOSIZE);

  /// Show the image
  CannyThreshold(0, 0);

  //TODO: Calculate the distance here, snag that lifecam from the robotics room and snap some quick candids of totes

  /// Wait until user exit program by pressing a key
  waitKey(0);

  return 0;
}
