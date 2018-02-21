#include "stdafx.h"
#include "Timer.h"

Timer::Timer() {
}

double Timer::SystemUpMillis(my_time_point global_init_timestamp_) {

	my_time_point current_timestamp =
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

	my_time_point highres_current_t = std::chrono::high_resolution_clock::now();

	if (timer_map.empty) {
		timer_map.emplace(std::pair<std::string, my_time_point>(custom_timer, highres_current_t));
	}
	

	for (size_t i = 0; i < timer_map.size; i++) {
		
		if (timer_map[i] == custom_timer) {

		}
	}
	return 0;

}

double Timer::TimerEnd(std::string custom_timer) {
	return 0;
}

Timer::~Timer() {
}
