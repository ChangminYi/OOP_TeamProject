#include "Func_CoffeeOrder.h"
#include "GlobalVar.h"
#include "Order.h"

void coffeeOrderSelected() {
	int orderdCoffeeNum;
	char a = NULL;

	do {
		std::cout << std::endl << "주문할 커피의 번호를 입력해 주세요." << std::endl;
		printDefaultCoffeeList();
		std::cout << "입력: ";
		std::cin >> orderdCoffeeNum;

		std::cout << std::endl << "메뉴를 추가하시겠습니까?(Y/N): ";
		std::cin >> a;
	} while (a == 'Y' || a == 'y');


}

void makeBill() {
	std::vector<Coffee> orderedCoffeeList;
	std::vector<CoffeeBean> orderedCoffeeBeanList;
	std::vector<Ingredient> orderedIngreList;

}