#pragma once

#include <iostream>
#include <string>
#include <chrono>


using TimePoint = std::chrono::system_clock::time_point;

class Appointment {

public:
	Appointment(TimePoint start, TimePoint end, std::string desc);
	void print() const;

	TimePoint getStartTime() const { return startTime; }
	TimePoint getEndTime() const { return endTime; }

	bool overlapsWith(const Appointment& other) const;


private:

	TimePoint startTime;
	TimePoint endTime;
	std::string description;

};
