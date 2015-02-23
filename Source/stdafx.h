
#ifndef STDAFX
#define STDAFX

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>

///AI States.
enum AIStates{
	Idle,
	Observe,
	Combat,
	Dead,
	Retreat
};

class AI;
typedef  void (AI::*CallBackFunctor)();
typedef  bool (AI::*GuardFunctor)();

#endif