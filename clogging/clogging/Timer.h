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


//#define CLOG_T(time_param) Timer.

enum Timer_t {START, END};

class Timer {

private:
	double TimerStart(std::string custom_timer);
	double TimerEnd(std::string custom_timer);

	//map<string, double> custom_timers;

public:

	double SystemUpMillis(std::chrono::steady_clock::time_point global_init_timestamp_);
	std::string TimeStamp();

	void ClogT(std::string custom_timer, Timer_t time_param);

	Timer();
	~Timer();
};

