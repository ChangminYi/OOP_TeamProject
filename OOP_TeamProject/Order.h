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
	void addOptionalBean(CoffeeBean _newBean);
	void addOptionalIngre(Ingredient _newIngre);

	void removeOptionalBean();
	void removeOptionalBean();

	unsigned int getCost() const;
};
#endif // !ORDER