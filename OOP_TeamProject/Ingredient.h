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
	Ingredient(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};

	void setName(const std::string _name);
	void setCost(const unsigned int _cost);

	std::string getName() const;
	unsigned int getCost() const;
};

#endif