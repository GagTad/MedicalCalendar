#include "ScheduleManager.h"
#include "Doctor.h"
#include "Patient.h"
#include <chrono>

int main() {
  
    Doctor dr_avagyan(1, "Avagyan");
    Doctor dr_petrosyan(2, "Petrosyan");
    Patient patient_aram(101, "Aram");
    Patient patient_anna(102, "Anna");

    ScheduleManager manager;
    TimePoint now = std::chrono::system_clock::now();

   
    manager.addAppointment(now, now + std::chrono::minutes(45), &dr_avagyan, &patient_aram, "Initial consultation");

    
    manager.addAppointment(now, now + std::chrono::minutes(30), &dr_petrosyan, &patient_anna, "Dental cleaning");
    std::cout << std::endl;
    std::cout << "--- Testing Doctor-Specific Conflicts ---";
    std::cout << std::endl;
    
    manager.addAppointment(now + std::chrono::minutes(30), now + std::chrono::minutes(60), &dr_avagyan, &patient_anna, "Follow-up");

 
    manager.addAppointment(now + std::chrono::minutes(45), now + std::chrono::minutes(90), &dr_avagyan, &patient_anna, "X-Ray results review");


    manager.printAllAppointments();

    return 0;
}
