#pragma once

#include "ofxEasing.h"
#include "ofMain.h"

class ofxTween2{
    
public:
    
    ///\brief Default Constructor
    ofxTween2();
    ///\brief Destructor
    ~ofxTween2() = default;
    ///\brief Constructor
    ///\param id [ int ]: The id of this ease. It is usefull when you use the same end event callback function, so you can tell which tween ended.
    ///\param easing [ std::function<float(float,float,float, float)> ] : Easing function taken from ofxEasing.
    ///\param from [ float ] : Strarting value of the tween
    ///\param to [ float ] : Ending value of the tween
    ///\param duration [ unsigned ] : Duration of the tween
    ///\param delay [ unsigned ] : Time taken until the tween starts.
    
    ofxTween2(int id, std::function<float(float,float,float,float)> easing, float from, float to, unsigned duration, unsigned delay);
    
    ///\brief copy constructor
    ofxTween2(const ofxTween2 &other);
    ///\brief copy constructor assigment operator
    ofxTween2 operator=(const ofxTween2 &other);
    
    
    ///\brief set the parameters of the tween. Tweening will start once you call this function
    ///\param id [ int ]: The id of this ease. It is usefull when you use the same end event callback function, so you can tell which tween ended.
    ///\param easing [ std::function<float(float,float,float, float)> ] : Easing function taken from ofxEasing.
    ///\param from [ float ] : Strarting value of the tween
    ///\param to [ float ] : Ending value of the tween
    ///\param duration [ unsigned ] : Duration of the tween
    ///\param delay [ unsigned ] : Time taken until the tween starts.
    void setParameters(int id, std::function<float(float,float,float,float)> easing, float from, float to,  unsigned duration, unsigned delay);
    void setParameters( std::function<float(float,float,float,float)> easing,  float from, float to,  unsigned duration, unsigned delay);
    
    
    ///\brief add another value pair to tween. You retrieve the tweeen value of this with getTarget
    ///\param from [ float ] : Strarting value of the tween
    ///\param to [ float ] : Ending value of the tween
    void addValue(float from, float to);
    
    ///\brief start the tween. this gets called automatically when you call setParameters
    void start();
    ///\brief stop the tween. Only use this if you need to stop while it is running.
    void stop();
    
    ///\brief calculates and applies a new value to the target.
    ///\returns the calculated target value
    float update();
    
    
    ///\brief get the target value when you add more targets using addValue(...)
    float getTarget(unsigned pos);
    
    ///\brief get the tween's duration
    ///\returns unsigned value. The duration in milliseconds .
    unsigned getDuration();
    
    ///\brief set the tween's duration
    ///\param duration [ unsigned ] The new duration in milliseconds .
    void setDuration(unsigned duration);
    
    
    
    ///\brief check if the tween has started.
    ///\returns true if the value is either tweening or still on the delay phase. Otherwise returns false.
    bool isRunning();
    ///\brief check if the tween has started and it is on the delay phase.
    ///\returns true if the value is on the delay phase. Otherwise returns false.
    bool isDelaying();
    ///\brief check if the tween has been completed
    ///\returns true if tween has completed. Otherwise returns false.
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
    
protected:
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

