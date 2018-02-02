#include "stdafx.h"
#include "Logger.h"
#pragma warning(disable : 4996)

namespace clogging {

	Logger::Logger() {
		
		CreateLogFile();
	}	
	
	bool Logger::CreateLogFile() {		

		ifstream log_file(GLOBAL_LOG_NAME);

		if (!log_file) {			
			ofstream log_file_create;
			log_file_create.open(GLOBAL_LOG_NAME);
			log_file_create.close();
			return true;
		}
		log_file.close();
		return false;
	}
	
	void Logger::Clog(int output_msg, string level, int specify_type) {
		
		string output_to_string = to_string(output_msg);

		switch (specify_type) {
			case 1:
				TXTSyntax(level, output_to_string);
				break;
			case 2:
				JSONSyntax(level, output_to_string);
				break;			
			default:
				TXTSyntax(level, output_to_string);
				break;
		}
	}	
	
	bool Logger::TXTSyntax(string level, string output_msg) {

		char *current_time = CurrentTimeStamp();

		ifstream log_file(GLOBAL_LOG_NAME);

		if (!log_file) {
			CreateLogFile();
		}

		log_file.close();

		ofstream log_file_out(GLOBAL_LOG_NAME, ios::app);
		log_file_out << "[" << current_time << "] [" << level << "] " << output_msg << "\n";
		log_file_out.close();
		return true;
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
