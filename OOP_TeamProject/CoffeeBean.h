#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef COFFEEBEAN
#define COFFEEBEAN

class CoffeeBean {
private: 
	std::string name;	//coffee bean's name
	unsigned int cost;	//coffee bean's cost

public:
	//constructor
	CoffeeBean(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};
	
	//setter
	void setName(const std::string _name);
	void setCost(const unsigned int _cost);

	//getter
	std::string getName() const;
	unsigned int getCost() const;
};

#endif