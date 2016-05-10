#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  configFile = "config.json";
  bool parsingSuccessful = config.open(configFile);
  if (parsingSuccessful) {
    dmx.connect(config["serialPort"].asString(), config["maxChannel"].asInt());
  } else {
    ofLogError("DMXBro", "Unable to open " + configFile);
    std::exit(0);
  }

  spacebroClient.setup("DMXBro");
  ofAddListener(spacebroClient.registerEvent("DMX-data"), this, &ofApp::onDMXData);
}

//--------------------------------------------------------------
void ofApp::onDMXData (ofxSocketIOData& data) {
  ofLogNotice("Got DMX data - channel", ofToString(data.getIntValue("channel")));
  ofLogNotice("Got DMX data - level", ofToString(data.getIntValue("level")));
  int channel = data.getIntValue("channel");
  int level = data.getIntValue("level");
  dmx.setLevel(channel, level);
}

//--------------------------------------------------------------
void ofApp::update(){
  dmx.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
}
