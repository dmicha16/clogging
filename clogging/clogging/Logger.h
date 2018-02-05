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

using namespace std;

namespace clogging {	
	
	class Logger {
	private:
		char *CurrentTimeStamp();
		const char *global_file_name_;

	public:		

		template<typename T>
		Logger & operator<<(T const & that) {
			stringstream stream << that;
			return *this;
		}

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



