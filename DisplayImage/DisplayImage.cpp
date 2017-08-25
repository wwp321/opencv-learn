#include <iostream>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc,char* argv[])
{
    int exampleId = atoi(argv[1]);
    cout << "Run example:" << exampleId << endl;
    switch(exampleId){
    case 1:
        {
            if(argc != 3){
                cout << "usage DispalyImage.out <Image Path>" << endl;
                return -1;
            }

            Mat image;
            image = imread(argv[2],1);
            if(!image.data)
            {
                cout << "No Image Data" << endl;
                return -1;
            }

            namedWindow("DisplayImage", WINDOW_AUTOSIZE);
            imshow("DisplayImage", image);

            Mat grayImage;
            cvtColor(image, grayImage, COLOR_BGR2GRAY);
            imwrite("./GrayImage.png", grayImage);

            namedWindow("GrayImage", WINDOW_AUTOSIZE);
            imshow("GrayImage", grayImage);

            waitKey(0);
        }
        break;
    case 2:
        {
            Mat m(2, 2, CV_8UC3, Scalar(0, 0, 255));
            cout << "M=" << endl << m << endl;
        }
        break;
    case 3:
        {
            int sz[3] = {2,2,2};
            Mat m(3, sz, CV_8UC(1), Scalar::all(0));
            //cout << "M=" << endl << m << endl;
        }
        break;
    case 4:
        {
            Mat m;
            m.create(4, 4, CV_8UC(2));
            cout << "M=" << endl << m << endl;
        }
        break;
    default:
        break;
    }
    return 0;
}
