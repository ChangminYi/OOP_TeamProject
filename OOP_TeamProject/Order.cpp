#include "Order.h"

void Order::setCost() {
	int temp = this->orderedCoffee.getCost();

	for (int i = 0; i < this->optionalBean.size(); i++) {
		temp += this->optionalBean.at(i).getCost();
	}

	for (int i = 0; i < this->optionalIngre.size(); i++) {
		temp += this->optionalIngre.at(i).getCost();
	}
}

void Order::addOptionalBean(const CoffeeBean _newBean) {
	this->optionalBean.push_back(_newBean);
}

void Order::addOptionalIngre(const Ingredient _newIngre) {
	this->optionalIngre.push_back(_newIngre);
}

void Order::removeOptionalBean() {

}

void Order::removeOptionalIngre() {

}

unsigned int Order::getCost() const {
	return this->cost;
}