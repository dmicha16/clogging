#pragma once
#include "Timer.h"

// Uncomment any of these macros for more logging and debugging options.
	// To use Windows.h and OutputDebugString in any Visual Studio version.
#define CLOG_USE_VS 1

//------------

#ifdef CLOG_USE_VS 1
	#include <Windows.h>
	#define CLOG_VS(output_msg) Logger.ClogVS(output_msg)
#endif // CLOG_USE_VS 1

//Init clogging macro:

#define INIT_CLOGGING clogging::Logger Logger
#define CLOGGING_TIMER Timer TimerObj

//Macro overloading:

#define GET_MACRO(_1,_2, _3, NAME,...) NAME

#define ADD_FILE(...) GET_MACRO(__VA_ARGS__, ADD_FILE3, ADD_FILE2, ADD_FILE1)(__VA_ARGS__)
#define CLOG(...) GET_MACRO(__VA_ARGS__, CLOG3, CLOG2, CLOG1)(__VA_ARGS__)
#define CLOG_VS(...) GET_MACRO(__VA_ARGS__, CLOG_VS3, CLOG_VS2, CLOG_VS1)(__VA_ARGS__)

#define CLOG_VS3(output_msg, level, type) Logger.ClogVS(output_msg, level, type)
#define CLOG_VS2(output_msg, level) Logger.ClogVS(output_msg, level)
#define CLOG_VS1(output_msg) Logger.ClogVS(output_msg)

#define ADD_FILE3(file_name, path, extension)
#define ADD_FILE2(file_name, path) Logger.AddFile(file_name, path)
#define ADD_FILE1(file_name) Logger.AddFile(file_name)

#define CLOG3(output_msg, level, type) Logger.Clog(output_msg, level, type)
#define CLOG2(output_msg, level) Logger.Clog(output_msg, level)
#define CLOG1(output_msg) Logger.Clog(output_msg)

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

enum Output {DEFAULT, JSON, BOTH, CSV};
enum Output_vs {DEBUG_ONLY, TO_FILE_JSON, TO_FILE_DEF, TO_FILE_BOTH};
enum Verbosity {DEBUG, INFO, NOTICE, WARN, ERR, CRIT, ALERT, EMERG};
enum Extension {E_CSV};

namespace clogging {	
	
	class Logger {
	private:

		Timer TimerObj;
		std::string global_file_name_;
		timepoint_t global_init_timestamp_;

		void LineSyntax();
		void TXTSyntax(Verbosity level, std::string output_msg);
		void JSONSyntax(Verbosity level, std::string output_msg);
		void CSVSyntax(Verbosity level, std::string output_msg);
		void SystemInitOutput(std::string file_name, std::string path);
		void SystemInitOutput(std::string file_name);
		std::stringstream SystemInitOutputFormat();
		std::string EnumStringValue(Verbosity level);
				
	public:

		void AddFile(std::string file_name, std::string path, Extension file_extension);
		void AddFile(std::string file_name, std::string path);
		void AddFile(std::string file_name);

		void ClogVS(std::string output_msg, Verbosity level, Output_vs specify_type);
		void ClogVS(std::string output_msg, Verbosity level);
		void ClogVS(std::string output_msg);

		void Clog(std::string output_msg, Verbosity level, Output specify_type);
		void Clog(std::string output_msg, Verbosity level);
		void Clog(std::string output_msg);		

		Logger();
		~Logger();
	};	
}



