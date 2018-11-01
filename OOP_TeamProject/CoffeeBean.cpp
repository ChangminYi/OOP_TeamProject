#include "CoffeeBean.h"

void CoffeeBean::setName(std::string _name) {
	this->name = _name;
}

void CoffeeBean::setCost(unsigned int _cost) {
	this->cost = _cost;
}

std::string CoffeeBean::getName() const {
	return this->name;
}

unsigned int CoffeeBean::getCost() const {
	return this->cost;
}