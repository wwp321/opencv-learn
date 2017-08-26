#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat& ScanImageAndReduceC(Mat& I, const uchar* table);
Mat& ScanImageAndReduceLUT(Mat& I, const uchar* table);

int main(int argc, char* argv[])
{
    int divideWidth;
    std::stringstream s;
    s << argv[2];
    s >> divideWidth;
    if( !s || !divideWidth )
    {
        cout << "Invalid Number" << endl;
        return -1;
    }

    uchar table[UCHAR_MAX + 1];
    for(int index = 0; index < UCHAR_MAX + 1; index++)
    {
        table[index] = divideWidth * (index / divideWidth);
    }

    Mat image = imread(argv[1]);
    //Mat converted = ScanImageAndReduceC(image, table);
    Mat converted = ScanImageAndReduceLUT(image, table);
    namedWindow("convertedImage", WINDOW_AUTOSIZE);
    imwrite("converted.png", converted);
    imshow("convertedImage", converted);
    waitKey(0);
    return 0;
}

Mat& ScanImageAndReduceC(Mat& I, const uchar* table)
{
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();
    int nRows = I.rows;
    int nColumes = I.cols * channels;

    if(I.isContinuous())
    {
        nColumes *= nRows;
        nRows = 1;
    }

    int i, j;
    uchar* p;
    for(i = 0; i < nRows; i++)
    {
        p = I.ptr<uchar>(i);
        for(j = 0; j < nColumes; j++){
            p[j] = table[p[j]];
        }
    }

    return I;
}


Mat& ScanImageAndReduceLUT(Mat& I, const uchar* table)
{
    Mat loopupTable(1, 256, CV_8U);
    uchar* p = loopupTable.ptr();
    for(int i = 0; i < 256; i++)
    {
        p[i] = table[i];
    }

    static Mat converted;
    LUT(I, loopupTable, converted);
    return converted;
}
