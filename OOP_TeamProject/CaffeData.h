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

	//data printer
	void printDefaultCoffeeBeanList() const;
	void printDefaultIngredientList() const;
	void printDefaultCoffeeList(const bool _allStatus = 0) const;
	void printCustomOrderList() const;

	//vector.push_back();
	void addCoffeeBean(const CoffeeBean _bean);
	void addIngredient(const Ingredient _ingre);
	void addCoffee(const Coffee _coffee);

	//vector.erase(iterator);
	void deleteCoffeeBean(const int it);
	void deleteIngredient(const int it);
	void deleteCoffee(const int it);

	//getter
	Coffee getDefaultCoffee(const int _index) const;
	CoffeeBean getDefaultCoffeeBean(const int _index) const;
	Ingredient getDefaultIngredient(const int _index) const;
	std::vector<CoffeeBean> *const getDefaultCoffeeBeanList();
	std::vector<Ingredient> *const getDefaultIngredientList();
	size_t sizeofCoffeeBeanList() const;
	size_t sizeofIngredientList() const;
	size_t sizeofCoffeeList() const;

	//updator
	void updateCost();

private:
	//initializers
	void initCoffeeBean();
	void initIngredient();
	void initCoffee();
	void initCustomOrder();

	//data
	std::vector<CoffeeBean> defaultCoffeeBeanList;	//caffe's default coffee bean list
	std::vector<Ingredient> defaultIngredientList;	//caffe's default ingredient list
	std::vector<Coffee> defaultCoffeeList;			//caffe's default coffee menu list
	std::vector<Order> customOrderList;				//caffe's custom order menu list
	CoffeeBean *defaultCoffeeBean;					//caffe's default using coffee bean
};

#endif