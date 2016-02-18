#pragma once

#include "ofMain.h"

#include "ofxDmx.h"
#include "ofxJSON.h"
#include "ofxSpacebroClient.h"

class ofApp : public ofBaseApp{

public:
  void setup();
  void update();
  void draw();

  std::string configFile;
  ofxJSONElement config;

  ofxDmx dmx;

  ofxSpacebroClient spacebroClient;
  ofEvent<ofxSocketIOData&> DMXData;

  void onDMXData(ofxSocketIOData& data);
};
