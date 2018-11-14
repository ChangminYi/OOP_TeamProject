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

//커피 한 잔을 나타내는 클래스
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
	void addBeanList(CoffeeBean _newBean);	//재료로 들어가는 커피콩 종류 추가
	void addBeanList(CoffeeBean *_newBean);	//"(포인터: 가격 수정을 바로 반영)
	void addIngreList(Ingredient _newIngredient);	//재료로 들어가는 첨가물 종류 추가
	void addIngreList(Ingredient *_newIngredient);	//"(포인터: 가격 수정을 바로 반영)

	//remover
	void removeBeanList(const int iter);	//인자로 받은 순서에 있는 커피콩 제거
	void removeIngreList(const int iter);	//인자로 받은 순서에 있는 첨가물 제거

	//getter
	std::vector<CoffeeBean *> getBeanList() const;	//커피콩 리스트 반환하는 함수
	std::vector<Ingredient *> getIngreList() const;	//첨가물 리스트 반환하는 함수
	std::string getName() const;	//커피 이름 반환하는 함수
	unsigned int getCost() const;	//커피 가격 반환하는 함수
	
	//setter
	void setCost();		//커피 가격 업데이트하는 함수
	void setName(const std::string _name);	//커피 이름 변경하는 함수
};

#endif // !COFFEE