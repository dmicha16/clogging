#include "stdafx.h"
#include "Logger.h"
#pragma warning(disable : 4996)

namespace clogging {

	Logger::Logger() {
		string global_file_name_ = "clogging";
		CreateLogFile(global_file_name_);
	}	
	
	bool Logger::CreateLogFile(string global_file_name_) {

		string log_file_name = global_file_name_ + ".log";

		ifstream log_file(log_file_name);

		if (!log_file) {			
			ofstream log_file_create;
			log_file_create.open(log_file_name);
			log_file_create.close();
			return true;
		}
		log_file.close();
		return false;
	}

	template <typename T>
	void Logger::Clog(T output_msg, string level, int specify_type) {
		
		string output_to_string = output_msg;

		switch (specify_type) {
			case 1:
				bool TXTSyntax(level, output_to_string);
				break;
			case 2:
				bool JSONSyntax(level, output_to_string);
				break;			
			default:
				bool TXTSyntax(level, output_to_string);
				break;
		}
	}
	
	bool Logger::TXTSyntax(string level, string output_msg) {

		ifstream()

	}

	
	/*void Logger::Clog(const char* level, void* output_msg, const char *specify_type) {
		char *current_time = CurrentTimeStamp();						

		ofstream log_file;
		log_file.open(global_file_name_);
		log_file << current_time << " " << level << " " << output_msg << "\n";
		log_file.close();
	}*/
	
	char *Logger::CurrentTimeStamp() {

		time_t rawtime;
		struct tm * timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		char *current = asctime(timeinfo);
		current[strlen(current) - 1] = '\0';

		return current;
	}	
	Logger::~Logger() {
	}
}
