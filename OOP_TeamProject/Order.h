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

//주문받은 내용을 나타내는 클래스
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
	void addOptionalBean(const CoffeeBean _newBean);	//추가로 주문받은 커피콩 추가
	void addOptionalIngre(const Ingredient _newIngre);	//추가로 주문받은 첨가물 추가

	//remover
	void removeOptionalBean();	//커피콩 삭제
	void removeOptionalIngre();	//첨가물 삭제

	//getter
	unsigned int getCost() const;	//주문의 가격을 반환
};
#endif // !ORDER