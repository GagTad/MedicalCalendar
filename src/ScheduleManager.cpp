#include "ScheduleManager.h"

ScheduleManager::ScheduleManager()
{

}

bool ScheduleManager::addAppointment(TimePoint start, TimePoint end, const std::string& desc)
{
	Appointment newAppointment(start, end, desc);
	
	for (const auto& existingAppointmentPtr : allAppointments)
	{
		if (newAppointment.overlapsWith(*existingAppointmentPtr)) 
		{
			std::cout << "[ERROR] Conflict Detected: Cannot add:" << desc << std::endl;
			std::cout << "Its overlaps with ";
			existingAppointmentPtr->print();
			return false;
		}

		allAppointments.push_back(std::make_unique<Appointment>(start, end, desc));
		std::cout << "[INFO] Successfully added :" << std::endl;
		return true;
	}
	
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
