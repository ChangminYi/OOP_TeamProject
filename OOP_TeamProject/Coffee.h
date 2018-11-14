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

//Ŀ�� �� ���� ��Ÿ���� Ŭ����
class Coffee{
private:
	std::string name;
	std::vector<CoffeeBean *> beanList;
	std::vector<Ingredient *> ingreList;
	unsigned int cost;

public:
	//constructor
	Coffee(const std::string _name, CoffeeBean *_defaultCoffeeBean, std::vector<Ingredient *> _ingreList) :name(_name) {
		for (int i = 0; i < _ingreList.size(); i++) {
			this->ingreList.push_back(_ingreList[i]);
		}
		this->beanList.push_back(_defaultCoffeeBean);
		this->setCost();
	};
	Coffee(const std::string _name, const std::vector<CoffeeBean *> _beanList, const std::vector<Ingredient *> _ingreList) :name(_name), beanList(_beanList), ingreList(_ingreList) {
		this->setCost();
	};

	//adder
	void addBeanList(CoffeeBean _newBean);	//���� ���� Ŀ���� ���� �߰�
	void addBeanList(CoffeeBean *_newBean);	//"(������: ���� ������ �ٷ� �ݿ�)
	void addIngreList(Ingredient _newIngredient);	//���� ���� ÷���� ���� �߰�
	void addIngreList(Ingredient *_newIngredient);	//"(������: ���� ������ �ٷ� �ݿ�)

	//remover
	void removeBeanList(const int iter);	//���ڷ� ���� ������ �ִ� Ŀ���� ����
	void removeIngreList(const int iter);	//���ڷ� ���� ������ �ִ� ÷���� ����

	//getter
	std::vector<CoffeeBean *> getBeanList() const;	//Ŀ���� ����Ʈ ��ȯ�ϴ� �Լ�
	std::vector<Ingredient *> getIngreList() const;	//÷���� ����Ʈ ��ȯ�ϴ� �Լ�
	std::string getName() const;	//Ŀ�� �̸� ��ȯ�ϴ� �Լ�
	unsigned int getCost() const;	//Ŀ�� ���� ��ȯ�ϴ� �Լ�
	
	//setter
	void setCost();		//Ŀ�� ���� ������Ʈ�ϴ� �Լ�
	void setName(const std::string _name);	//Ŀ�� �̸� �����ϴ� �Լ�
};

#endif // !COFFEE