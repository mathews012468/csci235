/**********************
File Name: RouteMap.hpp

Author: Mathew Soto
Date: July 2019
**********************/

/*******************************************
This is the interface of the RouteMap class,
which reads from a two-line file containing
the cities in the map and the cities each one 
is adjacent to and produces a route from a user 
provided origin to destination if one exists
*******************************************/

#ifndef ROUTE_MAP_H
#define ROUTE_MAP_H
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "City.hpp"


class RouteMap
{

public:
	//default constructor
	//@post number_of_cities_ set to zero
	RouteMap();

	//destructor
	//deletes and deallocates pointers in city_list_
	~RouteMap();

	/**
	@param input_file_name of a csv file representing a route map
		where the first line is a comma-separated list of city
		names, and the remainder is a comma-separated list of
		city pairs of the form A-B, indicating that B is adjacent 
		to A
	@post cities are stored in city_list_, and their corresponding
		adjacent cities are stored in each city object
	**/
	bool readMap(std::string input_file_name);

	//@param pointer to object of City class
	//@post new_city is added to city_list_
	void appendCity(City* new_city);

	/**
	@return a pointer to the city found at position, where 
		0 <= position <= n-1, and n is the number of cities,
		and cities are stored in the same order in which
		they appear in the input file
		nullptr if position is outside this range
	**/
	City* getCity(size_t position);

	/**
	@return true if there is a route from origin to destination,
		false otherwise
	@post if a route is found from origin to destination, it will
		print it to standard output in the form 
		"ORIGIN -> ... -> DESTINATION\n"
	**/
	bool isRoute(City* origin, City* destination);

private:
	//vector containing pointers to cities in the map
	std::vector<City*> city_list_;

	//size of city_list_
	size_t number_of_cities_;

	/**
	@param first line of input file
	@post converts string to a list of cities and 
		appends these to city_list_
	**/
	void strToCities(std::string cities);

	/**
	@param second line of input file
	@post converts string to adjacent cities and updates the
		City objects accordingly
	**/
	void setAdjacentCities(std::string adjacent);

	/**
	@param name of city
	@return pointer to city satisfying name_ = name
		nullptr if no cities satisfy this condition
	**/
	City* retrieveCity(std::string name);

};

#endif
