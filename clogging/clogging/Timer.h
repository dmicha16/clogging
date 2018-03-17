#pragma once

#include <time.h>
#include <string>
#include <string.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <chrono>
#include <thread>
#include "json.hpp"
#pragma warning(disable : 4996) //Visual studio error suppress


#define CLOG_T(custom_timer, time_param) TimerObj.ClogT(custom_timer, time_param)

typedef std::chrono::steady_clock::time_point timepoint_t;

typedef enum {
	TRI_TRUE = 0,
	TRI_FALSE = 1,
	TRI_NEUTRAL = 2
} TriState;

enum Timer_t {START, END};

class Timer {

private:
	TriState TimerStart(std::string custom_timer);
	double TimerEnd(std::string custom_timer);	

	std::map<std::string, timepoint_t> timer_map_;

	void TimerOutput(double timer_duration, std::string timer_name, TriState timer_check);

public:

	double SystemUpMillis(timepoint_t global_init_timestamp_);
	std::string TimeStamp();

	void ClogT(std::string custom_timer, Timer_t time_param);

	Timer();
	~Timer();
};

