#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#include "Order.h"

CoffeeBean defaultBean[] = {
	CoffeeBean("Colombian Milds", 1000),
	CoffeeBean("Ethiopian Harrar", 1000),
	CoffeeBean("Ethiopian Yirgacheffe", 1000),
	CoffeeBean("Hawaiian Kona", 1000),
	CoffeeBean("Jamaican Blue Mountain", 1000),
	CoffeeBean("Java", 1000)
};

Ingredient defaultIngredient[] = {
	Ingredient("Choco Syrup", 500),
	Ingredient("Charamel Syrup", 500),
	Ingredient("Hazelnut Syrup", 500),
	Ingredient("Vanilla Syrup", 500),
	Ingredient("Whipping Cream", 500),
	Ingredient("Milk Foam", 500),
	Ingredient("Water", 500),
};

Coffee defaultCoffee[]{
	Coffee("Espresso"),
	Coffee("Espresso Con Panna"),
	Coffee("Espresso Macchiato"),
	Coffee("Americano"),
	Coffee("Vienna"),
	Coffee("Caffe Latte"),
	Coffee("Hazelnut Latte"),
	Coffee("Vanilla Latte"),
	Coffee("Caramel Latte"),
	Coffee("Caramel Macchiato"),
	Coffee("Cappuccino"),
	Coffee("Caffe Mocha"),
	Coffee("White Chocolate Mocha"),
	Coffee("Caramel Mocha"),
	Coffee("Mochaccino")
};


void printDefaultBean() {
	for (int i = 0; i < sizeof(defaultBean) / sizeof(CoffeeBean); i++) {
		std::cout << defaultBean[i].getName() << ", " << defaultBean[i].getCost() << std::endl;
	}
}

void printDefaultIngredient() {
	for (int i = 0; i < sizeof(defaultIngredient) / sizeof(CoffeeBean); i++) {
		std::cout << defaultIngredient[i].getName() << ", " << defaultIngredient[i].getCost() << std::endl;
	}
}

void printDefaultCoffee() {
	for (int i = 0; i < sizeof(defaultCoffee) / sizeof(Coffee); i++) {
		std::cout << defaultCoffee[i].getName() << ", " << defaultCoffee[i].getCost() << std::endl;
	}
}

int main() {
	std::cout << "Alpha Version" << std::endl;

	system("pause");
	return 0;
}