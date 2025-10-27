#include "ScheduleManager.h"

ScheduleManager::ScheduleManager()
{

}

void ScheduleManager::addAppointment(TimePoint start, TimePoint end, const std::string& desc)
{
	auto newAppointment = std::make_unique<Appointment>(start, end, desc);

	allAppointments.push_back(std::move(newAppointment));
	
	std::cout << "New Appointemnt added ----:" << desc << std::endl;
}

void ScheduleManager::printAllAppointments() const
{
	if (allAppointments.empty())
	{
		std::cout << "No Appointments scheduled." << std::endl;
		std::cout << "-------------------------" << std::endl;
		return;
	}
	for (auto& appptr : allAppointments)
	{
		appptr->print();
	}
	

}
