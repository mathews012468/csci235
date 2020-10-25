#include "Student.hpp"

Student::Student()
{
	major_ = "";
	gpa_ = 0;
}

Student::Student(int id, std::string first, std::string last):
Person(id, first, last)
{

}

std::string Student::getMajor() const
{
	return major_;
}

double Student::getGpa() const
{
	return gpa_;
}

void Student::setMajor(const std::string major) 
{
	major_ = major;
}

void Student::setGpa(const double gpa)
{
	gpa_ = gpa;
}
