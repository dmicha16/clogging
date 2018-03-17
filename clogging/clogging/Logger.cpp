#include "stdafx.h"
#include "Logger.h"

using json = nlohmann::json;

namespace clogging {

	Logger::Logger() {
		global_init_timestamp_ = std::chrono::high_resolution_clock::now();
	}	
	
	void Logger::AddFile(std::string file_name) {

		global_file_name_ = file_name;

		std::ifstream log_file(file_name);

		if (!log_file) {			
			std::ofstream log_file_create;
			log_file_create.open(file_name);
			log_file_create.close();			
		}
		else
			SystemInitOutput(file_name);
		log_file.close();		
	}

	void Logger::AddFile(std::string file_name, std::string path) {

		global_file_name_ = path + file_name;

		std::ifstream log_file(file_name);

		if (!log_file) {
			std::ofstream log_file_create(path);
			log_file_create.open(path);
			log_file_create.close();
		}
		else
			SystemInitOutput(file_name, path);
		log_file.close();
	}
	
	void Logger::Clog(std::string output_msg, Verbosity level, Output specify_type) {
		
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

	void Logger::Clog(std::string output_msg, Verbosity level) {
		
		TXTSyntax(level, output_msg);
	}

	void Logger::Clog(std::string output_msg) {

		TXTSyntax(Verbosity::DEBUG, output_msg);
	}

	void Logger::SystemInitOutput(std::string file_name) {

		std::ifstream log_file(global_file_name_);
		log_file.close();

		std::ofstream log_file_out(global_file_name_, std::ofstream::app);

		if (log_file_out.is_open()) {

			log_file_out
				<< "[Logger started at: ]"
				<< "[" << __TIMESTAMP__ "] "
				<< "[" << __FILENAME__ << "] "
				<< "[" << __threadid << "] "
				<< std::endl
				<< std::string(75, '-') << std::endl;
			log_file_out.close();
		}
	}

	void Logger::SystemInitOutput(std::string file_name, std::string path) {
		
		std::ifstream log_file(global_file_name_);
		log_file.close();

		std::ofstream log_file_out(global_file_name_, std::ofstream::app);

		if (log_file_out.is_open()) {

			log_file_out
				<< "[Logger started at: ]"
				<< "[" << __TIMESTAMP__ "] "
				<< "[" << __FILENAME__ << "] "
				<< "[" << __threadid << "] "
				<< std::endl
				<< std::string(75, '-') << std::endl;
			log_file_out.close();
		}
	}
	
	void Logger::TXTSyntax(Verbosity level, std::string output_msg) {

		std::string level_value = EnumStringValue(level);
		std::string current_time = TimerObj.TimeStamp();
		double system_uptime = TimerObj.SystemUpMillis(global_init_timestamp_);

		std::ifstream log_file(global_file_name_);
		log_file.close();

		std::ofstream log_file_out(global_file_name_, std::ofstream::app);

		if (log_file_out.is_open()) {							
			
			log_file_out 
				<< "[" << current_time << "] "
				<< "[" << level_value << "] "
				<< "[" << system_uptime << "] "
				<< output_msg << std::endl;
			log_file_out.close();			
		}
	}

	void Logger::JSONSyntax(Verbosity level, std::string output_msg) {

		std::string level_value = EnumStringValue(level);
		std::string current_time = TimerObj.TimeStamp();
		double system_uptime = TimerObj.SystemUpMillis(global_init_timestamp_);

		json output_json = {
			{"timestamp", current_time},
			{"verbosity", level_value},
			{"output_message", output_msg},
			{"system_uptime", system_uptime }
		};

		std::string json_dump = output_json.dump();

		std::ifstream log_file(global_file_name_);
		log_file.close();

		std::ofstream log_file_out(global_file_name_, std::ofstream::app);

		if (log_file_out.is_open()) {

			log_file_out << json_dump << "\n";
			log_file_out.close();			
		}
	}	

#ifdef CLOG_USE_VS 1
	void Logger::ClogVS(std::string output_msg, Verbosity level, Output_vs specify_type) {

		std::string level_value = EnumStringValue(level);
		std::string current_time = TimerObj.TimeStamp();
		double system_uptime = TimerObj.SystemUpMillis(global_init_timestamp_);

		std::stringstream debug_output;
		debug_output
			<< "[" << current_time << "] "
			<< "[" << level_value << "] "
			<< "[" << system_uptime << "] "
			<< output_msg << std::endl;
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

	void Logger::ClogVS(std::string output_msg, Verbosity level) {

		std::string level_value = EnumStringValue(level);
		std::string current_time = TimerObj.TimeStamp();
		double system_uptime = TimerObj.SystemUpMillis(global_init_timestamp_);

		std::stringstream debug_output;
		debug_output
			<< "[" << current_time << "] "
			<< "[" << level_value << "] "
			<< "[" << system_uptime << "] "
			<< output_msg << std::endl;

		OutputDebugStringA(debug_output.str().c_str());
	}

	void Logger::ClogVS(std::string output_msg) {

		std::string current_time = TimerObj.TimeStamp();
		double system_uptime = TimerObj.SystemUpMillis(global_init_timestamp_);

		Verbosity level = Verbosity::DEBUG;
		std::string level_value = EnumStringValue(level);		

		std::stringstream debug_output;
		debug_output
			<< "[" << current_time << "] "
			<< "[" << level_value << "] "
			<< "[" << system_uptime << "] "
			<< output_msg << std::endl;

		OutputDebugStringA(debug_output.str().c_str());
	}
#endif // CLOG_USE_VS 1

	std::string Logger::EnumStringValue(Verbosity level) {

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
	}

	Logger::~Logger() {
	}
}
