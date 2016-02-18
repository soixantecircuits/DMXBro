#pragma once

#include "ofMain.h"
#include "ofxDmx.h"
#include "ofxJSON.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
  void setup();
  void update();
  void draw();

  std::string configFile;
  ofxJSONElement config;

  ofxDmx dmx;

  ofxPanel panel;
  ofParameter<bool> event1;
  int eventTimeout;
};
