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
	std::vector<CoffeeBean> beanList;
	std::vector<Ingredient> ingreList;
	unsigned int cost;

	void setCost();

public:
	Coffee(std::string _name) :name(_name) {};
	Coffee(std::string _name, std::vector<CoffeeBean> _beanList) :name(_name), beanList(_beanList) {};
	Coffee(std::string _name, std::vector<Ingredient> _ingreList) :name(_name), ingreList(_ingreList) {};
	Coffee(std::string _name, std::vector<CoffeeBean> _beanList, std::vector<Ingredient> _ingreList) :name(_name), beanList(_beanList), ingreList(_ingreList) {};

	void setName(std::string _name);

	void addBeanList(CoffeeBean _newBean);
	void addIngreList(Ingredient _newIngredient);

	void removeBeanList();
	void removeIngreList();

	std::string getName() const;
	unsigned int getCost() const;
};

#endif // !COFFEE