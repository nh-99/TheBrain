#include "vision.h"

Mat src_gray, srcImage, hsvIm, cannyIm, threshold_output;
map<int, double> results;
vector<vector<Point> > contours;

int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

int main(int argc, const char* argv[]) {
    Vision vt;
    srcImage = imread("/home/noah/Pictures/RealFullField/0.jpg",1);
    cvtColor( srcImage, src_gray, CV_BGR2GRAY );
    cout << "test" << endl;
    blur( src_gray, src_gray, Size(3,3) );
///    hsvIm = vt.applyHsvThreshold(src_gray);
    cout << "test2" << endl;
    cannyIm = vt.applyCannyTransform(src_gray);
    cout << "tes3" << endl;
    contours = vt.getContours(cannyIm);
    cout << "test4" << endl;
    /// Approximate contours to polygons + get bounding rects and circles
  vector<vector<Point> > contours_poly( contours.size() );
  vector<Rect> boundRect( contours.size() );
  vector<Point2f>center( contours.size() );
  vector<float>radius( contours.size() );

  for( int i = 0; i < contours.size(); i++ )
     { approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       boundRect[i] = boundingRect( Mat(contours_poly[i]) );
       minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
     }

  /// Draw polygonal contour + bonding rects + circles
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
       rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
       circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 );
     }

  /// Show in a window
  namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );
}
