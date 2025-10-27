#include <iostream>
#include "appointment.h"
#include "schedulemanager.h"


int main()
{
	ScheduleManager manager;


	TimePoint now = std::chrono::system_clock::now();

	manager.addAppointment(now, now + std::chrono::minutes(45), "Consultation with Dr. Avagyan");
	
	TimePoint later = now + std::chrono::hours(2);
	
	manager.addAppointment(later, later + std::chrono::minutes(30), "Dental check-up with Dr. Petrosyan");

	manager.addAppointment(now + std::chrono::hours(4), now + std::chrono::hours(5), "Meeting with the administrator");

	manager.printAllAppointments();

	return 0;
}
