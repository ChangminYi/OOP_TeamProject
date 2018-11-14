#pragma once

#include "Order.h"

#ifndef CAFFEDATA
#define CAFFEDATA

//ī�信�� ���� ������ ��� ������ ���� Ŭ����
class CaffeData {
public:
	//constructor
	CaffeData() {
		this->initCoffeeBean();
		this->initIngredient();
		this->initCoffee();
		this->initCustomOrder();
	}

	//data printer
	void printDefaultCoffeeBeanList() const;	//���� ��� ������ Ŀ���� ����Ʈ ���
	void printDefaultIngredientList() const;	//���� ��� ������ ÷���� ����Ʈ ���
	void printDefaultCoffeeList(const bool _allStatus = 0) const;	//���� �ֹ� ������ Ŀ�� ����Ʈ ���
	void printCustomOrderList() const;			//�⺻ �޴��� �ƴ�, �ֹ� �� ���� ������ Ŀ�� ����Ʈ ���

	//vector.push_back();
	void addCoffeeBean(const CoffeeBean _bean);		//ī�信�� ��� ������ Ŀ���� ���� �߰�
	void addIngredient(const Ingredient _ingre);	//ī�信�� ��� ������ ÷���� ���� �߰�
	void addCoffee(const Coffee _coffee);			//ī�信�� �ֹ� ������ Ŀ�� �߰�

	//vector.erase(iterator);
	void deleteCoffeeBean(const int it);	//Ŀ���� ���� ����
	void deleteIngredient(const int it);	//÷���� ���� ����
	void deleteCoffee(const int it);		//Ŀ�� ����

	//getter
	Coffee getDefaultCoffee(const int _index) const;	//�⺻���� ��� ������ Ŀ�� ��ȯ
	CoffeeBean getDefaultCoffeeBean(const int _index) const;	//�⺻���� ��� ������ Ŀ���� ��ȯ
	Ingredient getDefaultIngredient(const int _index) const;	//�⺻���� ��� ������ ÷���� ��ȯ
	std::vector<CoffeeBean> *const getDefaultCoffeeBeanList();	//Ŀ���� ����Ʈ ��ȯ
	std::vector<Ingredient> *const getDefaultIngredientList();	//÷���� ����Ʈ ��ȯ
	size_t sizeofCoffeeBeanList() const;	//Ŀ���� ���� ��ȯ
	size_t sizeofIngredientList() const;	//÷���� ���� ��ȯ
	size_t sizeofCoffeeList() const;		//Ŀ�� ���� ��ȯ

	//updator
	void updateCost();	//��� Ŀ���� ���� ������Ʈ

private:
	//initializers
	void initCoffeeBean();	//�ʱ� ���� �� Ŀ���� ����Ʈ ����
	void initIngredient();	//�ʱ� ���� �� ÷���� ����Ʈ ����
	void initCoffee();		//�ʱ� ���� �� Ŀ�� ����Ʈ ����
	void initCustomOrder();	//

	//data
	std::vector<CoffeeBean> defaultCoffeeBeanList;	//caffe's default coffee bean list
	std::vector<Ingredient> defaultIngredientList;	//caffe's default ingredient list
	std::vector<Coffee> defaultCoffeeList;			//caffe's default coffee menu list
	std::vector<Order> customOrderList;				//caffe's custom order menu list
	CoffeeBean *defaultCoffeeBean;					//caffe's default using coffee bean
};

#endif