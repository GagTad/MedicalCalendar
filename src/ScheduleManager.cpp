#include "ScheduleManager.h"
#include <iostream>
#include "Doctor.h"
#include "Patient.h"

ScheduleManager::ScheduleManager()
{

}

bool ScheduleManager::addAppointment(TimePoint start, TimePoint end, const Doctor* doc, const Patient* pat, const std::string& desc)
{
	Appointment newAppointment(start, end,doc ,pat , desc);
	if (!allAppointments.size())
	{
		allAppointments.push_back(std::make_unique<Appointment>(start, end,doc ,pat, desc));
		std::cout << "[INFO] Successfully added :" << desc << std::endl;
		return true;
	}
	
	for (const auto& existingAppointmentPtr : allAppointments)
	{
		if(existingAppointmentPtr->getDoctor()->getId() == doc->getId()){
			if (newAppointment.overlapsWith(*existingAppointmentPtr)) 
			{
				std::cout << "[ERROR] Conflict Detected: Cannot add:" << desc << std::endl;
				std::cout << "Its overlaps with ";
				existingAppointmentPtr->print();
				return false;
			}
		}

		allAppointments.push_back(std::make_unique<Appointment>(start, end,doc , pat,  desc));
		std::cout << "[INFO] Successfully added :" << desc << std::endl;
		return true;
	}
	

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
