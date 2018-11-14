#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef COFFEEBEAN
#define COFFEEBEAN

//Ŀ���� Ŭ����
class CoffeeBean {
private: 
	std::string name;	//coffee bean's name
	unsigned int cost;	//coffee bean's cost

public:
	//constructor
	CoffeeBean(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};
	
	//setter
	void setName(const std::string _name);	//Ŀ���� �̸��� �����ϴ� �Լ�
	void setCost(const unsigned int _cost);	//Ŀ���� ������ �����ϴ� �Լ�

	//getter
	std::string getName() const;	//Ŀ���� �̸��� ��ȯ�ϴ� �Լ�
	unsigned int getCost() const;	//Ŀ���� ������ ��ȯ�ϴ� �Լ�
};

#endif