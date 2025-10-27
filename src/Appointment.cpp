#include <iostream>
#include "Appointment.h"

Appointment::Appointment(TimePoint start, TimePoint end, std::string desc)
	: startTime(start), endTime(end), description(desc){}

void Appointment::print() const {
	auto duration = std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime);

	std::cout << "---Appointment Details---" << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Duration: " << duration.count() << " minutes" << std::endl;
	std::cout << "-------------------------" << std::endl;
}
