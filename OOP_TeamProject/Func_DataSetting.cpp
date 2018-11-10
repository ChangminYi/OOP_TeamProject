#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#include "CaffeData.h"
#include "Func_DataSetting.h"
#include "Order.h"



/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// 화면 출력 함수 /////////////////////////////////////

//커피의 원두 출력하는 함수
void printCoffeeBeanOfCoffee(Coffee arg) {
	for (int i = 0; i < arg.getBeanList().size(); i++) {
		std::cout << "      " << i + 1 << ". " << arg.getBeanList().at(i).getName() << std::endl;
	}

	return;
}

//커피의 첨가물 출력하는 함수
void printIngredientOfCoffee(Coffee arg) {
	for (int i = 0; i < arg.getIngreList().size(); i++) {
		std::cout << "      " << i + 1 << ". " << arg.getIngreList().at(i).getName() << std::endl;
	}

	return;
}

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
	std::cout << "  1. 커피에 원두 추가" << std::endl;
	std::cout << "  2. 커피에서 원두 삭제" << std::endl;
	std::cout << "  3. 커피에 첨가물 추가" << std::endl;
	std::cout << "  4. 커피에서 첨가물 삭제" << std::endl;
	std::cout << "  5. 커피 추가" << std::endl;
	std::cout << "  6. 커피 삭제" << std::endl;
	std::cout << "선택: ";
	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// 커피콩 제어 함수 ////////////////////////////////////

//원두 추가 함수
void addCoffeeBean(CaffeData *_cd) {
	std::string newCoffeeBeanName;
	unsigned int newCost = 0;

	std::cout << "추가할 원두 이름: ";
	std::cin.ignore();
	std::getline(std::cin, newCoffeeBeanName);
	std::cout << "원두 가격: ";
	std::cin >> newCost;

	_cd->addCoffeeBean(CoffeeBean(newCoffeeBeanName, newCost));
	
	return;
}

//원두 삭제 함수
void deleteCoffeeBean(CaffeData *_cd) {
	_cd->printDefaultCoffeeBeanList();

	int idx = 0;
	do {
		std::cout << "삭제할 원두 번호 (취소는 0): ";
		std::cin >> idx;

		if (idx < 0 || idx > _cd->sizeofCoffeeBeanList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx == 0) {
			break;
		}
		else {
			_cd->deleteCoffeeBean(idx - 1);
		}
	} while (idx < 0 || idx > _cd->sizeofCoffeeBeanList());

	return;
}

//원두 수정 함수
void modifyCoffeeBean(CaffeData *_cd) {
	_cd->printDefaultCoffeeBeanList();
	
	int idx = 0;
	do {
		std::cout << "수정할 원두 번호 (취소는 0): ";
		std::cin >> idx;

		if (idx > _cd->sizeofCoffeeBeanList() || idx < 0) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx == 0) {
			return;
		}
	} while (idx < 0 || idx > _cd->sizeofCoffeeBeanList());

	//이름 수정
	char yn = 0;
	do {
		std::cout << "이름을 수정하시겠습니까? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		std::string newName = _cd->getDefaultCoffeeBean(idx - 1).getName();
		std::cout << "새 이름을 입력하세요: ";
		std::cin.ignore();
		std::getline(std::cin, newName);
		_cd->getDefaultCoffeeBean(idx - 1).setName(newName);
	}

	//가격 수정
	yn = 0;
	do {
		std::cout << "가격을 수정하시겠습니까? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		unsigned int newCost = _cd->getDefaultCoffeeBean(idx - 1).getCost();
		std::cout << "새 가격을 입력하세요: ";
		std::cin >> newCost;
		_cd->getDefaultCoffeeBean(idx - 1).setCost(newCost);
	}
	
	return;
}

//원두에서 할 작업 선택하는 함수
void selectCoffeeBeanSetting(CaffeData *_cd) {
	printAddDeleteModify();
	
	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			addCoffeeBean(_cd);
			break;
		case 2:
			//deletion
			deleteCoffeeBean(_cd);
			break;
		case 3:
			//modify
			modifyCoffeeBean(_cd);
			break;
		default:
			std::cout << "올바른 입력이 아닙니다." << std::endl;
		}
	} while (tmp < 1 || tmp > 3);

	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// 첨가물 제어 함수 ////////////////////////////////////

//첨가물 추가 함수
void addIngredient(CaffeData *_cd) {
	std::string newIngredientName;
	unsigned int newCost = 0;

	std::cout << "추가할 첨가물 이름: ";
	std::cin.ignore();
	std::getline(std::cin, newIngredientName);
	std::cout << "첨가물 가격: ";
	std::cin >> newCost;

	_cd->addIngredient(Ingredient(newIngredientName, newCost));

	return;
}

