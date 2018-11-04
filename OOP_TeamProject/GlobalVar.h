#pragma once

#include "Order.h"

#ifndef GLOBALVAR
#define GLOBALVAR

void printDefaultCoffeeBeanList();
void printDefaultIngredientList();
void printDefaultCoffeeList(bool _allStatus = 0);
void printCustomOrderList();


void initCoffeeBean();
void initIngredient();
void initCoffee();
void initCustomOrder();
void init();

Coffee getDefaultCoffee(int _index);
CoffeeBean getDefaultCoffeeBean(int _index);
Ingredient getDefaultIngredient(int _index);

#endif