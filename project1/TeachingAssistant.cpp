#include "TeachingAssistant.hpp"

TeachingAssistant::TeachingAssistant() 
{
	hours_per_week_ = 0;
	role_ = LAB_ASSISTANT;
}

TeachingAssistant::TeachingAssistant(int id, std::string first, std::string last):
Student(id, first, last)
{

}

int TeachingAssistant::getHours() const
{
	return hours_per_week_;
}

ta_role TeachingAssistant::getRole() const
{
	return role_;
}

void TeachingAssistant::setHours(const int hours)
{
	hours_per_week_ = hours;
}

void TeachingAssistant::setRole(const ta_role role)
{
	role_ = role;
}
