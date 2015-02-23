/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/
#ifndef STATE_HEADER
#define STATE_HEADER 

#include "StdAfx.h"
#include "LinkedList.h"
#include "Transition.h"
#include "AI.h"

class Transition;

class State{
public:
	//Constructor/ Destructor/s
	State(AIStates State);
	State(AIStates State, CallBackFunctor CallBack, AI* Obj);
	~State(); 
	
	//Public Methods/ Members
	void addTransition(State* From, State* To, GuardFunctor Guard, AI* Obj);
	void invokeCallBack();
	State* checkGuards(bool* changed);

	//Operator Overloads 
	bool operator!=(State& rhd); 
	bool operator==(State& rhd); 

	//Attributes
	State* next;
	AIStates state;
	LinkedList<Transition>* transitions;

	CallBackFunctor callBack; 
	AI* obj;

private:
	State(){}
};

#endif