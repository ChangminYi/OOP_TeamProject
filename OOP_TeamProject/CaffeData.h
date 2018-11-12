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
	void printDefaultCoffeeList(const bool _allStatus = 0);
	void printCustomOrderList();

	//vector.push_back();
	void addCoffeeBean(const CoffeeBean _bean);
	void addIngredient(const Ingredient _ingre);
	void addCoffee(const Coffee _coffee);

	//vector.erase(iterator);
	void deleteCoffeeBean(const int it);
	void deleteIngredient(const int it);
	void deleteCoffee(const int it);

	//getter
	Coffee getDefaultCoffee(const int _index);
	CoffeeBean getDefaultCoffeeBean(const int _index);
	Ingredient getDefaultIngredient(const int _index);
	std::vector<CoffeeBean> *getDefaultCoffeeBeanList();
	std::vector<Ingredient> *getDefaultIngredientList();
	size_t sizeofCoffeeBeanList();
	size_t sizeofIngredientList();
	size_t sizeofCoffeeList();

	//updator
	void updateCost();

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
	CoffeeBean *defaultCoffeeBean;
};

#endif