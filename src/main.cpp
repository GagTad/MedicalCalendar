#include <iostream>
#include "appointment.h"
#include "schedulemanager.h"


int main()
{
	ScheduleManager manager;


	TimePoint now = std::chrono::system_clock::now();

	manager.addAppointment(now, now + std::chrono::minutes(60), "Consultation with Dr. Avagyan"); //0-60 min
	std::cout << std::endl;
	manager.addAppointment(now + std::chrono::minutes(90), now + std::chrono::minutes(120), "Dental check-up with Dr. Petrosyan"); //  90-120 min
	std::cout << std::endl;
	manager.addAppointment(now + std::chrono::minutes(30), now + std::chrono::minutes(75), "CONFLICT A (30-75 min)");
	std::cout << std::endl;
	manager.addAppointment(now + std::chrono::minutes(15), now + std::chrono::minutes(45), "CONFLICT B (15-45 min)");
	std::cout << std::endl;
	manager.addAppointment(now + std::chrono::minutes(60), now + std::chrono::minutes(90), "Meeting 3 (60-90 min)");
	std::cout << std::endl;
	manager.printAllAppointments();

	return 0;
}
