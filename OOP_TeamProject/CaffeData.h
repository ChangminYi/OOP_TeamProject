#pragma once

#include "Order.h"

#ifndef CAFFEDATA
#define CAFFEDATA

class CaffeData {
public:
	//constructor
	CaffeData() {
		this->initCoffeeBean();
		this->initIngredient();
		this->initCoffee();
		this->initCustomOrder();
	}

	//���� ��� �Լ�
	void printDefaultCoffeeBeanList();
	void printDefaultIngredientList();
	void printDefaultCoffeeList(bool _allStatus = 0);
	void printCustomOrderList();

	//vector.push_back();
	void addCoffeeBean(CoffeeBean _bean);
	void addIngredient(Ingredient _ingre);
	void addCoffee(Coffee _coffee);

	//vector.erase(iterator);
	void deleteCoffeeBean(int it);
	void deleteIngredient(int it);
	void deleteCoffee(int it);

	//getter
	Coffee getDefaultCoffee(int _index);
	CoffeeBean getDefaultCoffeeBean(int _index);
	Ingredient getDefaultIngredient(int _index);
	size_t sizeofCoffeeBeanList();
	size_t sizeofIngredientList();
	size_t sizeofCoffeeList();

private:
	//�ʱ�ȭ �Լ���
	void initCoffeeBean();
	void initIngredient();
	void initCoffee();
	void initCustomOrder();

	//����, ÷����, Ŀ�� ������
	std::vector<CoffeeBean> defaultCoffeeBeanList;
	std::vector<Ingredient> defaultIngredientList;
	std::vector<Coffee> defaultCoffeeList;
	std::vector<Order> customOrderList;
	CoffeeBean defaultCoffeeBean;
};

#endif