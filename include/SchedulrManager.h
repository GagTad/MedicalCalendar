#pragma once

#include "Appointment.h"
#include <vector>
#include <memory>


class ScheduleManager {
public:
	ScheduleManager();
	void addAppointment(TimePoint start, TimePoint end, const std::string& desc);
	void printAllAppointments() const;

private:
	std::vector<std::unique_ptr<Appointment>> allAppointments;
};
