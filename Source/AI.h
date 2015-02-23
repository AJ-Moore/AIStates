/*
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef AI_HEADER 
#define AI_HEADER 

#include "StdAfx.h"

class FSM;


class AI{
public:
	AI(bool CanSeePlayer, int Health, int Ammunition);
	~AI(); 

	void update(); 

	bool guardCombatToDead(); 
	bool guardCombatToRetreat(); 
	bool guardIdleToObserve(); 
	bool guardObserveToCombat(); 
	bool guardObserveToIdle(); 
	bool guardRetreatToDead(); 
	bool guardRetreatToIdle(); 

	void onCombat();
	void onDead(); 
	void onIdle();
	void onObserve(); 
	void onRetreat(); 

	FSM* fsm;
	int ammunition; 
	int health; 
	bool canSeePlayer; 

};

#endif 