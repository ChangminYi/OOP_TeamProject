#include "CoffeeBean.h"

void CoffeeBean::setName(const std::string _name) {
	this->name = _name;
}

void CoffeeBean::setCost(const unsigned int _cost) {
	this->cost = _cost;
}

std::string CoffeeBean::getName() const {
	return this->name;
}

unsigned int CoffeeBean::getCost() const {
	return this->cost;
}