#include "stdafx.h"
#include "Logger.h"
#pragma warning(disable : 4996)

using json = nlohmann::json;

namespace clogging {

	Logger::Logger() {
		global_init_timestamp_ = chrono::high_resolution_clock::now();		
		
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

	void Logger::AddFile(string file_name, string path) {

		global_file_name_ = path + file_name;
		cout << path;

		ifstream log_file(file_name);

		if (!log_file) {
			ofstream log_file_create(path);
			log_file_create.open(path);
			log_file_create.close();
		}
		log_file.close();
	}
	
	void Logger::Clog(string output_msg, Verbosity level, Output specify_type) {
		
		switch (specify_type) {
			case 0:
				TXTSyntax(level, output_msg);
				break;
			case 1:
				JSONSyntax(level, output_msg);
				break;
			case 2:
				TXTSyntax(level, output_msg);
				JSONSyntax(level, output_msg);
				break;
			default:
				TXTSyntax(level, output_msg);
				break;
		}
	}

	void Logger::Clog(string output_msg, Verbosity level) {
		
		TXTSyntax(level, output_msg);
	}

	void Logger::Clog(string output_msg) {	

		TXTSyntax(Verbosity::DEBUG, output_msg);
	}

	void Logger::Clog() {
		
		string output_msg = "Default placeholder message.";

		TXTSyntax(Verbosity::INFO, output_msg);
	}
	
	void Logger::TXTSyntax(Verbosity level, string output_msg) {               

		string level_value = EnumStringValue(level);
		char *current_time = CurrentTimeStamp();			
		double system_uptime = EpochSeconds(global_init_timestamp_);

		ifstream log_file(global_file_name_);
		log_file.close();

		ofstream log_file_out(global_file_name_, ofstream::app);

		if (log_file_out.is_open()) {							
			
			log_file_out << "[" << current_time << "] [" << level_value << "] " <<
				"[" << system_uptime << "] " <<output_msg << "\n";
			log_file_out.close();			
		}
	}

	void Logger::JSONSyntax(Verbosity level, string output_msg) {

		string level_value = EnumStringValue(level);

		char *current_time = CurrentTimeStamp();
		double system_uptime = EpochSeconds(global_init_timestamp_);

		json output_json = {
			{"timestamp", current_time},
			{"verbosity", level_value},
			{"output_message", output_msg},
			{"system_uptime", system_uptime }
		};

		string json_dump = output_json.dump();

		ifstream log_file(global_file_name_);
		log_file.close();

		ofstream log_file_out(global_file_name_, ofstream::app);

		if (log_file_out.is_open()) {

			log_file_out << json_dump << "\n";
			log_file_out.close();			
		}
	}

#ifdef CLOG_USE_VS 1
	void Logger::ClogVS(string output_msg, Verbosity level, Output_vs specify_type) {

		string level_value = EnumStringValue(level);
		char *current_time = CurrentTimeStamp();
		double system_uptime = EpochSeconds(global_init_timestamp_);

		stringstream debug_output;
		debug_output
			<< "[" << current_time << "] "
			<< "[" << level_value << "] "
			<< "[" << system_uptime << "] "
			<< output_msg << endl;
		OutputDebugStringA(debug_output.str().c_str());

		switch (specify_type) {
		case 0:
			// do nothing
			break;
		case 1:
			JSONSyntax(level, output_msg);
			break;
		case 2:
			TXTSyntax(level, output_msg);
			break;
		case 3:
			JSONSyntax(level, output_msg);
			TXTSyntax(level, output_msg);
			break;
		}
	}

	void Logger::ClogVS(string output_msg, Verbosity level) {

		string level_value = EnumStringValue(level);
		char *current_time = CurrentTimeStamp();

		double system_uptime = EpochSeconds(global_init_timestamp_);

		stringstream debug_output;
		debug_output
			<< "[" << current_time << "] "
			<< "[" << level_value << "] "
			<< "[" << system_uptime << "] "
			<< output_msg << endl;

		OutputDebugStringA(debug_output.str().c_str());
	}

	void Logger::ClogVS(string output_msg) {

		char *current_time = CurrentTimeStamp();
		double system_uptime = EpochSeconds(global_init_timestamp_);

		Verbosity level = Verbosity::DEBUG;
		string level_value = EnumStringValue(level);		

		stringstream debug_output;
		debug_output
			<< "[" << current_time << "] "
			<< "[" << level_value << "] "
			<< "[" << system_uptime << "] "
			<< output_msg << endl;

		OutputDebugStringA(debug_output.str().c_str());
	}
#endif // CLOG_USE_VS 1

	string Logger::EnumStringValue(Verbosity level) {

		switch (level) {
		case DEBUG:
			return "DEBUG";
			break;
		case INFO:
			return "INFO";
			break;
		case NOTICE:
			return "NOTICE";
			break;
		case WARN:
			return "WARNING";
			break;
		case ERR:
			return "ERROR";
			break;
		case CRIT:
			return "CRITICAL";
			break;
		case ALERT:
			return "ALERT";
			break;
		case EMERG:
			return "EMERGENCY";
			break;
		default:
			break;
		}
		return string();
	}
	
	char *Logger::CurrentTimeStamp() {

		time_t rawtime;
		struct tm * timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		char *current = asctime(timeinfo);
		current[strlen(current) - 1] = '\0';

		return current;
	}

	double Logger::EpochSeconds(chrono::steady_clock::time_point global_init_timestamp_) {

		chrono::steady_clock::time_point current_timestamp =
			std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> duration_t =
			current_timestamp - global_init_timestamp_;

		return duration_t.count();
	}

	Logger::~Logger() {
	}
}
