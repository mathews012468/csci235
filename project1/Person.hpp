#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person
{

public:
	Person();
	Person(int id, std::string first, std::string last);
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;

protected:
	int id_;
	std::string first_name_;
	std::string last_name_;

};

#endif
