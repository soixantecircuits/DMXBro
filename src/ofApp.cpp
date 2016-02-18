#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  configFile = "config.json";
  bool parsingSuccessful = config.open(configFile);
  if (parsingSuccessful) {
    dmx.connect(config["serialPort"].asString());
  } else {
    ofLogError("DMXBro", "Unable to open " + configFile);
    std::exit(0);
  }

  event1.set("event1", false);
  panel.setName("events");
  panel.setup();
  panel.add(event1);

  eventTimeout = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
  if (event1) {
    if (eventTimeout == 0) {
      eventTimeout = ofGetElapsedTimeMillis();
    }
    dmx.setLevel(1, 122);
    dmx.setLevel(2, 122);
    if (ofGetElapsedTimeMillis() - eventTimeout > 500) {
      event1 = false;
      eventTimeout = 0;
    }
  } else {
    dmx.setLevel(1, 10);
    dmx.setLevel(2, 10);
  }
  dmx.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  panel.draw();
}
