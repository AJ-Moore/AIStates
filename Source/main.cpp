/*
	Main Entry Point for Application
	Dev By Allan Moore 22/01/2014
	21017984
	Buckinghamshire New University 
*/

//precompiled header 
#include "StdAfx.h"

#include <Windows.h>

#include "AI.h"

int main(){
	
	//Change the console text colour... 
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute(hstdout, 2);

	//Create AI Object.
	AI* ai = new AI(true,100,20);
	ai->update();
	ai->update();
	ai->ammunition = 0; 
	ai->update(); 
	ai->health = 0; 
	ai->update(); 
	
	//Clean up memory 
	delete ai;

	system("PAUSE");
}