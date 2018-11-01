#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR

#include "Coffee.h"

#ifndef ORDER

class Order {
private:
	Coffee orderdCoffee;
	std::vector<CoffeeBean> optionalBean;
	std::vector<Ingredient> optionalIngre;
	unsigned int cost;

	void setCost();

public:
	void addOptionalBean(const CoffeeBean _newBean);
	void addOptionalIngre(const Ingredient _newIngre);

	void removeOptionalBean();
	void removeOptionalIngre();

	unsigned int getCost() const;
};
#endif // !ORDER