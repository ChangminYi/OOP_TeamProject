#include "Order.h"

void Order::setCost() {
	int temp = this->orderdCoffee.getCost();

	for (int i = 0; i < this->optionalBean.size(); i++) {
		temp += optionalBean.at(i).getCost();
	}

	for (int i = 0; i < this->optionalIngre.size(); i++) {
		temp += optionalIngre.at(i).getCost();
	}
}

void Order::addOptionalBean(CoffeeBean _newBean) {
	this->optionalBean.push_back(_newBean);
}

void Order::addOptionalIngre(Ingredient _newIngre) {
	this->optionalIngre.push_back(_newIngre);
}

void Order::removeOptionalBean() {

}

void Order::removeOptionalBean() {

}

unsigned int Order::getCost() const {
	return this->cost;
}