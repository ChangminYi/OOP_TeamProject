#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

//주문을 위한 데이터를 정의한 클래스 헤더
#include "Order.h"

//프로그램 작동을 위한 함수들 정의한 헤더
#include "Func_CoffeeOrder.h"
#include "Func_DataSetting.h"


Ingredient defaultIngredient[] = {
	Ingredient("Choco Syrup", 500),
	Ingredient("Charamel Syrup", 500),
	Ingredient("Hazelnut Syrup", 500),
	Ingredient("Vanilla Syrup", 500),
	Ingredient("Whipping Cream", 500),
	Ingredient("Milk Foam", 500),
	Ingredient("Water", 500)
};

Coffee defaultCoffee[]{
	Coffee("Espresso"),
	Coffee("Espresso Con Panna"),
	Coffee("Espresso Macchiato"),
	Coffee("Americano"),
	Coffee("Vienna"),
	Coffee("Caffe Latte"),
	Coffee("Hazelnut Latte"),
	Coffee("Vanilla Latte"),
	Coffee("Caramel Latte"),
	Coffee("Caramel Macchiato"),
	Coffee("Cappuccino"),
	Coffee("Caffe Mocha"),
	Coffee("White Chocolate Mocha"),
	Coffee("Caramel Mocha"),
	Coffee("Mochaccino")
};


void printMainScreen() {
	std::cout << "  1. 커피 주문" << std::endl;
	std::cout << "  2. 관리" << std::endl;
	std::cout << "  3. 종료" << std::endl;
	std::cout << "선택: ";
	return;
}

bool selectMainFunction() {
	int argi = 0;
	std::cin >> argi;

	switch (argi) {
	case 1:
		coffeeOrderSelected();
		break;
	case 2:
		dataSettingSelected();
		break;
	case 3:
		return false;
	default:
		std::cout << "올바른 입력이 아닙니다." << std::endl;
	}
	return true;
}

int main() {
	do {
		printMainScreen();
	} while (selectMainFunction() != false);

	system("pause");
	return 0;
}