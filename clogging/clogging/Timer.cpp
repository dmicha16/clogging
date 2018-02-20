#include "stdafx.h"
#include "Timer.h"

Timer::Timer() {
}

double Timer::SystemUpMillis(std::chrono::steady_clock::time_point global_init_timestamp_) {

	std::chrono::steady_clock::time_point current_timestamp =
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

	return 0;

}

double Timer::TimerEnd(std::string custom_timer) {
	return 0;
}

Timer::~Timer() {
}
