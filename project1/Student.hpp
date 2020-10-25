#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include "Person.hpp"

class Student: public Person
{

public:
	Student();
	Student(int id, std::string first, std::string last);
	std::string getMajor() const;
	double getGpa() const;
	void setMajor(const std::string major);
	void setGpa(const double gpa);

protected:
	std::string major_;
	double gpa_;

};

#endif
