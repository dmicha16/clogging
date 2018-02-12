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

#define EMERG "EMERGENCY"
#define ALERT "ALERT"
#define CRIT "CRITICAL"
#define ERR "ERROR"
#define WARNING "WARNING"
#define NOTICE "NOTICE"
#define INFO "INFO"
#define DEBUG "DEBUG"

#define LOG 1
#define JSON 2

#define INIT_CLOGGING clogging::Logger ToLog

//#define ADD_FILE(file_name, path)  ToLog.AddFile(file_name, path);
#define ADD_FILE(file_name)		   ToLog.AddFile(file_name)

#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define CLOG(...) GET_MACRO(__VA_ARGS__, CLOG3, CLOG2, CLOG1)(__VA_ARGS__)

#define CLOG3(output_msg, level, type) ToLog.Clog(output_msg, level, type)
#define CLOG2(output_msg, level) ToLog.Clog(output_msg, level)
#define CLOG1(output_msg) ToLog.Clog(output_msg)
//#define CLOG() ToLog.Clog()

using namespace std;

namespace clogging {	
	
	class Logger {
	private:
		char *CurrentTimeStamp();
		string global_file_name_;

		void TXTSyntax(string level, string output_msg);
		void JSONSyntax(string level, string output_msg);
				
	public:

		void AddFile(string file_name);
		//void AddFile(string file_name, string path);

		void Clog(string output_msg, string level, int specify_type);
		void Clog(string output_msg, string level);
		void Clog(string output_msg);
		void Clog();		

		Logger();
		~Logger();
	};
}



