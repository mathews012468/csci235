/**********************
File Name: RouteMap.cpp

Author: Mathew Soto
Date: July 2019
**********************/

/************************************************
This is the implementation of the RouteMap class,
which reads from a two-line file containing the
cities in the map and the cities each one is
adjacent to and produces a route from a user 
provided origin to destination if one exists
************************************************/

#include "RouteMap.hpp"

//default constructor
//@post number_of_cities_ set to zero
RouteMap::RouteMap()
{
	number_of_cities_ = 0;
}

//destructor
//deletes and deallocates pointers in city_list_
RouteMap::~RouteMap()
{
	for (size_t i = 0; i < number_of_cities_; i++)
	{
		delete getCity(i);
	}

	number_of_cities_ = 0;
}

/**
@param input_file_name of a csv file representing a route map
	where the first line is a comma-separated list of city
	names, and the remainder is a comma-separated list of
	city pairs of the form A-B, indicating that B is adjacent 
	to A
@post cities are stored in city_list_, and their corresponding
	adjacent cities are stored in each city object
**/
bool RouteMap::readMap(std::string input_file_name)
{
	bool success = false;

	std::ifstream fin;
	fin.open(input_file_name);

	if ( fin.fail() )
	{
		std::cout << "Could not open " << input_file_name << std::endl;
		exit(1);
	}

	std::string cities = "";
	if (std::getline(fin, cities))
	{
		strToCities(cities);
		success = true;
	}

	std::string adjacent = "";
	if (std::getline(fin, adjacent))
	{
		setAdjacentCities(adjacent);
	}

	else
	{
		success = false;
	}

	return success;
}

//@param pointer to object of City class
//@post new_city is added to city_list_
void RouteMap::appendCity(City* new_city)
{
	city_list_.push_back(new_city);
	number_of_cities_ += 1;
}

/**
@return a pointer to the city found at position, where 
	0 <= position <= n-1, and n is the number of cities,
	and cities are stored in the same order in which
	they appear in the input file
	nullptr if position is outside this range
**/
City* RouteMap::getCity(size_t position)
{
	if (position >= 0 && position <= number_of_cities_ - 1)
	{
		return city_list_[position];
	}

	else
	{
		return nullptr;
	}
}

/**
@return true if there is a route from origin to destination,
	false otherwise
@post if a route is found from origin to destination, it will
	print it to standard output in the form 
	"ORIGIN -> ... -> DESTINATION\n"
**/
bool RouteMap::isRoute(City* origin, City* destination)
{
	static std::stack<City*> path;
	path.push(origin);

	std::stack<City*> path2;

	static int number = 1;

	City* temp_city;

	origin->markVisited();

	while (path.top() != destination && !path.empty())
	{
		temp_city = path.top()->obtainCity();

		if (temp_city == nullptr)
		{
			path.pop();
		}

		else
		{
			origin = temp_city;
			path.push(origin);
			origin->markVisited();
		}
	}

	if (!path.empty())
	{
		int number = path.size();

		for (int i = 0; i < number; i++)
		{
			path2.push(path.top());
			path.pop();
		}

		for (int i = 0; i < (number - 1); i++)
		{
			std::cout << path2.top()->getName() << " -> ";
			path2.pop();
		}

		std::cout << path2.top()->getName() << std::endl;
		return true;
	}

	else 
	{
		return false;
	}
}



/******************PRIVATE METHODS*************************/

/**
@param first line of input file
@post converts string to a list of cities and
	appends these to city_list_
**/
void RouteMap::strToCities(std::string cities)
{
	int string_length = cities.length();
	std::string city = "";
	
	for (int i = 0; i < string_length; i++)
	{
		if (isalpha(cities[i]))
		{
			city += cities[i];
		}
		else if (cities[i] == ',')
		{
			City* new_city = new City;
			(*new_city).setName(city);
			appendCity(new_city);
			city = "";
		}
		
	}

	//last one after the for loop to account for the no ',' at the end
	City* new_city = new City;
	(*new_city).setName(city);
	appendCity(new_city);
}

/**
@param second line of input file
@post converts string to adjacent cities and updates the
	City objects accordingly
**/
void RouteMap::setAdjacentCities(std::string adjacent)
{
	int string_length = adjacent.length();
	std::string city1 = "";
	std::string city2 = "";
	bool dash_present = false;

	for (int i = 0; i < string_length; i++) // I changed up the order 
						//made most of them else if's
	{
		if (adjacent[i] == '-')
		{
			dash_present = true;
		}

		else if (adjacent[i] == ',')
		{
			retrieveCity(city1)->addCity(retrieveCity(city2));
			dash_present = false;
			city1 = "";
			city2 = "";
		}

		else if (!dash_present)
		{
			city1 += adjacent[i];
		}

		else if (dash_present == true)
		{
			city2 += adjacent[i];
		}
	}

	retrieveCity(city1)->addCity(retrieveCity(city2));
}

/**
@param name of city
@return pointer to city satisfying name_ = name
	nullptr if no cities satisfy this condition
**/
City* RouteMap::retrieveCity(std::string name)
{
	for (size_t i = 0; i < number_of_cities_; i++)
	{
		if (city_list_[i]->getName() == name)
		{
			return city_list_[i];
		}
	}

	return nullptr;
}
