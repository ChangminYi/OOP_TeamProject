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

//주문받는 점원(또는 그에 상응하는 것) 클래스
class CaffeClerk {
private:
	std::vector<Coffee> orderedCoffeeList;
	CaffeData* cd;

public:
	//constructor
	CaffeClerk(CaffeData* _cd) : cd(_cd) {};
	
	//getter
	CaffeData* getData();	//카페의 정보를 반환하는 함수
	std::vector<Coffee> getOrderedList();	//주문한 커피 리스트르 반환하는 함수

	//adder
	void addOrder(int _idx);	//커피 주문을 추가하는 함수(추가사항 없음)
	void addOrder(Coffee _coffee);	//커피 주문을 추가하는 함수(커스텀 커피)
	void addBean(int listIdx, int beanIdx);		//커피에 커피콩 추가하는 함수
	void addIngre(int listIdx, int ingreIdx);	//커피에 첨가물 추가하는 함수
	
	//else
	void saveCustom(Coffee& _newCoffee);	//추가 주문 내용 저장하는 함수
	void makeBill();	//주문서 출력 함수
};