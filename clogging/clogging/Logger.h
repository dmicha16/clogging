#pragma once

#include <time.h>
#include <string>
#include <string.h>
#include <ctime>
#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "json.hpp"

#define INIT_CLOGGING clogging::Logger ToLog

#define GET_MACRO(_1,_2, _3, NAME,...) NAME

#define ADD_FILE(...) GET_MACRO(__VA_ARGS__, ADD_FILE3, ADD_FILE2, ADD_FILE1)(__VA_ARGS__)
#define CLOG(...) GET_MACRO(__VA_ARGS__, CLOG3, CLOG2, CLOG1)(__VA_ARGS__)

#define ADD_FILE3(file_name, path, future_param)
#define ADD_FILE2(file_name, path) ToLog.AddFile(file_name, path)
#define ADD_FILE1(file_name) ToLog.AddFile(file_name)

#define CLOG3(output_msg, level, type) ToLog.Clog(output_msg, level, type)
#define CLOG2(output_msg, level) ToLog.Clog(output_msg, level)
#define CLOG1(output_msg) ToLog.Clog(output_msg)
//#define CLOG() ToLog.Clog()

enum Output {DEFAULT, JSON, BOTH};
enum Verbosity {DEBUG, INFO, NOTICE, WARNING, ERROR, CRIT, ALERT, EMERGENCY};

using namespace std;

namespace clogging {	
	
	class Logger {
	private:
		char *CurrentTimeStamp();
		string global_file_name_;

		void TXTSyntax(Verbosity level, string output_msg);
		void JSONSyntax(Verbosity level, string output_msg);
		string EnumStringValue(Verbosity level);
				
	public:

		void AddFile(string file_name, string path);
		void AddFile(string file_name);	

		void Clog(string output_msg, Verbosity level, Output specify_type);
		void Clog(string output_msg, Verbosity level);
		void Clog(string output_msg);
		void Clog();		

		Logger();
		~Logger();
	};
}



