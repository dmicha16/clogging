// clogging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"
																			   
int main()
{	
	INIT_CLOGGING;

	//ADD_FILE("someth12ing132.log");
	ADD_FILE2("someth12ing132.log", "C:\\Users\\davic\\Documents\\");
	
	CLOG("message", Verbosity::CRIT, Output::BOTH);                   
	
	return 0;
}

