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

#define GLOBAL_LOG_NAME "clogging.log"

#define INIT_CLOGGING clogging::Logger ToLog
#define CLOG(message, level, type) ToLog.Clog(message, level, type)
#define CLOG(message, level)       ToLog.Clog(message, level)
#define CLOG(message)			   ToLog.Clog(message)

using namespace std;

namespace clogging {	
	
	class Logger {
	private:
		char *CurrentTimeStamp();
		const char *global_file_name_;

	public:				

		bool CreateLogFile();

		void Clog(string output_msg, string level, int specify_type);
		void Clog(string output_msg, string level);
		void Clog(string output_msg);

		bool TXTSyntax(string level, string output_msg);				
		bool JSONSyntax(string level, string output_msg);

		Logger();
		~Logger();
	};
}



