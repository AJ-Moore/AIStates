/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#include "StdAfx.h"
#include "FSM.h"
#include "AI.h"

FSM::FSM(){
	this->states = new LinkedList<State>();
	this->currentState = nullptr; 
}

FSM::~FSM(){
	if (this->states != nullptr){delete this->states; this->states = nullptr;}
}

void FSM::check(){
	if (this->currentState != nullptr){
		bool changed = false; 
	
		State* toState = this->currentState->checkGuards(&changed);

		//if guard is met 
		if (changed){
			this->currentState = toState; 
			this->currentState->invokeCallBack();

		}
	}

}

bool FSM::addState(State* State){
	//First state added becomes the current state 
	if (this->states->isEmpty()){
		this->currentState = State;
		this->currentState->invokeCallBack();
		this->states->insert(State);
		return true;
	}
	else{
		//If the state hasn't already been added, insert state
		if (!this->states->find(State)){
			states->insert(State); 
			return true;
		}
		else{
			std::cout<<"The state has already been added!"<<std::endl; 
			return false; 
		}
	}

	///shouldn't ever be hit...
	return false;
}

///well then :/
bool FSM::addTransition(AIStates From, AIStates To, GuardFunctor GuardFunction, AI* Object){
	
	//Create states to see if they already exist
	State* FromState = new State(From);
	State* ToState = new State(To);
	//Check states haves been added.
	State* FState = states->find(FromState);
	State* TState = states->find(ToState);

	if (FState != nullptr && TState != nullptr){
		//Add new transition.
		FState->addTransition(FState,TState, GuardFunction, Object);
		delete FromState; FromState = nullptr; 
		delete ToState; ToState = nullptr; 
		return true;
	}
	else{
		if (FromState != nullptr){delete FromState; FromState = nullptr;}
		if (ToState != nullptr){delete ToState; ToState = nullptr;}
		std::cout<<"Error: Invalid Transition: State/s missing?"<<std::endl;
		return false; 
	}
	return false;

	
}

///Returns the current state.
State* FSM::getCurrentState(){
	return this->currentState;
}
	