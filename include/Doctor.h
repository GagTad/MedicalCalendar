#pragma once

#include <string>

class Doctor {
public:
	Doctor(int docid, const std::string& docName) : id(docid), name(docName) {}


	int getId() const { return id; }
	std::string getName() const { return name; }


private:
	int id;
	std::string name;
};