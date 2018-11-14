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

//�ֹ����� ������ ��Ÿ���� Ŭ����
class Order {
private:
	Coffee orderedCoffee;
	std::vector<CoffeeBean> optionalBean;
	std::vector<Ingredient> optionalIngre;
	unsigned int cost;

	void setCost();

public:
	//constructor
	Order(const Coffee _coffee) : orderedCoffee(_coffee) {}
	Order(const Coffee _coffee, const std::vector<CoffeeBean> _beanList, const std::vector<Ingredient> _ingreList) : orderedCoffee(_coffee), optionalBean(_beanList), optionalIngre(_ingreList) {}

	//adder
	void addOptionalBean(const CoffeeBean _newBean);	//�߰��� �ֹ����� Ŀ���� �߰�
	void addOptionalIngre(const Ingredient _newIngre);	//�߰��� �ֹ����� ÷���� �߰�

	//remover
	void removeOptionalBean();	//Ŀ���� ����
	void removeOptionalIngre();	//÷���� ����

	//getter
	unsigned int getCost() const;	//�ֹ��� ������ ��ȯ
};
#endif // !ORDER