#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#include "CaffeData.h"



void CaffeData::printDefaultCoffeeBeanList() {
	for (int i = 0; i < this->defaultCoffeeBeanList.size(); i++) {
		std::cout << "    " << i + 1 << ". " << this->defaultCoffeeBeanList[i].getName() << ", " << this->defaultCoffeeBeanList[i].getCost() << "원" << std::endl;
	}
	return;
}

void CaffeData::printDefaultIngredientList() {
	for (int i = 0; i < this->defaultIngredientList.size(); i++) {
		std::cout << "    " << i + 1 << ". " << this->defaultIngredientList[i].getName() << ", " << this->defaultIngredientList[i].getCost() << "원" << std::endl;
	}
	return;
}

void CaffeData::printDefaultCoffeeList(const bool _allStatus) {
	for (int i = 0; i < this->defaultCoffeeList.size(); i++) {
		std::cout << "    " << i + 1 << ". " << this->defaultCoffeeList[i].getName() << ", " << this->defaultCoffeeList[i].getCost() << "원" << std::endl;
		
		if (_allStatus) {
			std::vector<CoffeeBean> beanTemp = defaultCoffeeList[i].getBeanList();
			std::cout << "      원두: ";
			for (int j = 0; j < beanTemp.size(); j++) {
				std::cout << beanTemp[j].getName() << " ";
			}
			std::vector<Ingredient> ingTemp = defaultCoffeeList[i].getIngreList();
			std::cout << std::endl << "      첨가물: ";
			for (int j = 0; j < ingTemp.size(); j++) {
				std::cout << ingTemp[j].getName() << " ";
			}
			std::cout << std::endl;
		}
	}
	return;
}

void CaffeData::printCustomOrderList() {
	for (int i = 0; i < this->customOrderList.size(); i++) {
		//std::cout << "    " << i + 1 << ". " << customOrderList.at(i).getName() << std::endl;
	}
	return;
}

void CaffeData::addCoffeeBean(const CoffeeBean _bean){
	this->defaultCoffeeBeanList.push_back(_bean);
	return;
}

void CaffeData::addIngredient(const Ingredient _ingre) {
	this->defaultIngredientList.push_back(_ingre);
	return;
}

void CaffeData::addCoffee(const Coffee _coffee) {
	this->defaultCoffeeList.push_back(_coffee);
	return;
}

void CaffeData::deleteCoffeeBean(const int it){
	this->defaultCoffeeBeanList.erase(this->defaultCoffeeBeanList.begin() + it);
	return;
}

void CaffeData::deleteIngredient(const int it) {
	this->defaultIngredientList.erase(this->defaultIngredientList.begin() + it);
	return;
}

void CaffeData::deleteCoffee(const int it) {
	this->defaultCoffeeList.erase(this->defaultCoffeeList.begin() + it);
}

void CaffeData::initCoffeeBean() {
	//update initial list of coffeebean
	this->defaultCoffeeBeanList.push_back(CoffeeBean("Colombian Milds", 1000));
	this->defaultCoffeeBeanList.push_back(CoffeeBean("Ethiopian Harrar", 1000));
	this->defaultCoffeeBeanList.push_back(CoffeeBean("Ethiopian Yirgacheffe", 1000));
	this->defaultCoffeeBeanList.push_back(CoffeeBean("Hawaiian Kona", 1000));
	this->defaultCoffeeBeanList.push_back(CoffeeBean("Jamaican Blue Mountain", 1000));
	this->defaultCoffeeBeanList.push_back(CoffeeBean("Java", 1000));

	//set default coffeebean
	this->defaultCoffeeBean = defaultCoffeeBeanList[5];	//Java

	return;
}

