// clogging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"
																			   
int main()
{	
	INIT_CLOGGING;

	//ADD_FILE("something.log");
	ADD_FILE("clogging.log", "C:\\clogging\\");

	string msg = "hello world!";
	//CLOG(msg, Verbosity::WARN, Output::BOTH);

	for (size_t i = 0; i < 15; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		CLOG(msg, Verbosity::WARN, Output::DEFAULT);
		CLOG_VS(msg, Verbosity::INFO);
		
	}

	//CLOG_VS(msg, Verbosity::EMERG, Output_vs::TO_FILE_BOTH);
	

	return 0;
}