//첨가물 삭제 함수
void deleteIngredient(CaffeData *_cd) {
	_cd->printDefaultIngredientList();

	int idx = 0;
	do {
		std::cout << "삭제할 첨가물 번호: ";
		std::cin >> idx;

		if (idx < 0 || idx > _cd->sizeofIngredientList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
		}
		else if (idx == 0) {
			break;
		}
		else {
			_cd->deleteIngredient(idx - 1);
		}
	} while (idx < 1 || idx > _cd->sizeofIngredientList());

	return;
}

//첨가물 수정 함수
void modifyIngredient(CaffeData *_cd) {
	_cd->printDefaultIngredientList();

	int idx = 0;
	do {
		std::cout << "수정할 첨가물 번호 (취소는 0): ";
		std::cin >> idx;

		if (idx < 0 || idx > _cd->sizeofIngredientList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx == 0) {
			return;
		}
	} while (idx < 0 || idx > _cd->sizeofIngredientList());

	//이름 수정
	char yn = 0;
	do {
		std::cout << "이름을 수정하시겠습니까? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		std::string newName = _cd->getDefaultIngredient(idx - 1).getName();
		std::cout << "새 이름을 입력하세요: ";
		std::cin.ignore();
		std::getline(std::cin, newName);
		_cd->getDefaultIngredient(idx - 1).setName(newName);
	}

	//가격 수정
	yn = 0;
	do {
		std::cout << "가격을 수정하시겠습니까? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		unsigned int newCost = _cd->getDefaultIngredient(idx - 1).getCost();
		std::cout << "새 가격을 입력하세요: ";
		std::cin >> newCost;
		_cd->getDefaultIngredient(idx - 1).setCost(newCost);
	}

	return;
}

//첨가물에서 할 작업 선택하는 함수
void selectIngredientSetting(CaffeData *_cd) {
	printAddDeleteModify();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			addIngredient(_cd);
			break;
		case 2:
			//deletion
			deleteIngredient(_cd);
			break;
		case 3:
			//modify
			modifyIngredient(_cd);
			break;
		default:
			std::cout << "올바른 입력이 아닙니다." << std::endl;
		}
	} while (tmp < 1 || tmp > 3);

	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// 커피 제어 함수 ////////////////////////////////////

//커피에 커피콩 추가 함수
void addCoffeeBeanToCoffee(CaffeData *_cd) {
	_cd->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "커피콩을 추가할 커피 번호를 선택해 주세요 (취소는 0): ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList());

	_cd->printDefaultCoffeeBeanList();
	int idx_bean = 0;
	do {
		std::cout << "추가할 원두 번호를 선택해 주세요 (다 추가했으면 0): ";
		std::cin >> idx_bean;

		if (idx_bean < 0 || idx_bean > _cd->sizeofCoffeeBeanList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx_bean == 0) {
			break;
		}
		else {
			_cd->getDefaultCoffee(idx_coffee - 1).addBeanList(_cd->getDefaultCoffeeBean(idx_bean - 1));
		}
	} while (idx_bean != 0);

	return;
}

//커피에 커피콩 제거 함수
void deleteCoffeeBeanFromCoffee(CaffeData *_cd) {
	_cd->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "커피콩을 제거할 커피 번호를 선택해 주세요 (취소는 0): ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList());

	Coffee *toRemove = &_cd->getDefaultCoffee(idx_coffee - 1);

	int idx_bean = 0;
	do {
		if (toRemove->getBeanList().empty()) {
			std::cout << "원두가 없습니다." << std::endl;
			idx_bean = 0;
			break;
		}
		else {
			printCoffeeBeanOfCoffee(*toRemove);

			std::cout << "삭제할 원두 번호를 선택해 주세요 (다 삭제했으면 0): ";
			std::cin >> idx_bean;

			if (idx_bean < 0 || idx_bean > toRemove->getBeanList().size()) {
				std::cout << "잘못된 입력입니다." << std::endl;
				continue;
			}
			else if (idx_bean == 0) {
				break;
			}
			else {
				toRemove->removeBeanList(idx_bean - 1);
			}
		}
	} while (idx_bean != 0);

	return;
}

//커피에 첨가물 추가 함수
void addIngredientToCoffee(CaffeData *_cd) {
	_cd->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "첨가물을 추가할 커피 번호를 선택해 주세요 (취소는 0): ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList());

	_cd->printDefaultIngredientList();
	int idx_ingre = 0;
	do {
		std::cout << "추가할 첨가물 번호를 선택해 주세요 (다 추가했으면 0): ";
		std::cin >> idx_ingre;

		if (idx_ingre < 0 || idx_ingre > _cd->sizeofIngredientList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx_ingre == 0) {
			break;
		}
		else {
			_cd->getDefaultCoffee(idx_coffee - 1).addIngreList(_cd->getDefaultIngredient(idx_ingre - 1));
		}
	} while (idx_ingre != 0);

	return;
}

