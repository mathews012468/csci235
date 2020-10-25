/***********************
File Name: City.hpp

Author: Mathew Soto
Date: July 2019
***********************/

/***************************************
This is the interface of the City class, 
which contains a bool indicating whether 
or not this city has been visited and a
list of pointers to other cities adjacent 
to this one
***************************************/

#ifndef CITY_H
#define CITY_H
#include <vector>
#include <string>

class City
{

public:
	//default constructor
	//@post sets visited_ to false
	//@post sets name_ to empty string
	//@post sets next_city_ to null
	City();

	//parameterized constructor
	//@param a string with which a City object will be identified
	//@post sets visited_ to false
	//@post sets name_ to name
	//@post sets next_city_ to null
	City(std::string name);


	//@param a string with which a City object will be identified
	//@post sets name_ to name
	void setName(std::string name);

	//@return name_
	std::string getName() const;

	//@post sets visited_ to true
	void markVisited();

	//@return true is visited_ is true, false otherwise
	bool isVisited() const;

	//@param pointer to city adjacent to this object
	//@post adds new_city to adjacent_list_
	void addCity(City* new_city);

	//@return the unvisited city which appears first in adjacent_list_
	//@return nullptr if adjacent_list_ is empty
	City* obtainCity() const;

private:
	//vector containing pointers to cities adjacent to this object
	std::vector<City*> adjacent_list_;

	//by default false
	//true indicates visited
	bool visited_;

	//string by which this object will be identified
	std::string name_;

};

#endif