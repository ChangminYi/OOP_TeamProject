#include "Func_CoffeeOrder.h"
#include "GlobalVar.h"
#include "Order.h"

void coffeeOrderSelected() {
	int orderdCoffeeNum;
	char a = NULL;

	do {
		std::cout << std::endl << "�ֹ��� Ŀ���� ��ȣ�� �Է��� �ּ���." << std::endl;
		printDefaultCoffeeList();
		std::cout << "�Է�: ";
		std::cin >> orderdCoffeeNum;

		std::cout << std::endl << "�޴��� �߰��Ͻðڽ��ϱ�?(Y/N): ";
		std::cin >> a;
	} while (a == 'Y' || a == 'y');


}

void makeBill() {
	std::vector<Coffee> orderedCoffeeList;
	std::vector<CoffeeBean> orderedCoffeeBeanList;
	std::vector<Ingredient> orderedIngreList;

}