#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#include "GlobalVar.h"

//��� ������ ���� ����
std::vector<CoffeeBean> defaultCoffeeBeanList;
//��� ������ ÷���� ����
std::vector<Ingredient> defaultIngredientList;
//�ֹ� ������ �⺻ Ŀ��
std::vector<Coffee> defaultCoffeeList;
//����Ǿ� �ִ� Ŀ���� Ŀ��
std::vector<Order> customOrderList;
//�⺻���� ����� ���� ����
CoffeeBean defaultCoffeeBean;

void printDefaultCoffeeBeanList() {
	for (int i = 0; i < defaultCoffeeBeanList.size(); i++) {
		std::cout << "    " << i + 1 << ". " << defaultCoffeeBeanList.at(i).getName() << ", " << defaultCoffeeBeanList.at(i).getCost() << "��" << std::endl;
	}
	return;
}

void printDefaultIngredientList() {
	for (int i = 0; i < defaultIngredientList.size(); i++) {
		std::cout << "    " << i + 1 << ". " << defaultIngredientList.at(i).getName() << ", " << defaultIngredientList.at(i).getCost() << "��" << std::endl;
	}
	return;
}

void printDefaultCoffeeList(bool _allStatus) {
	for (int i = 0; i < defaultCoffeeList.size(); i++) {
		std::cout << "    " << i + 1 << ". " << defaultCoffeeList.at(i).getName() << ", " << defaultCoffeeList.at(i).getCost() << "��" << std::endl;
		
		if (_allStatus) {
			std::vector<CoffeeBean> beanTemp = defaultCoffeeList.at(i).getBeanList();
			std::cout << "      ����: ";
			for (int j = 0; j < beanTemp.size(); j++) {
				std::cout << beanTemp.at(j).getName() << " ";
			}
			std::vector<Ingredient> ingTemp = defaultCoffeeList.at(i).getIngreList();
			std::cout << std::endl << "      ÷����: ";
			for (int j = 0; j < ingTemp.size(); j++) {
				std::cout << ingTemp.at(j).getName() << " ";
			}
			std::cout << std::endl;
		}
	}
	return;
}

void printCustomOrderList() {
	for (int i = 0; i < customOrderList.size(); i++) {
		//std::cout << "    " << i + 1 << ". " << customOrderList.at(i).getName() << std::endl;
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
	defaultIngredientList.push_back(Ingredient("Choco Syrup", 500));		//0
	defaultIngredientList.push_back(Ingredient("Charamel Syrup", 500));		//1
	defaultIngredientList.push_back(Ingredient("Hazelnut Syrup", 500));		//2
	defaultIngredientList.push_back(Ingredient("Vanilla Syrup", 500));		//3
	defaultIngredientList.push_back(Ingredient("Whipping Cream", 500));		//4
	defaultIngredientList.push_back(Ingredient("Milk Foam", 500));			//5
	defaultIngredientList.push_back(Ingredient("Steamed Milk", 500));		//6
	defaultIngredientList.push_back(Ingredient("Water", 500));				//7
	defaultIngredientList.push_back(Ingredient("White Choco Syrup", 500));	//8

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

	defaultCoffeeList.push_back(Coffee("Espresso", defaultCoffeeBean, { }));
	defaultCoffeeList.push_back(Coffee("Espresso Con Panna", defaultCoffeeBean, { defaultIngredientList.at(4) }));
	defaultCoffeeList.push_back(Coffee("Espresso Macchiato", defaultCoffeeBean, { defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	defaultCoffeeList.push_back(Coffee("Americano", defaultCoffeeBean, { defaultIngredientList.at(7) }));
	defaultCoffeeList.push_back(Coffee("Vienna", defaultCoffeeBean, { defaultIngredientList.at(7), defaultIngredientList.at(4) }));
	defaultCoffeeList.push_back(Coffee("Caffe Latte", defaultCoffeeBean, { defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	defaultCoffeeList.push_back(Coffee("Hazelnut Latte", defaultCoffeeBean, { defaultIngredientList.at(2), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	defaultCoffeeList.push_back(Coffee("Vanilla Latte", defaultCoffeeBean, { defaultIngredientList.at(3), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	defaultCoffeeList.push_back(Coffee("Caramel Latte", defaultCoffeeBean, { defaultIngredientList.at(1), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	defaultCoffeeList.push_back(Coffee("Caramel Macchiato", defaultCoffeeBean, { defaultIngredientList.at(1), defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	defaultCoffeeList.push_back(Coffee("Cappuccino", defaultCoffeeBean, { defaultIngredientList.at(6), defaultIngredientList.at(5) }));
	defaultCoffeeList.push_back(Coffee("Caffe Mocha", defaultCoffeeBean, { defaultIngredientList.at(0), defaultIngredientList.at(6), defaultIngredientList.at(4) }));
	defaultCoffeeList.push_back(Coffee("White Chocolate Mocha", defaultCoffeeBean, { defaultIngredientList.at(8), defaultIngredientList.at(6), defaultIngredientList.at(4) }));
	defaultCoffeeList.push_back(Coffee("Caramel Mocha", defaultCoffeeBean, { defaultIngredientList.at(0), defaultIngredientList.at(1), defaultIngredientList.at(6), defaultIngredientList.at(4) }));
	defaultCoffeeList.push_back(Coffee("Mochaccino", defaultCoffeeBean, { defaultIngredientList.at(0), defaultIngredientList.at(6), defaultIngredientList.at(5) }));

	return;
}

void init() {
	initCoffeeBean();
	initIngredient();
	initCustomOrder();
	initCoffee();

	return;
}

Coffee getDefaultCoffee(int _index) {
	return defaultCoffeeList.at(_index);
}

CoffeeBean getDefaultCoffeeBean(int _index) {
	return defaultCoffeeBeanList.at(_index);
}

Ingredient getDefaultIngredient(int _index) {
	return defaultIngredientList.at(_index);
}