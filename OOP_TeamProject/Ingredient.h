#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef INGREDIENT
#define INGREDIENT

class Ingredient {
private:
	std::string name;	//additional ingredient's name
	unsigned int cost;	//additional ingredient's cost

public:
	//constructor
	Ingredient(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};

	//setter
	void setName(const std::string _name);
	void setCost(const unsigned int _cost);

	//getter
	std::string getName() const;
	unsigned int getCost() const;
};

#endif