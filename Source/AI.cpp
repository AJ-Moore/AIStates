/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#include "StdAfx.h"
#include "AI.h"
#include "FSM.h"

///Consturctor /Destructor /s 
AI::AI(bool CanSeePlayer, int Health, int Ammunition){
	this->health = Health; 
	this->canSeePlayer = CanSeePlayer; 
	this->ammunition = Ammunition;
	
	this->fsm = new FSM(); 

	//Add States
	fsm->addState(new State(Idle,&AI::onIdle,this));//Start State
	fsm->addState(new State(Combat,&AI::onCombat,this));
	fsm->addState(new State(Dead,&AI::onDead,this));
	fsm->addState(new State(Observe,&AI::onObserve,this));
	fsm->addState(new State(Retreat,&AI::onRetreat,this));

	fsm->addTransition(Combat,Dead,&AI::guardCombatToDead,this);
	fsm->addTransition(Combat,Retreat,&AI::guardCombatToRetreat,this); 
	fsm->addTransition(Idle,Observe,&AI::guardIdleToObserve,this); 
	fsm->addTransition(Observe,Combat,&AI::guardObserveToCombat,this); 
	fsm->addTransition(Observe,Idle,&AI::guardRetreatToIdle,this); 
	fsm->addTransition(Retreat,Dead,&AI::guardRetreatToDead,this); 
	fsm->addTransition(Retreat,Idle,&AI::guardRetreatToIdle,this); 

}

AI::~AI(){
	if (this->fsm != nullptr){delete this->fsm; this->fsm = nullptr;}
}

///Update the AI
void AI::update(){
	if (this->fsm != nullptr)
		this->fsm->check();

}


/* GUARD FUNCTIONS  */
bool AI::guardCombatToDead(){
	return (this->health <= 0);
}

bool AI::guardCombatToRetreat(){
	return (this->ammunition <= 0);
}

bool AI::guardIdleToObserve(){
	return (this->canSeePlayer);
}

bool AI::guardObserveToCombat(){
	return (this->health > 70 && this->ammunition >0);
}

bool AI::guardObserveToIdle(){
	return (!this->canSeePlayer);
}

bool AI::guardRetreatToDead(){
	return (this->health <= 0);
}

bool AI::guardRetreatToIdle(){
	return (!this->canSeePlayer);
}

/*   CALLBACKS   */
void AI::onCombat(){
	std::cout<<"onCombat"<<std::endl;
}

void AI::onDead(){
	std::cout<<"onDead"<<std::endl; 
}

void AI::onIdle(){
	std::cout<<"onIdle"<<std::endl;
}

void AI::onObserve(){
	std::cout<<"onObserve"<<std::endl;
}

void AI::onRetreat(){
	std::cout<<"onRetreat"<<std::endl;
}