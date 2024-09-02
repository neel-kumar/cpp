#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    cv::Mat input = cv::imread("C:/StackOverflow/Input/parking.png");
    cv::Mat gray;
    cv::cvtColor(input, gray, CV_BGR2GRAY);


    cv::Ptr<cv::LineSegmentDetector> det;
    det = cv::createLineSegmentDetector();



    cv::Mat lines;
    det->detect(gray, lines);

    det->drawSegments(input, lines);

    cv::imshow("input", input);
    cv::waitKey(0);
    return 0;
}
