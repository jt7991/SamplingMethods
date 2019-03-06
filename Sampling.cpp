#include "Sampling.h"
#include "of3dGraphics.h"
#include "ofImage.h"
#include <cstdlib>
Sampling::Sampling()
{
}


Sampling::~Sampling()
{
}

double Sampling::drawLines(int x, int y, double lineWidth) {
	int xlinePositions[5] = { 90,180,270,360,450 };
	int ylinePositions[5] = { 95,185,275,365,455 };
	if (std::find(std::begin(xlinePositions), std::end(xlinePositions), x) != std::end(xlinePositions) ||
		std::find(std::begin(xlinePositions), std::end(xlinePositions), x+1) != std::end(xlinePositions) ||
		std::find(std::begin(ylinePositions), std::end(ylinePositions), y) != std::end(ylinePositions) ||
		std::find(std::begin(ylinePositions), std::end(ylinePositions), y+1) != std::end(ylinePositions))
	{
		
		double r = ((double)rand() / (RAND_MAX)) ;
		
		if (r <= lineWidth / 2) {
			return 1;
		}
		else return 0;
	}
	else {
		return 0;
	}
}
double Sampling::drawLinesWithSampling(double x, double y, double lineWidth) {
	int xlinePositions[5] = { 90,180,270,360,450 };
	int ylinePositions[5] = { 95,185,275,365,455 };
	
	for (int i=0; i < 5; i++) {
		if ((x >= xlinePositions[i] + (1.0-lineWidth / 2) && x <= xlinePositions[i] + 1 + lineWidth / 2)||
			(y >= ylinePositions[i] + (1.0-lineWidth / 2) && y <= ylinePositions[i] + 1 + lineWidth / 2)) {
			return 1;
		}
	}
	return 0;
}
double Sampling::startRandomSampling(double numPixels, double x, double y, double lineWidth) {
	double darkness = 0;
	for (int i = 0; i < numPixels; i++) {
		double r = ((double)rand() / (RAND_MAX + 1));
		double sampleX = x + r ;
		r = ((double)rand() / (RAND_MAX + 1));
		double sampleY = y + r ;
		darkness += drawLinesWithSampling(sampleX, sampleY, lineWidth);
	}
	
	return (darkness / numPixels);
}

double Sampling::startJitteredSampling(double gridWidth,double x, double y, double lineWidth) {
	double darkness = 0;
	double dx = 1 / gridWidth;
	for (double i =0; i <= gridWidth; i+=dx) {
		for (double j = 0; j <= gridWidth; j += dx) {
			double r = ((double)rand() / (RAND_MAX + 1))/dx;
			double sampleX = x + r + j;
			r = ((double)rand() / (RAND_MAX + 1))/dx;
			double sampleY = y + r + i;
			darkness += drawLinesWithSampling(sampleX, sampleY, lineWidth);
		}
	}

	return (darkness / (gridWidth*gridWidth));
}
ofImage Sampling::calculatePixels(double minX, double maxX, double minY, double maxY,
	ofImage img, std::string samplingType, double lineWidth) {
	double pixelWidth = img.getWidth();
	double pixelHeight = img.getHeight();
	double dx = (maxX - minX) / pixelWidth;
	double dy = (maxY - minY) / pixelHeight;
	ofPixels& pixels = img.getPixels();

	for (double i = minY; i < maxY; i += dy) {
		for (double j = minX; j < maxX; j += dx) {
			double darkness;
			if (samplingType == "None") darkness = drawLines(j, i, lineWidth);
			else if (samplingType == "Random") darkness = startRandomSampling(16, j, i, lineWidth);
			else darkness = startJitteredSampling(4, j, i, lineWidth);
			ofColor color(darkness * 255);
			int pixelXVal = (j / maxX) * pixelWidth;
			int pixelYVal = (i / maxY) * pixelHeight;
			pixels.setColor(pixelXVal, pixelYVal, color);
		}
	}
	img.update();
	return img;
}