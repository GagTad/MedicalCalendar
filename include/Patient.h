#pragma once
#include <string>

class Patient {
public:
	Patient(int patId, const std::string& patName) : id(patId), name(patName) {}

	int getid() const { return id; }
	std::string getName() const { return name; }

private:
	int id;
	std::string name;
};