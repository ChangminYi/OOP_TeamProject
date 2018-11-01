#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#include "Func_DataSetting.h"

//main에서 2번이 눌렸을 경우 화면을 출력하는 함수
void printDataSetting() {
	std::cout << "  1. 원두" << std::endl;
	std::cout << "  2. 첨가물" << std::endl;
	std::cout << "  3. 커피" << std::endl;
	std::cout << "  4. 취소" << std::endl;
	std::cout << "선택: ";
	return;
}

//원두와 첨가물 기능 선택 화면
void printAddDeleteModify() {
	std::cout << "  1. 추가" << std::endl;
	std::cout << "  2. 삭제" << std::endl;
	std::cout << "  3. 수정" << std::endl;
	std::cout << "선택: ";
	return;
}

//커피 기능 선택 화면
void printAddDeleteModify_Coffee() {
	std::cout << "  1. 원두 추가" << std::endl;
	std::cout << "  2. 원두 삭제" << std::endl;
	std::cout << "  3. 첨가물 추가" << std::endl;
	std::cout << "  4. 첨가물 삭제" << std::endl;
	std::cout << "  5. 커피 추가" << std::endl;
	std::cout << "  6. 커피 삭제" << std::endl;
	std::cout << "선택: ";
	return;
}

//원두에서 할 작업 선택하는 함수
void selectCoffeeBeanSetting() {
	printAddDeleteModify();
	
	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			break;
		case 2:
			//deletion
			break;
		case 3:
			//modify
			break;
		default:
			std::cout << "올바른 입력이 아닙니다." << std::endl;
		}
	} while (tmp < 1 || tmp > 3);

	return;
}

//첨가물에서 할 작업 선택하는 함수
void selectIngredientSetting() {
	printAddDeleteModify();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			break;
		case 2:
			//deletion
			break;
		case 3:
			//modify
			break;
		default:
			std::cout << "올바른 입력이 아닙니다." << std::endl;
		}
	} while (tmp < 1 || tmp > 3);

	return;
}

//커피에서 할 작업 선택하는 함수
void selectCoffeeSetting() {
	printAddDeleteModify_Coffee();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//coffeebean addition
			break;
		case 2:
			//coffeebean deletion
			break;
		case 3:
			//addon addition
			break;
		case 4:
			//addon deletion
			break;
		case 5:
			//coffee addition
			break;
		case 6:
			//coffee deletion
			break;
		default:
			std::cout << "올바른 입력이 아닙니다." << std::endl;
		}
	} while (tmp < 1 || tmp > 6);

	return;
}

//main에서 2번이 눌렸을 경우 기능을 선택하는 함수
void dataSettingSelected() {
	int tmp = 0;

	do {
		printDataSetting();
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//function which calls setting of coffeebean
			selectCoffeeBeanSetting();
			break;
		case 2:
			//function which calls setting of addon
			selectIngredientSetting();
			break;
		case 3:
			//function which calls setting of coffee itself
			selectCoffeeSetting();
			break;
		case 4:
			//end of data setting
			return;
		default:
			std::cout << "올바른 입력이 아닙니다." << std::endl;
		}
	} while (tmp < 1 || tmp > 4);

	return;
}
