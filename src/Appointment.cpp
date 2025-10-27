#include <iostream>
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"

Appointment::Appointment(TimePoint start, TimePoint end, const Doctor* doc, const Patient* pat, std::string desc)
	: startTime(start), endTime(end), doctor(doc), patient(pat), description(desc){}

void Appointment::print() const {
	auto duration = std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime);

	std::cout << "---Appointment Details---" << std::endl;
	std::cout << "Doctor: " << doctor->getName()<< std::endl;
	std::cout << "Patient: " << patient->getName() << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Duration: " << duration.count() << " minutes" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

bool Appointment::overlapsWith(const Appointment& other) const
{
	return this->startTime < other.getEndTime() && this->endTime > other.getStartTime();
}
