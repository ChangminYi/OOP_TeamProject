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

//�ֹ��޴� ����(�Ǵ� �׿� �����ϴ� ��) Ŭ����
class CaffeClerk {
private:
	std::vector<Coffee> orderedCoffeeList;
	CaffeData* cd;

public:
	//constructor
	CaffeClerk(CaffeData* _cd) : cd(_cd) {};
	
	//getter
	CaffeData* getData();	//ī���� ������ ��ȯ�ϴ� �Լ�
	std::vector<Coffee> getOrderedList();	//�ֹ��� Ŀ�� ����Ʈ�� ��ȯ�ϴ� �Լ�

	//adder
	void addOrder(int _idx);	//Ŀ�� �ֹ��� �߰��ϴ� �Լ�(�߰����� ����)
	void addOrder(Coffee _coffee);	//Ŀ�� �ֹ��� �߰��ϴ� �Լ�(Ŀ���� Ŀ��)
	void addBean(int listIdx, int beanIdx);		//Ŀ�ǿ� Ŀ���� �߰��ϴ� �Լ�
	void addIngre(int listIdx, int ingreIdx);	//Ŀ�ǿ� ÷���� �߰��ϴ� �Լ�
	
	//else
	void saveCustom(Coffee& _newCoffee);	//�߰� �ֹ� ���� �����ϴ� �Լ�
	void makeBill();	//�ֹ��� ��� �Լ�
};