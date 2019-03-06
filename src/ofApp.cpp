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
	gui.add(lineWidth.setup("Line Width", .9, .01, .99));
	gui.add(drawImageBtn.setup("No Sampling"));
	gui.add(randomSamplingBtn.setup("Random Sampling"));
	gui.add(jitteredSamplingBtn.setup("Jittered Sampling"));
	drawImageBtn.addListener(this, &ofApp::drawImage);
	randomSamplingBtn.addListener(this, &ofApp::drawImageWithRandomSampling);
	jitteredSamplingBtn.addListener(this, &ofApp::drawImageWithRandomSampling);
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
void ofApp::drawImage() {
	minX = 0;
	maxX = 511;
	minY = 0;
	maxY = 511;
	img.allocate(512, 512, OF_IMAGE_COLOR);
	img = sampling.calculatePixels(minX, maxX, minY, maxY, img, "None", lineWidth);

}
void ofApp::drawImageWithRandomSampling() {
	minX = 0;
	maxX = 511;
	minY = 0;
	maxY = 511;
	img.allocate(512, 512, OF_IMAGE_COLOR);
	img = sampling.calculatePixels(minX, maxX, minY, maxY, img, "Random", lineWidth);

}
void ofApp::drawImageWithJitteredSampling() {
	minX = 0;
	maxX = 511;
	minY = 0;
	maxY = 511;
	img.allocate(512, 512, OF_IMAGE_COLOR);
	img = sampling.calculatePixels(minX, maxX, minY, maxY, img, "Jittered", lineWidth);

}

