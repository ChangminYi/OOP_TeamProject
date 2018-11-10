#pragma once

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR

#ifndef STRING
#define STRING
#include <string>
#endif // !STRING

#include "CaffeData.h"
#include "Order.h"

class CaffeClerk {
private:
	std::vector<Coffee> orderedCoffeeList;
	CaffeData* cd;

public:
	CaffeClerk(CaffeData* _cd) : cd(_cd) {};
	CaffeData* getData();
	std::vector<Coffee> getOrderedList();

	void addOrder(int _idx);
	void addOrder(Coffee _coffee);
	void addBean(Coffee _coffee, int _idx);
	void addIngre(Coffee _coffee, int _idx);
	void saveCustom(Coffee _newCoffee);
	void makeBill();
};