//커피에 첨가물 제거 함수
void deleteIngredientFromCoffee(CaffeData *_cd) {
	_cd->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "커피콩을 제거할 커피 번호를 선택해 주세요: ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _cd->sizeofCoffeeList());

	Coffee *toRemove = &_cd->getDefaultCoffee(idx_coffee - 1);

	int idx_ingre = 0;
	do {
		if (toRemove->getIngreList().empty()) {
			std::cout << "첨가물이 없습니다." << std::endl;
			idx_ingre = 0;
			break;
		}
		else {
			printIngredientOfCoffee(*toRemove);

			std::cout << "삭제할 첨가물 번호를 선택해 주세요 (다 삭제했으면 0): ";
			std::cin >> idx_ingre;

			if (idx_ingre < 0 || idx_ingre > toRemove->getIngreList().size()) {
				std::cout << "잘못된 입력입니다." << std::endl;
				continue;
			}
			else if (idx_ingre == 0) {
				break;
			}
			else {
				toRemove->removeIngreList(idx_ingre - 1);
			}
		}
	} while (idx_ingre != 0);

	return;
}

//커피 추가 함수
void addCoffee(CaffeData *_cd) {
	std::string newCoffeeName;
	std::cout << "새로운 커피 이름을 입력하세요: ";
	std::cin.ignore();
	std::getline(std::cin, newCoffeeName);

	int tmp = 0;
	std::vector<CoffeeBean> newBean;
	_cd->printDefaultCoffeeBeanList();
	do {
		std::cout << "원두를 추가하세요 (다 추가했으면 0): ";
		std::cin >> tmp;

		if (tmp < 0 || tmp > _cd->sizeofCoffeeBeanList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}
		else if (tmp == 0) {
			break;
		}
		else {
			newBean.push_back(_cd->getDefaultCoffeeBean(tmp - 1));
		}
	} while (tmp != 0);

	tmp = 0;
	std::vector<Ingredient> newIngre;
	_cd->printDefaultIngredientList();
	do {
		std::cout << "첨가물을 추가하세요 (다 추가했으면 0): ";
		std::cin >> tmp;

		if (tmp < 0 || tmp > _cd->sizeofIngredientList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
		}
		else if (tmp == 0) {
			break;
		}
		else {
			newIngre.push_back(_cd->getDefaultIngredient(tmp - 1));
		}
	} while (tmp != 0);

	Coffee newCoffee(newCoffeeName, newBean, newIngre);
	_cd->addCoffee(newCoffee);
	return;
}

//커피 제거 함수
void deleteCoffee(CaffeData *_cd) {
	_cd->printDefaultCoffeeList();
	
	int toDelete = 0;
	do {
		std::cout << "삭제할 커피 번호를 입력하세요 (취소는 0): ";
		std::cin >> toDelete;

		if (toDelete < 0 || toDelete > _cd->sizeofCoffeeList()) {
			std::cout << "잘못된 입력입니다." << std::endl;
		}
		else if (toDelete == 0) {
			break;
		}
		else {
			_cd->deleteCoffee(toDelete - 1);
		}
	} while (toDelete != 0);
	return;
}

//커피에서 할 작업 선택하는 함수
void selectCoffeeSetting(CaffeData *_data) {
	printAddDeleteModify_Coffee();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//coffeebean addition
			addCoffeeBeanToCoffee(_data);
			break;
		case 2:
			//coffeebean deletion
			deleteCoffeeBeanFromCoffee(_data);
			break;
		case 3:
			//addon addition
			addIngredientToCoffee(_data);
			break;
		case 4:
			//addon deletion
			deleteIngredientFromCoffee(_data);
			break;
		case 5:
			//coffee addition
			addCoffee(_data);
			break;
		case 6:
			//coffee deletion
			deleteCoffee(_data);
			break;
		default:
			std::cout << "올바른 입력이 아닙니다." << std::endl;
		}
	} while (tmp < 1 || tmp > 6);

	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// 기능 제어 함수 ///////////////////////////////////

//main에서 2번이 눌렸을 경우 기능을 선택하는 함수
void dataSettingSelected(CaffeData *_data) {
	int tmp = 0;

	do {
		printDataSetting();
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//function which calls setting of coffeebean
			selectCoffeeBeanSetting(_data);
			break;
		case 2:
			//function which calls setting of addon
			selectIngredientSetting(_data);
			break;
		case 3:
			//function which calls setting of coffee itself
			selectCoffeeSetting(_data);
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
