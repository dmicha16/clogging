// clogging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"
																			   
int main()
{	
	INIT_CLOGGING;

	//ADD_FILE("something.log");
	ADD_FILE2("custom.log", "C:\\photos\\");
	
	CLOG("message", Verbosity::CRIT, Output::DEFAULT);                   
	
	return 0;
}

