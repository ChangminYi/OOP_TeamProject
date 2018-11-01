#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef INGREDIENT
#define INGREDIENT

class Ingredient {
private:
	std::string name;
	unsigned int cost;

public:
	Ingredient(std::string _name, unsigned int _cost) :name(_name), cost(_cost) {};

	void setName(std::string _name);
	void setCost(unsigned int _cost);

	std::string getName() const;
	unsigned int getCost() const;
};

#endif