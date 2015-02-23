/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#include "StdAfx.h"
#include "Transition.h"

Transition::Transition(State* From, State* To, GuardFunctor GuardFunction, AI* Object){
	this->fromState = From; 
	this->toState = To;
	this->guardFunction = GuardFunction;
	this->guardObject = Object;
}

Transition::~Transition(){

}

State* Transition::getToState(){
	return this->toState;
}

bool Transition::invokeGuard(){
	if (this->guardObject != nullptr && this->guardFunction != nullptr){
		return (this->guardObject->*this->guardFunction)();
	}
	return false;
}