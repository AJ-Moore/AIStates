/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#include "StdAfx.h"
#include "AI.h"
#include "State.h"

State::State(AIStates State){
	this->state = State;
	this->transitions = nullptr; 
	this->next = nullptr;
	this->obj = nullptr; 
}

State::State(AIStates State, CallBackFunctor CallBack, AI* Obj){
	this->state = State; 
	this->obj = Obj; 
	this->callBack = CallBack;
	this->next = nullptr; 
	this->transitions = new LinkedList<Transition>();
}

State::~State(){
	if (this->transitions != nullptr){delete this->transitions;this->transitions = nullptr;}
}
	
//Public Methods/ Members
void State::addTransition(State* From, State* To, GuardFunctor Guard, AI* Obj){
	this->transitions->insert(new Transition(From,To,Guard,Obj));
}

void State::invokeCallBack(){
	if (this->obj != NULL){
		(this->obj->*this->callBack)();
	}
}

State* State::checkGuards(bool* changed){
	for (int iter = 0; iter < this->transitions->getSize(); iter++){
		if ((*this->transitions)[iter]->invokeGuard()){
			*changed = true; 
			return (*this->transitions)[iter]->getToState();
		}
	}
	return nullptr;
}

//Operator Overloads 
bool State::operator!=(State& rhd){
	return (this->state != rhd.state);
}

bool State::operator==(State& rhd){
	return (this->state == rhd.state);
}