#include "Instructor.hpp"

Instructor::Instructor()
{
	office_ = "";
	contact_ = "";
}

Instructor::Instructor(int id, std::string first, std::string last):
Person(id, first, last)
{

}

std::string Instructor::getOffice() const
{
	return office_;
}

std::string Instructor::getContact() const
{
	return contact_;
}

void Instructor::setOffice(const std::string office)
{
	office_ = office;
}

void Instructor::setContact(const std::string contact)
{
	contact_ = contact;
}
