#include "Func_CoffeeOrder.h"
#include "CaffeClerk.h"

/*
주문을 받는 함수
커피, 해당 커피에 추가하고 싶은 첨가물이나 원두를 선택하여 추가 가능
*/

void coffeeOrderSelected(CaffeData* _cd) {
	CaffeClerk clerk(_cd); // 카페점원 객체

	int orderedCoffeeNum = 0, optionalCoffeeBeanNum = 0, optionalIngreNum = 0;

	for (int i = 0; ; i++) {
		int firstBP = 0;
		char secondBP = NULL, thirdBP = NULL, fourthBP = NULL, fifthBP = NULL;
		bool checkCustom = false; // 주문된 커피에 추가적인 수정이 가해졌는지를 체크.

		std::cout << "1. 기존 메뉴에서 주문하기" << std::endl << "2. 나만의 커피 주문하기" << std::endl;
		std::cout << "입력: ";
		std::cin >> firstBP;

		if (firstBP == 2) { // 고객이 커피를 완전히 새로 만드는 경우(Func_dataSetting의 addCoffee 함수 따옴)
			std::string newCoffeeName = "나만의 커피";
			std::cout << "새로운 커피 이름을 입력하세요: ";
			std::cin.ignore();
			std::getline(std::cin, newCoffeeName);

			int tmp = 0;
			std::vector<CoffeeBean *> newBean;
			clerk.getData()->printDefaultCoffeeBeanList();
			do {
				std::cout << "원두를 추가하세요 (다 추가했으면 0): ";
				std::cin >> tmp;

				if (tmp < 0 || tmp > clerk.getData()->sizeofCoffeeBeanList()) {
					std::cout << "잘못된 입력입니다." << std::endl;
					continue;
				}
				else if (tmp == 0) {
					break;
				}
				else {
					newBean.push_back(&clerk.getData()->getDefaultCoffeeBeanList()->at(tmp - 1));
				}
			} while (tmp != 0);

			tmp = 0;
			std::vector<Ingredient *> newIngre;
			clerk.getData()->printDefaultIngredientList();
			do {
				std::cout << "첨가물을 추가하세요 (다 추가했으면 0): ";
				std::cin >> tmp;

				if (tmp < 0 || tmp > clerk.getData()->sizeofIngredientList()) {
					std::cout << "잘못된 입력입니다." << std::endl;
				}
				else if (tmp == 0) {
					break;
				}
				else {
					newIngre.push_back(&clerk.getData()->getDefaultIngredientList()->at(tmp - 1));
				}
			} while (tmp != 0);

			Coffee newCustomCoffee(newCoffeeName, newBean, newIngre);
			clerk.addOrder(newCustomCoffee);
			std::cout << "나만의 커피를 저장하시겠습니까?(Y/N): ";
			char a = NULL;
			std::cin >> a;
			if (a == 'Y' || a == 'y') {
				clerk.getData()->addCoffee(newCustomCoffee);
			}
		}
		else { // 기존에 저장된 메뉴를 바탕으로 주문하는 경우
			std::cout << std::endl << "주문할 커피의 번호를 입력해 주세요." << std::endl;
			clerk.getData()->printDefaultCoffeeList();
			std::cout << "입력: ";
			std::cin >> orderedCoffeeNum;

			Coffee newCoffee = clerk.getData()->getDefaultCoffee(orderedCoffeeNum - 1);

			std::vector<CoffeeBean> *DefaultCoffeeBeanList = clerk.getData()->getDefaultCoffeeBeanList();
			std::vector<Ingredient> *DefaultIngredientList = clerk.getData()->getDefaultIngredientList();

			for ( ; ; ) {
				std::cout << "원두를 추가하시겠습니까?(Y/N): ";
				std::cin >> secondBP;
				if (secondBP == 'N' || secondBP == 'n') {
					break;
				}

				checkCustom = true;
				clerk.getData()->printDefaultCoffeeBeanList();
				std::cout << "입력: ";
				std::cin >> optionalCoffeeBeanNum;

				newCoffee.addBeanList(&DefaultCoffeeBeanList->at(optionalCoffeeBeanNum - 1));
			}

			for ( ; ; ) {
				std::cout << "첨가물을 추가하시겠습니까?(Y/N): ";
				std::cin >> thirdBP;
				if (thirdBP == 'N' || thirdBP == 'n') {
					break;
				}

				checkCustom = true;
				clerk.getData()->printDefaultIngredientList();
				std::cout << "입력: ";
				std::cin >> optionalIngreNum;
				
				newCoffee.addIngreList(&DefaultIngredientList->at(optionalIngreNum - 1));
			}

			if (checkCustom) {
				std::cout << std::endl << "기본 메뉴에서 변동이 있는 상품이 존재합니다." << std::endl << "이 상품을 저장하시겠습니까?(Y/N): ";
				std::cin >> fourthBP;
				if (fourthBP == 'Y' || fourthBP == 'y') {


					std::string _newCoffeeName;
					std::cout << "추가할 커피의 이름을 입력해주세요: ";
					std::cin >> _newCoffeeName;
					newCoffee.setName(_newCoffeeName);
					//Coffee _newCoffee = Coffee(_newCoffeeName, clerk.getOrderedList().at(i).getBeanList(), clerk.getOrderedList().at(i).getIngreList());
					clerk.saveCustom(newCoffee);
				}
			}

			clerk.addOrder(newCoffee);

			std::cout << "주문을 계속 하시겠습니까?(Y/N): ";
			std::cin >> fifthBP;
			if (fifthBP == 'N' || fifthBP == 'n') {
				break;
			}
		}
	}

	clerk.makeBill();
}