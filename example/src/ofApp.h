#pragma once


#include "ofMain.h"
#include "ofxTween2.h"


class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

       float length_float;

       ofxTween2 tweenback;
       ofxTween2 tweenbounce;
       ofxTween2 tweencirc;
       ofxTween2 tweencubic;
       ofxTween2 tweenelastic;
       ofxTween2 tweenexpo;
       ofxTween2 tweenlinear;
       ofxTween2 tweenquad;
       ofxTween2 tweenquart;
       ofxTween2 tweenquint;
       ofxTween2 tweensine;

       ofxTween2 multitween;

};
