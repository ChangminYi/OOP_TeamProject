#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef INGREDIENT
#define INGREDIENT

//÷���� Ŭ����
class Ingredient {
private:
	std::string name;	//additional ingredient's name
	unsigned int cost;	//additional ingredient's cost

public:
	//constructor
	Ingredient(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};

	//setter
	void setName(const std::string _name);	//÷���� �̸� �����ϴ� �Լ�
	void setCost(const unsigned int _cost);	//÷���� ���� �����ϴ� �Լ�

	//getter
	std::string getName() const;	//÷���� �̸� ��ȯ�ϴ� �Լ�
	unsigned int getCost() const;	//÷���� ���� ��ȯ�ϴ� �Լ�
};

#endif