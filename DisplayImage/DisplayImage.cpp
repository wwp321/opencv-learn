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
    case 5:
        {
            Mat m = Mat(3, 2, CV_8UC3);
            randu(m, Scalar::all(0), Scalar::all(128));
            cout << "M=" << endl << m << endl;
            cout << "format python M=" << endl << format(m, Formatter::FMT_PYTHON) << endl;
            cout << "format matlab M=" << endl << format(m, Formatter::FMT_MATLAB) << endl;
            cout << "format numpy  M=" << endl << format(m, Formatter::FMT_NUMPY) << endl;
            cout << "format c      M=" << endl << format(m, Formatter::FMT_C) << endl;
            cout << "format csv    M=" << endl << format(m, Formatter::FMT_CSV) << endl;
        }
        break;
    case 6:
        {
            Point2f p(4, 2);
            cout << "Point(2d)" << p << endl;
            Point3f p3f(3, 1, 4);
            cout << "Point(3d)" << p3f << endl;
        }
        break;
    case 7:
        {
            vector<float> v;
            v.push_back((float)CV_PI);
            v.push_back(32.2);
            v.push_back(1111.1);
            Mat m(v);
            cout << "M=" << endl << m << endl;
        }
        break;
    default:
        break;
    }
    return 0;
}
