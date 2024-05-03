#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto numberOfActor = 700;
	auto len = 120;
	ofColor color;

	ofSeedRandom(39);
	for (int i = 0; i < numberOfActor; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));

		ofSetColor(239);
		for (int k = 0; k < len; k++) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, k * 0.001 + ofGetFrameNum() * 0.0025), 0, 1, -450, 450),
				ofMap(ofNoise(noise_seed.y, k * 0.001 + ofGetFrameNum() * 0.0025), 0, 1, -450, 450));

			ofDrawCircle(location, 12);
		}

		color.setHsb(ofRandom(255), 150, ofMap(i, 0, numberOfActor, 0, 255));
		ofSetColor(color);
		for (int k = 0; k < len; k++) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, k * 0.001 + ofGetFrameNum() * 0.0025), 0, 1, -450, 450),
				ofMap(ofNoise(noise_seed.y, k * 0.001 + ofGetFrameNum() * 0.0025), 0, 1, -450, 450));

			ofDrawCircle(location, 7);
		}
	}
	/*
	int start = 300;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}