void CaffeData::initIngredient() {
	//update initial list of ingredient
	this->defaultIngredientList.push_back(Ingredient("Choco Syrup", 500));			//0
	this->defaultIngredientList.push_back(Ingredient("Charamel Syrup", 500));		//1
	this->defaultIngredientList.push_back(Ingredient("Hazelnut Syrup", 500));		//2
	this->defaultIngredientList.push_back(Ingredient("Vanilla Syrup", 500));		//3
	this->defaultIngredientList.push_back(Ingredient("Whipping Cream", 500));		//4
	this->defaultIngredientList.push_back(Ingredient("Milk Foam", 500));			//5
	this->defaultIngredientList.push_back(Ingredient("Steamed Milk", 500));			//6
	this->defaultIngredientList.push_back(Ingredient("Water", 500));				//7
	this->defaultIngredientList.push_back(Ingredient("White Choco Syrup", 500));	//8

	return;
}

void CaffeData::initCustomOrder() {
	if (!this->customOrderList.empty()) {
		std::cout << "Custom Order List is not empty." << std::endl;
	}

	return;
}

void CaffeData::initCoffee() {
	//update initial coffee

	this->defaultCoffeeList.push_back(Coffee("Espresso", defaultCoffeeBean, { }));
	this->defaultCoffeeList.push_back(Coffee("Espresso Con Panna", defaultCoffeeBean, { defaultIngredientList.at(4) }));
	this->defaultCoffeeList.push_back(Coffee("Espresso Macchiato", defaultCoffeeBean, { defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	this->defaultCoffeeList.push_back(Coffee("Americano", defaultCoffeeBean, { defaultIngredientList.at(7) }));
	this->defaultCoffeeList.push_back(Coffee("Vienna", defaultCoffeeBean, { defaultIngredientList.at(7), defaultIngredientList.at(4) }));
	this->defaultCoffeeList.push_back(Coffee("Caffe Latte", defaultCoffeeBean, { defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	this->defaultCoffeeList.push_back(Coffee("Hazelnut Latte", defaultCoffeeBean, { defaultIngredientList.at(2), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	this->defaultCoffeeList.push_back(Coffee("Vanilla Latte", defaultCoffeeBean, { defaultIngredientList.at(3), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	this->defaultCoffeeList.push_back(Coffee("Caramel Latte", defaultCoffeeBean, { defaultIngredientList.at(1), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	this->defaultCoffeeList.push_back(Coffee("Caramel Macchiato", defaultCoffeeBean, { defaultIngredientList.at(1), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	this->defaultCoffeeList.push_back(Coffee("Cappuccino", defaultCoffeeBean, { defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	this->defaultCoffeeList.push_back(Coffee("Caffe Mocha", defaultCoffeeBean, { defaultIngredientList.at(0), defaultIngredientList.at(6), defaultIngredientList.at(4) }));
	this->defaultCoffeeList.push_back(Coffee("White Chocolate Mocha", defaultCoffeeBean, { defaultIngredientList.at(8), defaultIngredientList.at(6), defaultIngredientList.at(4) }));
	this->defaultCoffeeList.push_back(Coffee("Caramel Mocha", defaultCoffeeBean, { defaultIngredientList.at(0), defaultIngredientList.at(1), defaultIngredientList.at(6), defaultIngredientList.at(4) }));
	this->defaultCoffeeList.push_back(Coffee("Mochaccino", defaultCoffeeBean, { defaultIngredientList.at(0), defaultIngredientList.at(6), defaultIngredientList.at(5) }));

	return;
}


Coffee &CaffeData::getDefaultCoffee(const int _index) {
	return this->defaultCoffeeList.at(_index);
}

CoffeeBean &CaffeData::getDefaultCoffeeBean(const int _index) {
	return this->defaultCoffeeBeanList.at(_index);
}

Ingredient &CaffeData::getDefaultIngredient(const int _index) {
	return this->defaultIngredientList.at(_index);
}

size_t CaffeData::sizeofCoffeeBeanList() {
	return this->defaultCoffeeBeanList.size();
}

size_t CaffeData::sizeofIngredientList() {
	return this->defaultIngredientList.size();
}

size_t CaffeData::sizeofCoffeeList(){
	return this->defaultCoffeeList.size();
}
