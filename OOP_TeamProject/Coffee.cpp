#include "Coffee.h"

void Coffee::setCost() {
	unsigned int temp = 0;

	for (int i = 0; i < this->beanList.size() ; i++) {	
		temp += this->beanList.at(i).getCost();
	}

	for (int i = 0; i < this->ingreList.size(); i++) {
		temp += this->ingreList.at(i).getCost();
	}

	this->cost = temp;
}

void Coffee::setName(const std::string _name) {
	this->name = _name;
}

void Coffee::addBeanList(const CoffeeBean _newBean) {
	this->beanList.push_back(_newBean);
}

void Coffee::addIngreList(const Ingredient _newIngredient) {
	this->ingreList.push_back(_newIngredient);
}

void Coffee::removeBeanList() {

}

void Coffee::removeIngreList() {

}

std::string Coffee::getName() const {
	return this->name;
}

unsigned int Coffee::getCost() const {
	return this->cost;
}