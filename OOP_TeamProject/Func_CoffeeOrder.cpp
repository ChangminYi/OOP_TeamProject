#include "Func_CoffeeOrder.h"

void coffeeOrderSelected() {
	std::vector<Coffee> orderedCoffeeList;

	unsigned int orderdCoffeeNum, optionalCoffeeBeanNum, optionalIngreNum;
	char a = NULL, b = NULL, c = NULL;

	for (int i = 0; ; i++) {

		std::cout << std::endl << "주문할 커피의 번호를 입력해 주세요." << std::endl;
		printDefaultCoffeeList();
		std::cout << "입력: ";
		std::cin >> orderdCoffeeNum;
		orderedCoffeeList.push_back(getDefaultCoffee(orderdCoffeeNum - 1));

		for (int j = 0; ; j++) {
			std::cout << "원두를 추가하시겠습니까?(Y/N): " << std::endl;
			std::cin >> a;
			if (a == 'N' || a == 'n') {
				break;
			}

			printDefaultCoffeeBeanList();
			std::cout << "입력: ";
			std::cin >> optionalCoffeeBeanNum;
			orderedCoffeeList.at(i).addBeanList(getDefaultCoffeeBean(optionalCoffeeBeanNum - 1));
		}

		for (int j = 0; ; j++) {
			std::cout << "첨가물을 추가하시겠습니까?(Y/N): " << std::endl;
			std::cin >> b;
			if (b == 'N' || b == 'n') {
				break;
			}

			printDefaultIngredientList();
			std::cout << "입력: ";
			std::cin >> optionalIngreNum;
			orderedCoffeeList.at(i).addIngreList(getDefaultIngredient(optionalIngreNum - 1));
		}

		std::cout << std::endl << "메뉴를 추가하시겠습니까?(Y/N): ";
		std::cin >> c;
		if (c == 'N' || c == 'n') {
			break;
		}
	}

	makeBill(orderedCoffeeList);
}

void makeBill(const std::vector<Coffee> _orderedCoffeeList) {
	std::cout << std::endl << "<주문서>" << std::endl;

	for (int i = 0; i < _orderedCoffeeList.size(); i++) {
		std::cout << "  " << i + 1 << '.' << _orderedCoffeeList.at(i).getName() << ": " << _orderedCoffeeList.at(i).getCost() << "원" << std::endl;
	}

	std::cout << std::endl << std::endl;;
}