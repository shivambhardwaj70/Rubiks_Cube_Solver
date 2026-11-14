#ifndef RUBIKS_CUBE_SOLVER_CUBESCANNER_H
#define RUBIKS_CUBE_SOLVER_CUBESCANNER_H

#include <opencv2/opencv.hpp>
#include "../Model/GenericRubiksCube.h"
#include "../bits/stdc++.h"

using namespace std;
using namespace cv;

class CubeScanner {
public:
    CubeScanner(int camIndex = 0, int boxSize = 60);
    ~CubeScanner();

    void scan(GenericRubiksCube& cube);

private:
    VideoCapture cap;
    int boxSize;

    static const map<GenericRubiksCube::COLOR, Scalar> colorMap;

    GenericRubiksCube::COLOR classifyColor(const Vec3b& bgr);
    Vec3b medianColor(const Mat& frame, int centerX, int centerY, int region = 5);

    vector<vector<GenericRubiksCube::COLOR>> captureFace();
    Mat drawColorFace(const vector<vector<GenericRubiksCube::COLOR>>& faceGrid);
    Mat drawFullCube(const vector<vector<vector<GenericRubiksCube::COLOR>>>& cubeGrid);
};


#endif //RUBIKS_CUBE_SOLVER_CUBESCANNER_H
