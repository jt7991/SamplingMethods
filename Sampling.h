#pragma once
#include <math.h>
#include "of3dGraphics.h"
#include "ofImage.h"
class Sampling
{
public:
	Sampling();
	~Sampling();
	double drawLines(int x, int y);
	double drawLines(int x, int y, double lineWidth);
	double drawLinesWithSampling(double x, double y, double lineWidth);
	double startRandomSampling(double numPixels, double x, double y, double lineWidth);
	double startJitteredSampling(double numPixels, double x, double y, double lineWidth);
	ofImage calculatePixels(double minX, double maxX, double minY, double maxY, ofImage img, std::string samplingType, double lineWidth);
	double startSamplingMethod1(int numPixels, double x, double y, double dx, double dy, double lineWidth);
};

