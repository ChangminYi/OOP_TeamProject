#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef INGREDIENT
#define INGREDIENT

//첨가물 클래스
class Ingredient {
private:
	std::string name;	//additional ingredient's name
	unsigned int cost;	//additional ingredient's cost

public:
	//constructor
	Ingredient(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};

	//setter
	void setName(const std::string _name);	//첨가물 이름 변경하는 함수
	void setCost(const unsigned int _cost);	//첨가물 가격 변경하는 함수

	//getter
	std::string getName() const;	//첨가물 이름 반환하는 함수
	unsigned int getCost() const;	//첨가물 가격 반환하는 함수
};

#endif