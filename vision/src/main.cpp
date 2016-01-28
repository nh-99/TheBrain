#include "vision.h"

Mat src;
Vision vt;
RNG rng(12345);
int w_filter = 0;

int main(int argc, const char* argv[]) {
    src = imread(argv[1], 1);
    Mat hsv_image = vt.applyHsvThreshold(src);
    vector<Rect> getRectangles = vt.getContours(hsv_image);
    for(int i = 0; i < getRectangles.size(); i++) {
        cout << (getRectangles[i].width * getRectangles[i].height) << endl;
    }
    Mat drawing = Mat::zeros( hsv_image.size(), CV_8UC3 );
  src.copyTo(drawing);
  for( int i = 0; i< getRectangles.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       if(getRectangles[i].width > w_filter) { // Filter width
         rectangle( drawing, getRectangles[i].tl(), getRectangles[i].br(), color, 2, 8, 0 );
       }
     }
  imshow("test", drawing);
  waitKey();
}
