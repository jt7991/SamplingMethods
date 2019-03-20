#include "ofApp.h"
#include "of3dGraphics.h"
#include "ofApp.h"
#include "../Sampling.h"
#include "ofxGui/src/ofxGui.h"
ofxButton drawImageBtn, randomSamplingBtn, jitteredSamplingBtn;
double minX, maxX, minY, maxY;
ofImage img;
ofxPanel gui;
ofxFloatSlider lineWidth;
Sampling sampling;
//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.add(lineWidth.setup("Line Width", .9, .01, 2));
	gui.add(randomSamplingBtn.setup("Random Sampling"));
	gui.add(jitteredSamplingBtn.setup("Jittered Sampling"));
	randomSamplingBtn.addListener(this, &ofApp::drawImageWithRandomSampling);
	jitteredSamplingBtn.addListener(this, &ofApp::drawImageWithJitteredSampling);
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	img.draw(0, 0);
	gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::drawImageWithRandomSampling() {
	minX = 0;
	maxX = 500;
	minY = 0;
	maxY = 500;
	ofClear(ofColor(0));
	img.clear();
	img.allocate(500, 500, OF_IMAGE_COLOR);
	img = sampling.startRandomSampling(minX, maxX, minY, maxY, img, lineWidth,50000);

}
void ofApp::drawImageWithJitteredSampling() {
	minX = 0;
	maxX = 500;
	minY = 0;
	maxY = 500;
	ofClear(ofColor(0));
	img.clear();
	img.allocate(500, 500, OF_IMAGE_COLOR);
	img = sampling.startJitteredSampling(minX, maxX, minY, maxY, img, lineWidth, 1000, 10);

}

