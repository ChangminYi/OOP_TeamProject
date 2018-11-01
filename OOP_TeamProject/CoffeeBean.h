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
	CoffeeBean(std::string _name, int _cost) :name(_name), cost(_cost) {};
	
	void setName(std::string _name);
	void setCost(unsigned int _cost);

	std::string getName() const;
	unsigned int getCost() const;
};

#endif