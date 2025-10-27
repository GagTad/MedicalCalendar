#pragma once

#include <iostream>
#include <string>
#include <chrono>

class Doctor;
class Patient;

using TimePoint = std::chrono::system_clock::time_point;

class Appointment {

public:
	Appointment(TimePoint start, TimePoint end,const Doctor* doc, const Patient* pat, std::string desc);
	
	void print() const;

	TimePoint getStartTime() const { return startTime; }
	TimePoint getEndTime() const { return endTime; }

	const Doctor* getDoctor() const { return doctor; }

	bool overlapsWith(const Appointment& other) const;


private:

	TimePoint startTime;
	TimePoint endTime;
	std::string description;
	const Doctor* doctor;
	const Patient* patient;

};
