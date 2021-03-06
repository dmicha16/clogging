// clogging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"
																			   
int main()
{	
	INIT_CLOGGING;
	CLOGGING_TIMER;

	//ADD_FILE("something.log");
	//ADD_FILE("clogging.log");
	ADD_FILE("clogging.csv");

	std::string msg = "hello world!";
	//CLOG(msg, Verbosity::WARN, Output::BOTH);
	std::string msg2 = "appended";

	CLOG_T("timer1", Timer_t::START);
	CLOG_T("timer2", Timer_t::START);

	CLOG(msg, Verbosity::WARN, Output::CSV);
	CLOG(msg2, Verbosity::WARN, Output::CSV_A);

	CLOG_T("timer1", Timer_t::END);
	for (size_t i = 0; i < 2; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}
	CLOG_T("timer2", Timer_t::END);

	//CLOG_VS(msg, Verbosity::EMERG, Output_vs::TO_FILE_BOTH);
	

	return 0;
}

