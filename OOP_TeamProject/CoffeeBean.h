#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef COFFEEBEAN
#define COFFEEBEAN

class CoffeeBean {
private: 
	std::string name;
	unsigned int cost;

public:
	CoffeeBean(const unsigned int _cost = 0) :cost(_cost) {};
	CoffeeBean(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};
	
	void setName(const std::string _name);
	void setCost(const unsigned int _cost);

	std::string getName() const;
	unsigned int getCost() const;
};

#endif