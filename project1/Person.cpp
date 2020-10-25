#include "Person.hpp"

Person::Person() 
{
	id_ = 0;
	first_name_ = "";
	last_name_ = "";
}

Person::Person(int id, std::string first, std::string last)
{
	id_ = id;
	first_name_ = first;
	last_name_ = last;
}

int Person::getID() const
{
	return id_;
}

std::string Person::getFirstName() const
{
	return first_name_;
}

std::string Person::getLastName() const
{
	return last_name_;
}
