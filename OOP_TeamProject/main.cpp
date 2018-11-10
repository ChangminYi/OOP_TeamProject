#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

//전역변수 초기화를 위한 헤더
#include "CaffeData.h"

//주문을 위한 데이터를 정의한 클래스 헤더
#include "Order.h"

//프로그램 작동을 위한 함수들 정의한 헤더
#include "Func_CoffeeOrder.h"
#include "Func_DataSetting.h"


//메인 화면 출력 함수
void printMainScreen() {
	std::cout << "  1. 커피 주문" << std::endl;
	std::cout << "  2. 관리" << std::endl;
	std::cout << "  3. 종료" << std::endl;
	std::cout << "선택: ";
	return;
}

//작업 분배 함수
bool selectMainFunction(CaffeData* _cd) {
	int argi = 0;
	std::cin >> argi;

	switch (argi) {
	case 1:
		coffeeOrderSelected(_cd);
		break;
	case 2:
		dataSettingSelected(_cd);
		break;
	case 3:
		return false;
	default:
		std::cout << "올바른 입력이 아닙니다." << std::endl;
	}
	return true;
}

//메인 함수
int main() {
	CaffeData* defData = new CaffeData();

	do {
		printMainScreen();
	} while (selectMainFunction(defData) != false);

	system("pause");

	delete defData;
	return 0;
}