#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR

#include "CoffeeBean.h"
#include "Ingredient.h"


#ifndef COFFEE

class Coffee{
private:
	std::string name;
	std::vector<CoffeeBean *> beanList;
	std::vector<Ingredient *> ingreList;
	unsigned int cost;

public:
	//constructor
	Coffee(const std::string _name, CoffeeBean *_defaultCoffeeBean, std::vector<Ingredient *> _ingreList) :name(_name) {
		for (int i = 0; i < _ingreList.size(); i++) {
			this->ingreList.push_back(_ingreList[i]);
		}
		this->beanList.push_back(_defaultCoffeeBean);
		this->setCost();
	};
	Coffee(const std::string _name, const std::vector<CoffeeBean *> _beanList, const std::vector<Ingredient *> _ingreList) :name(_name), beanList(_beanList), ingreList(_ingreList) {
		this->setCost();
	};

	//adder
	void addBeanList(CoffeeBean _newBean);
	void addBeanList(CoffeeBean *_newBean);
	void addIngreList(Ingredient _newIngredient);
	void addIngreList(Ingredient *_newIngredient);

	//remover
	void removeBeanList(const int iter);
	void removeIngreList(const int iter);

	//getter
	std::vector<CoffeeBean *> getBeanList() const;
	std::vector<Ingredient *> getIngreList() const;
	std::string getName() const;
	unsigned int getCost() const;
	
	//setter
	void setCost();
	void setName(const std::string _name);
};

#endif // !COFFEE