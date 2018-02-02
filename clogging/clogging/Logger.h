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

#include "Macros.h"

using namespace std;

namespace clogging {	
	
	class Logger {
	private:
		char *CurrentTimeStamp();
		const char *global_file_name_;

	public:		
		bool CreateLogFile();								

		
		void Clog(int output_msg, string level, int specify_type);
		void Clog(string output_msg, string level, int specify_type);
		void Clog(double output_msg, string level, int specify_type);
		void Clog(float output_msg, string level, int specify_type);
		void Clog(char *output_msg, string level, int specify_type);
		void Clog(wchar_t *output_msg, string level, int specify_type);		
		
		bool TXTSyntax(string level, string output_msg);				
		bool JSONSyntax(string level, string output_msg);

		Logger();
		~Logger();
	};
}



