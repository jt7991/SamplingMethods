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
	ofImage startJitteredSampling(double minX, double maxX, double minY, double maxY, ofImage img, double lineWidth, int numSamples, int sampleGridWidth);
	ofImage calculatePixels(double minX, double maxX, double minY, double maxY, ofImage img, std::string samplingType, double lineWidth);
	int screenX(double x, int gridWidth);
	int screenY(double y, int gridHeight);
	bool hitGrid(double x, double y, int spacing, double lineWidth);
	ofImage startRandomSampling(double minX, double maxX, double minY, double maxY, ofImage img, double lineWidth, int numSamples);
	ofImage calculateSamples(double minX, double maxX, double minY, double maxY, int numSamples);
	double startSamplingMethod1(int numPixels, double x, double y, double dx, double dy, double lineWidth);
};

