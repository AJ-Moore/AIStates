/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef TRANSITION_HEADER
#define TRANSITION_HEADER

#include "State.h"

class State; 

class Transition{
public:
	//Constructors/ Destructors 
	Transition(State* From, State* To, GuardFunctor GuardFunction, AI* Object);
	~Transition();

	State* getToState(); 
	bool invokeGuard(); 
	Transition* next;
private:
	Transition(){}

	State* fromState;
	State* toState; 
	
	GuardFunctor guardFunction; 
	AI* guardObject; 

};

#endif