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

#define INIT_CLOGGING clogging::Logger ToLog;

//#define ADD_FILE(file_name, path)  ToLog.AddFile(file_name, path);
#define ADD_FILE(file_name)		   ToLog.AddFile(file_name);

#define CLOG(message, level, type) ToLog.Clog(message, level, type);
#define CLOG(message, level)       ToLog.Clog(message, level);
#define CLOG(message)			   ToLog.Clog(message);
#define CLOG ToLog.Clog();

using namespace std;

namespace clogging {	
	
	class Logger {
	private:
		char *CurrentTimeStamp();
		string global_file_name_;
				
	public:

		void AddFile(string file_name);
		void AddFile(string file_name, string path);

		void Clog(string output_msg, string level, int specify_type);
		void Clog(string output_msg, string level);
		void Clog(string output_msg);
		void Clog();

		bool TXTSyntax(string level, string output_msg);				
		//bool JSONSyntax(string level, string output_msg);

		Logger();
		~Logger();
	};
}



