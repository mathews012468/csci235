#ifndef TEACHING_ASSISTANT_H
#define TEACHING_ASSISTANT_H

#include <string>
#include "Person.hpp"
#include "Student.hpp"

enum ta_role {LAB_ASSISTANT, LECTURE_ASSISTANT, FULL_ASSISTANT};

class TeachingAssistant: public Student
{

public:
	TeachingAssistant();
	TeachingAssistant(int id, std::string first, std::string last);
	int getHours() const;
	ta_role getRole() const;
	void setHours(const int hours);
	void setRole(const ta_role role);

private:
	int hours_per_week_;
	ta_role role_;

};

#endif
