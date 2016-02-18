#pragma once

#include "ofMain.h"
#include "ofxDmx.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

public:
  void setup();
  void update();
  void draw();

  std::string configFile;
  ofxJSONElement config;

  ofxDmx dmx;
};
