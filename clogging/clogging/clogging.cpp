// clogging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"
																			   
int main()
{	
	INIT_CLOGGING;

	//ADD_FILE("something.log");
	ADD_FILE("clogging.log", "C:\\photos\\");

	string msg = "hello world!";
	//CLOG(msg, Verbosity::WARN, Output::BOTH);

	CLOG_VS(msg, Verbosity::EMERG, Output_vs::TO_FILE_BOTH);
	

	return 0;
}

