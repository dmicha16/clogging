#include "stdafx.h"
#include "Logger.h"
#pragma warning(disable : 4996)

namespace clogging {

	Logger::Logger() {		
		
	}	
	
	void Logger::AddFile(string file_name) {

		global_file_name_ = file_name;

		ifstream log_file(file_name);

		if (!log_file) {			
			ofstream log_file_create;
			log_file_create.open(file_name);
			log_file_create.close();			
		}
		log_file.close();		
	}

	/*void Logger::AddFile(string file_name, string path) {

		global_file_name_ = file_name;

		ifstream log_file(file_name);

		if (!log_file) {
			ofstream log_file_create(path);
			log_file_create.open(file_name);
			log_file_create.close();
		}
		log_file.close();
	}*/
	
	void Logger::Clog(string output_msg, string level, int specify_type) {		
		
		switch (specify_type) {
			case 1:
				TXTSyntax(level, output_msg);
				break;
			case 2:
				//JSONSyntax(level, output_msg);
				break;			
			default:
				TXTSyntax(level, output_msg);
				break;
		}
	}

	void Logger::Clog(string output_msg, string level) {
		
		TXTSyntax(level, output_msg);
	}

	void Logger::Clog(string output_msg) {

		string level = DEBUG;

		TXTSyntax(level, output_msg);
	}

	void Logger::Clog() {

		string level = INFO;
		string output_msg = "Default placeholder message.";

		TXTSyntax(level, output_msg);
	}
	
	bool Logger::TXTSyntax(string level, string output_msg) {

		char *current_time = CurrentTimeStamp();		

		ifstream log_file(global_file_name_);
		log_file.close();

		ofstream log_file_out(global_file_name_, ofstream::app);

		if (log_file_out.is_open()) {							
			
			log_file_out << "[" << current_time << "] [" << level << "] " << output_msg << "\n";
			log_file_out.close();
			return true;
		}
	}

	/*bool Logger::JSONSyntax(string level, string output_msg) {

		char *current_time = CurrentTimeStamp();

		ifstream log_file(GLOBAL_LOG_NAME);

		if (!log_file) {
			CreateLogFile();
		}

		log_file.close();

		string json_array[10][10] = {



		};

		ofstream log_file_out(GLOBAL_LOG_NAME, ofstream::app);

		if (log_file_out.is_open()) {

			log_file_out << "[" << current_time << "] [" << level << "] " << output_msg << "\n";
			log_file_out.close();
			return true;
		}
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
