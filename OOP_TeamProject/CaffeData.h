#pragma once

#include "Order.h"

#ifndef CAFFEDATA
#define CAFFEDATA

//카페에서 제공 가능한 모든 정보를 가진 클래스
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
	void printDefaultCoffeeBeanList() const;	//현재 사용 가능한 커피콩 리스트 출력
	void printDefaultIngredientList() const;	//현재 사용 가능한 첨가물 리스트 출력
	void printDefaultCoffeeList(const bool _allStatus = 0) const;	//현재 주문 가능한 커피 리스트 출력
	void printCustomOrderList() const;			//기본 메뉴가 아닌, 주문 시 새로 저장한 커피 리스트 출력

	//vector.push_back();
	void addCoffeeBean(const CoffeeBean _bean);		//카페에서 사용 가능한 커피콩 종류 추가
	void addIngredient(const Ingredient _ingre);	//카페에서 사용 가능한 첨가물 종류 추가
	void addCoffee(const Coffee _coffee);			//카페에서 주문 가능한 커피 추가

	//vector.erase(iterator);
	void deleteCoffeeBean(const int it);	//커피콩 종류 제거
	void deleteIngredient(const int it);	//첨가물 종류 제거
	void deleteCoffee(const int it);		//커피 제거

	//getter
	Coffee getDefaultCoffee(const int _index) const;	//기본으로 사용 가능한 커피 반환
	CoffeeBean getDefaultCoffeeBean(const int _index) const;	//기본으로 사용 가능한 커피콩 반환
	Ingredient getDefaultIngredient(const int _index) const;	//기본으로 사용 가능한 첨가물 반환
	std::vector<CoffeeBean> *const getDefaultCoffeeBeanList();	//커피콩 리스트 반환
	std::vector<Ingredient> *const getDefaultIngredientList();	//첨가물 리스트 반환
	size_t sizeofCoffeeBeanList() const;	//커피콩 갯수 반환
	size_t sizeofIngredientList() const;	//첨가물 갯수 반환
	size_t sizeofCoffeeList() const;		//커피 갯수 반환

	//updator
	void updateCost();	//모든 커피의 가격 업데이트

private:
	//initializers
	void initCoffeeBean();	//초기 실행 시 커피콩 리스트 생성
	void initIngredient();	//초기 실행 시 첨가물 리스트 생성
	void initCoffee();		//초기 실행 시 커피 리스트 생성
	void initCustomOrder();	//

	//data
	std::vector<CoffeeBean> defaultCoffeeBeanList;	//caffe's default coffee bean list
	std::vector<Ingredient> defaultIngredientList;	//caffe's default ingredient list
	std::vector<Coffee> defaultCoffeeList;			//caffe's default coffee menu list
	std::vector<Order> customOrderList;				//caffe's custom order menu list
	CoffeeBean *defaultCoffeeBean;					//caffe's default using coffee bean
};

#endif