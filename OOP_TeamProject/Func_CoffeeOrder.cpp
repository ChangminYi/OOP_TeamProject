#include "Func_CoffeeOrder.h"


/*
주문을 받는 함수
커피, 해당 커피에 추가하고 싶은 첨가물이나 원두를 선택하여 추가 가능

*/

void coffeeOrderSelected(CaffeData* _cd) {
	CaffeData *currentData = _cd;
	std::vector<Coffee> orderedCoffeeList; //주문한 커피 목록

	unsigned int orderdCoffeeNum, optionalCoffeeBeanNum, optionalIngreNum;
	char a = NULL, b = NULL, c = NULL;

	for (int i = 0; ; i++) {
		bool checkCustom = false; // 주문된 커피에 추가적인 수정이 가해졌는지를 체크.

		std::cout << std::endl << "주문할 커피의 번호를 입력해 주세요." << std::endl;
		currentData->printDefaultCoffeeList();
		std::cout << "입력: ";
		std::cin >> orderdCoffeeNum;
		orderedCoffeeList.push_back(currentData->getDefaultCoffee(orderdCoffeeNum - 1));

		for (int j = 0; ; j++) {
			std::cout << "원두를 추가하시겠습니까?(Y/N): " << std::endl;
			std::cin >> a;
			if (a == 'N' || a == 'n') {
				break;
			}

			checkCustom = true;
			currentData->printDefaultCoffeeBeanList();
			std::cout << "입력: ";
			std::cin >> optionalCoffeeBeanNum;
			orderedCoffeeList.at(i).addBeanList(currentData->getDefaultCoffeeBean(optionalCoffeeBeanNum - 1));
		}

		for (int j = 0; ; j++) {
			std::cout << "첨가물을 추가하시겠습니까?(Y/N): " << std::endl;
			std::cin >> b;
			if (b == 'N' || b == 'n') {
				break;
			}

			checkCustom = true;
			currentData->printDefaultIngredientList();
			std::cout << "입력: ";
			std::cin >> optionalIngreNum;
			orderedCoffeeList.at(i).addIngreList(currentData->getDefaultIngredient(optionalIngreNum - 1));
		}

		if (checkCustom) {
			std::cout << std::endl << "기본 메뉴에서 변동이 있는 상품이 존재합니다." << std::endl << "이 상품을 저장하시겠습니까?(Y/N): ";
			std::cin >> c;
			if (c == 'N' || c == 'n') {
				break;
			}

			std::string _newCoffeeName;
			std::cout << "추가할 커피의 이름을 입력해주세요: ";
			std::getline(std::cin, _newCoffeeName);
			Coffee _newCoffee = Coffee(_newCoffeeName, orderedCoffeeList.at(i).getBeanList(), orderedCoffeeList.at(i).getIngreList());
			currentData->addCoffee(_newCoffee);
		}
	}

	makeBill(orderedCoffeeList);
}

/*
영수증 생성 함수
주문한 커피와 그 가격을 출력
*/

void makeBill(const std::vector<Coffee> _orderedCoffeeList) {
	std::cout << std::endl << "<주문서>" << std::endl;

	for (int i = 0; i < _orderedCoffeeList.size(); i++) {
		std::cout << "  " << i + 1 << '.' << _orderedCoffeeList.at(i).getName() << ": " << _orderedCoffeeList.at(i).getCost() << "원" << std::endl;
	}

	std::cout << std::endl << std::endl;;
}