/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef FSM_HEADER 
#define FSM_HEADER 

#include "StdAfx.h"
#include "AI.h"
#include "State.h"

class State;

class FSM{
public:
	FSM();
	~FSM(); 

	void check(); 
	
	bool addState(State* state); 
	bool addTransition(AIStates From, AIStates To, GuardFunctor GuardFunction, AI* Object);

	State* getCurrentState(); 
	
private:
	State* currentState; 
	LinkedList<State>* states; 

};

#endif 