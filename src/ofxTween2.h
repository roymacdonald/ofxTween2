#pragma once

#include "ofxEasing.h"
#include "ofMain.h"

class ofxTween2{

	public:

		ofxTween2();
	
		ofxTween2(int id, std::function<float(float,float,float,float)> easing, float from, float to, unsigned duration, unsigned delay);
    
        // Mitchell Nordine 2/2/14
        // Added copy constructor to handle heap allocation (now much easier
        // to work on stack and copy classes that contain a tween object).
        ofxTween2(const ofxTween2 &other);
        ofxTween2 operator=(const ofxTween2 &other);

		void setParameters(int id, std::function<float(float,float,float,float)> easing, float from, float to,  unsigned duration, unsigned delay);
		void setParameters( std::function<float(float,float,float,float)> easing,  float from, float to,  unsigned duration, unsigned delay);

		void addValue(float from, float to);
		void start();

		~ofxTween2();

		float update();
		// calculates and applies a new value to the target

		float getTarget(unsigned pos);

		unsigned getDuration();
		void setDuration(unsigned duration);

		bool isRunning();
		bool isDelaying();
		bool isCompleted();

		int id;
		
	ofEvent<int> end_E;
	ofEvent<int> begin_E;//triggered when the tween starts after the delay 
	
	
	template<class ListenerClass, typename ListenerMethod>
	void addBeginListener(ListenerClass * listener, ListenerMethod method, int prio=OF_EVENT_ORDER_AFTER_APP){
		ofAddListener(begin_E,listener,method,prio);
	}
	template<class ListenerClass, typename ListenerMethod>
	void addEndListener(ListenerClass * listener, ListenerMethod method, int prio=OF_EVENT_ORDER_AFTER_APP){
		ofAddListener(end_E,listener,method,prio);
	}
	template<class ListenerClass, typename ListenerMethod>
	void removeBeginListener(ListenerClass * listener, ListenerMethod method, int prio=OF_EVENT_ORDER_AFTER_APP){
		ofRemoveListener(begin_E,listener,method,prio);
	}
	template<class ListenerClass, typename ListenerMethod>
	void removeEndListener(ListenerClass * listener, ListenerMethod method, int prio=OF_EVENT_ORDER_AFTER_APP){
		ofRemoveListener(end_E,listener,method,prio);
	}
	
	private:
		vector<float> from;
		vector<float> to;
		vector<float> pTarget;

		uint64_t startTime;

		unsigned delay;
		unsigned duration;

		bool running;
		bool completed;
		bool delaying;

		std::function<float(float,float,float,float)> easing;


};

