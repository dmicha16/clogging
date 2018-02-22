#include "stdafx.h"
#include "Timer.h"

Timer::Timer() {
}

double Timer::SystemUpMillis(timepoint_t global_init_timestamp_) {

	timepoint_t current_timestamp =
		std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration_t =
		current_timestamp - global_init_timestamp_;

	return duration_t.count();
}

std::string Timer::TimeStamp() {

	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char *time_stamp = asctime(timeinfo);
	time_stamp[strlen(time_stamp) - 1] = '\0';

	return time_stamp;
}

void Timer::ClogT(std::string custom_timer, Timer_t time_param) {	

	switch (time_param) {
	case START:
		TimerStart(custom_timer);
		break;
	case END:
		double timer_duration = TimerEnd(custom_timer);
		TimerOutput(timer_duration, custom_timer);
		break;
	}
}

double Timer::TimerStart(std::string custom_timer) {

	timepoint_t timer_start = std::chrono::high_resolution_clock::now();

	if (timer_map_.empty()) {
		timer_map_.emplace(std::pair<std::string, timepoint_t>(custom_timer, timer_start));

	}
	else {
		timer_map_.end();
		timer_map_.emplace(std::pair<std::string, timepoint_t>(custom_timer, timer_start));
	}

	return 0;

}

double Timer::TimerEnd(std::string custom_timer) {

	timepoint_t timer_end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> timer_duration;

	if (timer_map_.find(custom_timer) != timer_map_.end()) {

		timepoint_t timer_start = timer_map_.find(custom_timer)->second;
		timer_duration = timer_end - timer_start;
		timer_map_.erase(custom_timer);

		return timer_duration.count();
	}
	else {

	}

	return 0;
}

void Timer::TimerOutput(double timer_duration, std::string timer_name) {

	std::string current_time = TimeStamp();

	std::ifstream log_file("timeroutput.log");
	log_file.close();

	std::ofstream log_file_out("timeroutput.log", std::ofstream::app);

	if (log_file_out.is_open()) {

		log_file_out
			<< "[" << current_time << "] "
			<< "[" << timer_name << "] "
			<< "-> Duration: "
			<< timer_duration << std::endl;
		log_file_out.close();
	}

}

Timer::~Timer() {
}
