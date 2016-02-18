#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  configFile = "config.json";
  bool parsingSuccessful = config.open(configFile);
  if (parsingSuccessful) {
    dmx.connect(config["serialPort"].asString());
  } else {
    ofLogNotice("DMXBro", "Unable to open " + configFile);
  }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}
