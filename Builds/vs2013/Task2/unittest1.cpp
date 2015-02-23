#include "stdafx.h"
#include "CppUnitTest.h"

#include <AI.h>
#include <FSM.h>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		//Test that the AI Starting State is Idle
		TEST_METHOD(StartState)
		{
			AI ai(false, 0, 0);
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Idle);
			
		}

		//Check Idle to Observe Transition.
		TEST_METHOD(IdleToObserve)
		{
			//create the AI -> Sets Can See Player to true
			AI ai(true, 0, 0);

			//check that the current state is in idle 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Idle);
			//check after the update that the state has changed to Observe 
			ai.update();
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Observe);
		}

		//Checks the transition between the Observe and Idle states. 
		TEST_METHOD(ObserveToIdle)
		{
			AI ai(true, 0, 0);
			ai.update(); 
			ai.canSeePlayer = false; 
			ai.update(); 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Idle);
			
		}

		//Observe to Combat Test 
		TEST_METHOD(ObserveToCombat){
			AI ai(true, 70, 0);
			ai.update();//state should now be observe. 
			ai.update();//state should still be observe. 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Observe);
			//change health to 71 and ammo to 1 
			ai.health = 71; 
			ai.ammunition = 1; 
			ai.update();//state should now be combat 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Combat);
		}

		//Combat to Retreat Test.
		TEST_METHOD(CombatToRetreat){
			AI ai(true, 71, 1);
			ai.update();//state should now be observe. 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Observe);
			ai.update();//state should now be combat
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Combat);
			ai.ammunition = 0; 
			ai.update(); 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Retreat);
		}

		//Combat to Retreat Test.
		TEST_METHOD(CombatToDead){
			AI ai(true, 71, 1);
			ai.update();//state should now be observe. 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Observe);
			ai.update();//state should now be combat
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Combat);
			ai.health = 0;
			ai.update();
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Dead);
		}

		//Combat to Retreat Test.
		TEST_METHOD(RetreatToDead){
			AI ai(true, 71, 1);
			ai.update();//state should now be observe. 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Observe);
			ai.update();//state should now be combat
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Combat);
			ai.ammunition = 0;
			ai.update();
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Retreat);
			ai.health = 0; 
			ai.update();
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Dead);
		}

		TEST_METHOD(RetreatToIdle){
			AI ai(true, 71, 1);
			ai.update();//state should now be observe. 
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Observe);
			ai.update();//state should now be combat
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Combat);
			ai.ammunition = 0;
			ai.update();
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Retreat);
			ai.canSeePlayer = false;
			ai.update();
			Assert::AreEqual((int)ai.fsm->getCurrentState()->state, (int)AIStates::Idle);
		}

	};
}