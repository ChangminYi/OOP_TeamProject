#include "Coffee.h"

void Coffee::setCost() {
	unsigned int temp = 0;

	for (int i = 0; i < this->beanList.size() ; i++) {	
		temp += this->beanList.at(i)->getCost();
	}

	for (int i = 0; i < this->ingreList.size(); i++) {
		temp += this->ingreList.at(i)->getCost();
	}

	this->cost = temp;
}

void Coffee::setName(const std::string _name) {
	this->name = _name;
}

void Coffee::addBeanList(CoffeeBean _newBean) {
	this->beanList.push_back(&_newBean);
	this->setCost();
}

void Coffee::addBeanList(CoffeeBean *_newBean) {
	this->beanList.push_back(_newBean);
	this->setCost();
}

void Coffee::addIngreList(Ingredient _newIngredient) {
	this->ingreList.push_back(&_newIngredient);
	this->setCost();
}

void Coffee::addIngreList(Ingredient * _newIngredient){
	this->ingreList.push_back(_newIngredient);
	this->setCost();
}

void Coffee::removeBeanList(const int iter) {
	this->beanList.erase(this->beanList.begin() + iter);
	this->setCost();
}

void Coffee::removeIngreList(const int iter) {
	this->ingreList.erase(this->ingreList.begin() + iter);
	this->setCost();
}

std::vector<CoffeeBean*> Coffee::getBeanList() const {
	return this->beanList;
}

std::vector<Ingredient*> Coffee::getIngreList() const {
	return this->ingreList;
}

std::string Coffee::getName() const {
	return this->name;
}

unsigned int Coffee::getCost() const {
	return this->cost;
}