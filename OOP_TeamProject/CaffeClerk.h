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
	void addOrder(Coffee& _coffee);
	void addBean(int listIdx, int beanIdx);
	void addIngre(int listIdx, int ingreIdx);
	void saveCustom(Coffee& _newCoffee);
	void makeBill();
};