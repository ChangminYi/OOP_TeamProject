#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#include "Order.h"
#include "GlobalVar.h"

//사용 가능한 원두 종류
std::vector<CoffeeBean> defaultCoffeeBeanList;
//사용 가능한 첨가물 종류
std::vector<Ingredient> defaultIngredientList;
//주문 가능한 기본 커피
std::vector<Coffee> defaultCoffeeList;
//저장되어 있는 커스텀 커피
std::vector<Order> customOrderList;
//기본으로 사용할 원두 종류
CoffeeBean defaultCoffeeBean;

void printDefaultCoffeeBeanList() {
	for (int i = 0; i < defaultCoffeeBeanList.size(); i++) {
		std::cout << i + 1 << defaultCoffeeBeanList.at(i).getName() << std::endl;
	}
	return;
}

void printDefaultIngredientList() {
	for (int i = 0; i < defaultIngredientList.size(); i++) {
		std::cout << i + 1 << defaultIngredientList.at(i).getName() << std::endl;
	}
	return;
}

void printDefaultCoffeeList() {
	for (int i = 0; i < defaultCoffeeList.size(); i++) {
		std::cout << i + 1 << defaultCoffeeList.at(i).getName() << std::endl;
	}
	return;
}

void printCustomOrderList() {
	for (int i = 0; i < customOrderList.size(); i++) {
		//std::cout << i + 1 << customOrderList.at(i).getName() << std::endl;
	}
	return;
}

void initCoffeeBean() {
	//update initial list of coffeebean
	defaultCoffeeBeanList.push_back(CoffeeBean("Colombian Milds", 1000));
	defaultCoffeeBeanList.push_back(CoffeeBean("Ethiopian Harrar", 1000));
	defaultCoffeeBeanList.push_back(CoffeeBean("Ethiopian Yirgacheffe", 1000));
	defaultCoffeeBeanList.push_back(CoffeeBean("Hawaiian Kona", 1000));
	defaultCoffeeBeanList.push_back(CoffeeBean("Jamaican Blue Mountain", 1000));
	defaultCoffeeBeanList.push_back(CoffeeBean("Java", 1000));

	//set default coffeebean
	defaultCoffeeBean = defaultCoffeeBeanList.at(5);

	return;
}

void initIngredient() {
	//update initial list of ingredient
	defaultIngredientList.push_back(Ingredient("Choco Syrup", 500));
	defaultIngredientList.push_back(Ingredient("Charamel Syrup", 500));
	defaultIngredientList.push_back(Ingredient("Hazelnut Syrup", 500));
	defaultIngredientList.push_back(Ingredient("Vanilla Syrup", 500));
	defaultIngredientList.push_back(Ingredient("Whipping Cream", 500));
	defaultIngredientList.push_back(Ingredient("Milk Foam", 500));
	defaultIngredientList.push_back(Ingredient("Water", 500));

	return;
}

void initCustomOrder() {
	if (!customOrderList.empty()) {
		std::cout << "Custom Order List is not empty." << std::endl;
	}

	return;
}

void initCoffee() {
	//update initial coffee
	defaultCoffeeList.push_back(Coffee("Espresso", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Espresso Con Panna", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Espresso Macchiato", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Americano", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Vienna", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Caffe Latte", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Hazelnut Latte", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Vanilla Latte", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Caramel Latte", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Caramel Macchiato", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Cappuccino", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Caffe Mocha", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("White Chocolate Mocha", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Caramel Mocha", defaultCoffeeBean));
	defaultCoffeeList.push_back(Coffee("Mochaccino", defaultCoffeeBean));

	return;
}

void init() {
	initCoffeeBean();
	initIngredient();
	initCustomOrder();
	initCoffee();

	return;
}
