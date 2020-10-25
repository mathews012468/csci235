/********************
File Name: City.cpp

Author: Mathew Soto
Date: July 2019
********************/

/*******************************************
This is the implementation of the City class,
which contains a bool indicating whether or
not this city has been visited and a list
of pointers to other cities adjacent to this one
*******************************************/

#include "City.hpp"

//default constructor
//@post sets visited_ to false
//@post sets name_ to empty string
City::City()
{
	visited_ = false;
	name_ = "";
}

//parameterized constructor
//@param a string with which a City object will be identified
//@post sets visited_ to false
//@post sets name_ to name
City::City(std::string name)
{
	visited_ = false;
	name_ = name;
}

//@param a string with which a City object will be identified
//@post sets name_ to name
void City::setName(std::string name)
{
	name_ = name;
}

//@return name_
std::string City::getName() const
{
	return name_;
}

//@post sets visited_ to true
void City::markVisited()
{
	visited_ = true;
}

//@return value of visited_
bool City::isVisited() const
{
	return visited_;
}

//@param pointer to city adjacent to this object
//@post adds new_city to adjacent_list_
void City::addCity(City* new_city)
{
	adjacent_list_.push_back(new_city);
}

//@return the unvisited city which appears first in adjacent_list_
//@return nullptr if adjacent_list_ is empty
City* City::obtainCity() const
{
	if (adjacent_list_.empty() == true)
	{
		return nullptr;
	}

	int adjacent_cities = adjacent_list_.size();

	for (int i = 0; i < adjacent_cities; i++)
	{
		if (adjacent_list_[i]->isVisited() == false)
		{
			return adjacent_list_[i];
		}
	}

	return nullptr;
}