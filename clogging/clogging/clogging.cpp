// clogging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"
																			   
int main()
{	
	INIT_CLOGGING;
	CLOGGING_TIMER;

	//ADD_FILE("something.log");
	ADD_FILE("clogging.log");

	std::string msg = "hello world!";
	//CLOG(msg, Verbosity::WARN, Output::BOTH);
	std::cout << msg;	

	CLOG_T("timer1", Timer_t::START);
	CLOG_T("timer2", Timer_t::START);

	for (size_t i = 0; i < 2; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		CLOG(msg, Verbosity::WARN, Output::DEFAULT);
		CLOG_VS(msg, Verbosity::INFO);
		
	}

	CLOG_T("timer1", Timer_t::END);
	for (size_t i = 0; i < 2; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}
	CLOG_T("timer2", Timer_t::END);

	//CLOG_VS(msg, Verbosity::EMERG, Output_vs::TO_FILE_BOTH);
	

	return 0;
}

