#include "ofxTween2.h"

ofxTween2::ofxTween2(){
	duration = 0;
	completed = true;
	running = false;
	delaying = false;
	id = -1;
}

ofxTween2::ofxTween2(const ofxTween2 &other)
: id(other.id),
end_E(other.end_E),
from(other.from),
to(other.to),
pTarget(other.pTarget),
startTime(other.startTime),
delay(other.delay),
duration(other.duration),
running(other.running),
completed(other.completed){
	easing = other.easing;
}

ofxTween2 ofxTween2::operator=(const ofxTween2 &other)
{
	id = other.id;
	end_E = other.end_E;
	from = other.from;
	to = other.to;
	pTarget = other.pTarget;
	startTime = other.startTime;
	delay = other.delay;
	duration = other.duration;
	running = other.running;
	completed = other.completed;
	easing = other.easing;
	return *this;
}

ofxTween2::ofxTween2(int id, std::function<float(float,float,float,float)> easing, float from, float to,  unsigned duration, unsigned delay) {
	setParameters(id, easing, from,to,duration,delay);
}

ofxTween2::~ofxTween2() {
}

void ofxTween2::setParameters( std::function<float(float,float,float,float)> easing, float from, float to,  unsigned duration, unsigned delay){
	setParameters(id, easing,from,to,duration,delay);
}

void ofxTween2::setParameters(int id, std::function<float(float,float,float,float)> easing, float from, float to,  unsigned duration, unsigned delay){
	this->from.clear();
	this->to.clear();
	pTarget.clear();
	
	this->id 		= id;
	this->easing 	= easing;
	
	addValue(from,to);
	this->duration = duration;
	this->delay = delay;
	
	start();
}

void ofxTween2::addValue(float _from, float _to){
	from.push_back(_from);
	to.push_back(_to);
	pTarget.push_back(_from);
}

void ofxTween2::start(){
	startTime = ofGetElapsedTimeMillis()+delay;
	completed = false;
	running = false;
	delaying = delay != 0;
}

void ofxTween2::setDuration(unsigned _duration) {
	duration = _duration;
}

unsigned ofxTween2::getDuration() {
	return duration;
}

float ofxTween2::getTarget(unsigned pos) {
	if(pTarget.size()>pos)
		return pTarget[pos];
	else
		return 0;
}

bool ofxTween2::isRunning() {
	return running;
}

bool ofxTween2::isCompleted() {
	return completed;
}
bool ofxTween2::isDelaying(){
	return delaying;
}
float ofxTween2::update() {
	if (!completed) {
		uint64_t currentTime = ofGetElapsedTimeMillis();
		if (currentTime >= startTime+duration) {
			for (unsigned i=0; i<from.size(); i++) {
				pTarget[i] = to[i];
			}
			running = false;
			completed = true;
			ofNotifyEvent(end_E,id);
		} else if (currentTime>=startTime) {
			for (unsigned i=0; i<from.size(); i++) {
				pTarget[i]= ofxeasing::map(currentTime, startTime, startTime+duration, from[i], to[i], easing);
			}
			if(!running){
				ofNotifyEvent(begin_E, id);
				delaying = false;
				running = true;
			}
		}
	}
	return getTarget(0);
}

