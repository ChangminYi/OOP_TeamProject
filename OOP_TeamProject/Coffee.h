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
	Coffee(const std::string _name) :name(_name) { this->setCost(); };
	Coffee(const std::string _name, const std::vector<CoffeeBean> _beanList) :name(_name), beanList(_beanList) { this->setCost(); };
	Coffee(const std::string _name, const std::vector<Ingredient> _ingreList) :name(_name), ingreList(_ingreList) { this->setCost(); };
	Coffee(const std::string _name, const std::vector<CoffeeBean> _beanList, const std::vector<Ingredient> _ingreList) :name(_name), beanList(_beanList), ingreList(_ingreList) { this->setCost(); };

	void setName(const std::string _name);

	void addBeanList(const CoffeeBean _newBean);
	void addIngreList(const Ingredient _newIngredient);

	void removeBeanList();
	void removeIngreList();

	std::string getName() const;
	unsigned int getCost() const;
};

#endif // !COFFEE