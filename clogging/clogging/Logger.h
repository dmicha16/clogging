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
#include <sstream>

#include <chrono>
#include <thread>

// Uncomment any of these macros for more logging and debugging options.
	// To use Windows.h and OutputDebugString in any Visual Studio version.
#define CLOG_USE_VS 1 

//------------

#ifdef CLOG_USE_VS 1
	#include <Windows.h>
	#define CLOG_VS(output_msg) ToLog.ClogVS(output_msg)
#endif // CLOG_USE_VS 1

//Init clogging macro:

#define INIT_CLOGGING clogging::Logger ToLog

//Macro overloading:

#define GET_MACRO(_1,_2, _3, NAME,...) NAME

#define ADD_FILE(...) GET_MACRO(__VA_ARGS__, ADD_FILE3, ADD_FILE2, ADD_FILE1)(__VA_ARGS__)
#define CLOG(...) GET_MACRO(__VA_ARGS__, CLOG3, CLOG2, CLOG1)(__VA_ARGS__)
#define CLOG_VS(...) GET_MACRO(__VA_ARGS__, CLOG_VS3, CLOG_VS2, CLOG_VS1)(__VA_ARGS__)

#define CLOG_VS3(output_msg, level, type) ToLog.ClogVS(output_msg, level, type)
#define CLOG_VS2(output_msg, level) ToLog.ClogVS(output_msg, level)
#define CLOG_VS1(output_msg) ToLog.ClogVS(output_msg)

#define ADD_FILE3(file_name, path, future_param)
#define ADD_FILE2(file_name, path) ToLog.AddFile(file_name, path)
#define ADD_FILE1(file_name) ToLog.AddFile(file_name)

#define CLOG3(output_msg, level, type) ToLog.Clog(output_msg, level, type)
#define CLOG2(output_msg, level) ToLog.Clog(output_msg, level)
#define CLOG1(output_msg) ToLog.Clog(output_msg)
//#define CLOG() ToLog.Clog()

enum Output {DEFAULT, JSON, BOTH};
enum Output_vs {DEBUG_ONLY, TO_FILE_JSON, TO_FILE_DEF, TO_FILE_BOTH};
enum Verbosity {DEBUG, INFO, NOTICE, WARN, ERR, CRIT, ALERT, EMERG};

using namespace std;

namespace clogging {	
	
	class Logger {
	private:
		string global_file_name_;
		chrono::steady_clock::time_point global_init_timestamp_;

		char *CurrentTimeStamp();
		double EpochSeconds(chrono::steady_clock::time_point global_init_timestamp_);

		void TXTSyntax(Verbosity level, string output_msg);
		void JSONSyntax(Verbosity level, string output_msg);
		string EnumStringValue(Verbosity level);
				
	public:

		void AddFile(string file_name, string path);
		void AddFile(string file_name);

		void ClogVS(string output_msg, Verbosity level, Output_vs specify_type);
		void ClogVS(string output_msg, Verbosity level);
		void ClogVS(string output_msg);

		void Clog(string output_msg, Verbosity level, Output specify_type);
		void Clog(string output_msg, Verbosity level);
		void Clog(string output_msg);
		void Clog();		

		Logger();
		~Logger();
	};
}



