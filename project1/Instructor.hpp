#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include "Person.hpp"

class Instructor: public Person
{

public:
	Instructor();
	Instructor(int id, std::string first, std::string last);
	std::string getOffice() const;
	std::string getContact() const;
	void setOffice(const std::string office);
	void setContact(const std::string contact);

private:
	std::string office_;
	std::string contact_;

};

#endif
