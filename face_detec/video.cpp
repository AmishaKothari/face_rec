// CPP program to detects face in a video 
  
// Include required header files from OpenCV directory 
#include <opencv2/objdetect.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <iostream> 
  
using namespace std; 
using namespace cv; 
  
// Function for Face Detection 
void detectAndDraw( Mat& img, CascadeClassifier& faceDetection, double scale ); 
string cascadeName, nestedCascadeName; 
  
int main( int argc, const char** argv ) 
{ 
    // VideoCapture class for playing video for which faces to be detected 
    VideoCapture capture;  
    Mat frame, image; 
  
    // PreDefined trained XML classifiers with facial features 
    CascadeClassifier faceDetection;  
    double scale=1; 
  
    // Load classifiers from "opencv/data/haarcascades" directory  
    if(!faceDetection.load("/opt/OPEN/opencv/data/haarcascades/haarcascade_frontalface_default.xml"))
    {
        cout<<"file is not loaded properly";
        exit(0);
    } 
  
    // Change path before execution  
    //cascade.load( "./haarcascades/data/haarcascades/haarcascade_frontalcatface.xml" ) ;  
  
    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video 
    capture.open(0);  
    if( capture.isOpened() ) 
    { 
        // Capture frames from video and detect faces 
        cout << "Face Detection Started...." << endl; 
        while(1) 
        { 
            capture >> frame; 
            if( frame.empty() ) 
                break; 
            Mat frame1 = frame.clone(); 
            detectAndDraw( frame1, faceDetection, scale );  
            char c = (char)waitKey(10); 
          
            // Press q to exit from window 
            if( c == 27 || c == 'q' || c == 'Q' )  
                break; 
        } 
    } 
    else
        cout<<"Could not Open Camera"; 
    return 0; 
} 
  
void detectAndDraw( Mat& img, CascadeClassifier& faceDetection, 
                    double scale) 
{ 
    vector<Rect> faces, faces2; 
    faceDetection.detectMultiScale(img, faces); 
  
    // Draw rectangles around the faces 
   for(int i=0; i<faces.size();i++)
        {
            Point pt1(faces[i].x , faces[i].y);
            Point pt2( (faces[i].x + faces[i].height), (faces[i].y+ faces[i].width )); 
            rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);
        }
  
    // Show Processed Image with detected faces 
    imshow( "Face Detection", img );  
}