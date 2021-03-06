#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	unsigned delay = 2000;
	unsigned duration = 1000;
	tweenback.setParameters(1,ofxeasing::back::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenbounce.setParameters(2,ofxeasing::bounce::easeOut,0,ofGetWidth()-100,duration,delay);
    tweencirc.setParameters(3,ofxeasing::circ::easeOut,0,ofGetWidth()-100,duration,delay);
    tweencubic.setParameters(4,ofxeasing::cubic::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenelastic.setParameters(5,ofxeasing::elastic::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenexpo.setParameters(6,ofxeasing::exp::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenlinear.setParameters(7,ofxeasing::linear::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenquad.setParameters(8,ofxeasing::quad::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenquart.setParameters(9,ofxeasing::quart::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenquint.setParameters(10,ofxeasing::quint::easeOut,0,ofGetWidth()-100,duration,delay);
    tweensine.setParameters(10,ofxeasing::sine::easeOut,0,ofGetWidth()-100,duration,delay);

    // if you setup different tweens to control several parameters,
    // they don't end exactly at the same time
    // by adding values you get only 1 tween that controls several parameters
    // totally synchronized
    multitween.setParameters(ofxeasing::quart::easeInOut,0,ofGetWidth()-100,duration,delay);
    multitween.addValue(0,ofGetWidth()-120);
    multitween.addValue(0,ofGetWidth()-140);
    multitween.addValue(0,ofGetWidth()-160);
    multitween.addValue(0,ofGetWidth()-180);
    multitween.addValue(0,ofGetWidth()-200);
    multitween.start(); //dont forget to call start to sync all the tweens

    ofBackground(255,255,255);
	ofSetColor(0,0,0);
	ofNoFill();
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawRectangle(20,50,tweenback.update(),20);
	ofDrawRectangle(20,80,tweenbounce.update(),20);
	ofDrawRectangle(20,110,tweencirc.update(),20);
	ofDrawRectangle(20,140,tweencubic.update(),20);
	ofDrawRectangle(20,170,tweenelastic.update(),20);
	ofDrawRectangle(20,200,tweenexpo.update(),20);
	ofDrawRectangle(20,230,tweenlinear.update(),20);
	ofDrawRectangle(20,260,tweenquad.update(),20);
	ofDrawRectangle(20,290,tweenquart.update(),20);
	ofDrawRectangle(20,320,tweenquint.update(),20);
	ofDrawRectangle(20,350,tweensine.update(),20);

	// in sync multitween
	ofDrawRectangle(20,400,multitween.update(),20);
	ofDrawRectangle(20,430,multitween.getTarget(1),20);
	ofDrawRectangle(20,460,multitween.getTarget(2),20);
	ofDrawRectangle(20,490,multitween.getTarget(3),20);
	ofDrawRectangle(20,520,multitween.getTarget(4),20);
	ofDrawRectangle(20,550,multitween.getTarget(5),20);

	ofDrawBitmapString("back",30,65);
	ofDrawBitmapString("bounce",30,95);
	ofDrawBitmapString("circ",30,125);
	ofDrawBitmapString("cubic",30,155);
	ofDrawBitmapString("elastic",30,185);
	ofDrawBitmapString("expo",30,215);
	ofDrawBitmapString("linear",30,245);
	ofDrawBitmapString("quad",30,275);
	ofDrawBitmapString("quart",30,305);
	ofDrawBitmapString("quint",30,335);
	ofDrawBitmapString("sine",30,365);

	// in sync multitween
	ofDrawBitmapString("multitween",30,415);
	ofDrawBitmapString("multitween",30,445);
	ofDrawBitmapString("multitween",30,475);
	ofDrawBitmapString("multitween",30,505);
	ofDrawBitmapString("multitween",30,535);
	ofDrawBitmapString("multitween",30,565);
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	unsigned delay = 0;
	unsigned duration = 1000;
	tweenback.setParameters(1,ofxeasing::back::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenbounce.setParameters(2,ofxeasing::bounce::easeOut,0,ofGetWidth()-100,duration,delay);
	tweencirc.setParameters(3,ofxeasing::circ::easeOut,0,ofGetWidth()-100,duration,delay);
	tweencubic.setParameters(4,ofxeasing::cubic::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenelastic.setParameters(5,ofxeasing::elastic::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenexpo.setParameters(6,ofxeasing::exp::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenlinear.setParameters(7,ofxeasing::linear::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenquad.setParameters(8,ofxeasing::quad::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenquart.setParameters(9,ofxeasing::quart::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenquint.setParameters(10,ofxeasing::quint::easeOut,0,ofGetWidth()-100,duration,delay);
	tweensine.setParameters(10,ofxeasing::sine::easeOut,0,ofGetWidth()-100,duration,delay);

    multitween.setParameters(ofxeasing::quart::easeInOut,0,ofGetWidth()-100,duration,delay);
    multitween.addValue(0,ofGetWidth()-120);
    multitween.addValue(0,ofGetWidth()-140);
    multitween.addValue(0,ofGetWidth()-160);
    multitween.addValue(0,ofGetWidth()-180);
    multitween.addValue(0,ofGetWidth()-200);
    multitween.start(); //dont forget to call start to sync all the tweens
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

