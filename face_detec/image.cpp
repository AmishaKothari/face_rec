#include<iostream>
#include<stdlib.h>
#include<opencv2/objdetect/objdetect.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
 
using namespace std;
using namespace cv;
 
int main()
{
    CascadeClassifier faceDetection;
    if(!faceDetection.load("/opt/OPEN/opencv/data/haarcascades/haarcascade_frontalface_default.xml"))
    {
        cout<<"file is not loaded properly";
        exit(0);
    }
 
    //char path[100];
    //path ="lena5.jpg";
 
    Mat img=imread("sample.jpeg", CV_LOAD_IMAGE_UNCHANGED);
 
    if(img.empty())
    {
        cout<<"\n Image is not loaded properly";
    }
    else
    {
        cout<<"image loaded";
        cout<<"processing...";
 
        vector<Rect> faces;
        faceDetection.detectMultiScale(img, faces); //detecting here
 
        for(int i=0; i<faces.size();i++)
        {
            Point pt1(faces[i].x , faces[i].y);
            Point pt2( (faces[i].x + faces[i].height), (faces[i].y+ faces[i].width )); 
            rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);
        }
 
        namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
        imshow( "Display window", img );                // Show our image inside it.
        waitKey(0); // Wait for a keystroke in the window
        cout<< "face detected OK!";
 
    }
    
    return 0;
 
}