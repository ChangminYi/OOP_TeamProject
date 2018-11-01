#include "Ingredient.h"

void Ingredient::setName(const std::string _name) {
	this->name = _name;
}

void Ingredient::setCost(const unsigned int _cost) {
	this->cost = _cost;
}

std::string Ingredient::getName() const {
	return this->name;
}

unsigned int Ingredient::getCost() const {
	return this->cost;
}