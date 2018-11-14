#pragma once
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef COFFEEBEAN
#define COFFEEBEAN

//커피콩 클래스
class CoffeeBean {
private: 
	std::string name;	//coffee bean's name
	unsigned int cost;	//coffee bean's cost

public:
	//constructor
	CoffeeBean(const std::string _name, const unsigned int _cost) :name(_name), cost(_cost) {};
	
	//setter
	void setName(const std::string _name);	//커피콩 이름을 변경하는 함수
	void setCost(const unsigned int _cost);	//커피콩 가격을 변경하는 함수

	//getter
	std::string getName() const;	//커피콩 이름을 반환하는 함수
	unsigned int getCost() const;	//커피콩 가격을 반환하는 함수
};

#endif