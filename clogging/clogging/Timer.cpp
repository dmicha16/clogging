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
		TimerEnd(custom_timer);
		break;
	default:
		break;
	}
}

double Timer::TimerStart(std::string custom_timer) {

	timepoint_t highres_current_t = std::chrono::high_resolution_clock::now();

	if (timer_map_.empty) {
		timer_map_.emplace(std::pair<std::string, timepoint_t>(custom_timer, highres_current_t));

	}
	else {
		timer_map_.end();
		timer_map_.emplace(std::pair<std::string, timepoint_t>(custom_timer, highres_current_t));
	}

	return 0;

}

double Timer::TimerEnd(std::string custom_timer) {

	timepoint_t timer_end = std::chrono::high_resolution_clock::now();
	timepoint_t custom_timer_length;

	if (timer_map_.find(custom_timer) != timer_map_.end()) {

		timepoint_t timer_start = timer_map_.find(custom_timer)->second;
		//custom_timer_length = timer_end - timer_start;


		timer_map_.erase(custom_timer);
	}
	else{

	}

	return 0;
}

Timer::~Timer() {
}
