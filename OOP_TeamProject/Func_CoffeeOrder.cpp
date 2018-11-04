#include "Func_CoffeeOrder.h"

void coffeeOrderSelected() {
	std::vector<Coffee> orderedCoffeeList;

	unsigned int orderdCoffeeNum, optionalCoffeeBeanNum, optionalIngreNum;
	char a = NULL, b = NULL, c = NULL;

	for (int i = 0; ; i++) {

		std::cout << std::endl << "�ֹ��� Ŀ���� ��ȣ�� �Է��� �ּ���." << std::endl;
		printDefaultCoffeeList();
		std::cout << "�Է�: ";
		std::cin >> orderdCoffeeNum;
		orderedCoffeeList.push_back(getDefaultCoffee(orderdCoffeeNum - 1));

		for (int j = 0; ; j++) {
			std::cout << "���θ� �߰��Ͻðڽ��ϱ�?(Y/N): " << std::endl;
			std::cin >> a;
			if (a == 'N' || a == 'n') {
				break;
			}

			printDefaultCoffeeBeanList();
			std::cout << "�Է�: ";
			std::cin >> optionalCoffeeBeanNum;
			orderedCoffeeList.at(i).addBeanList(getDefaultCoffeeBean(optionalCoffeeBeanNum - 1));
		}

		for (int j = 0; ; j++) {
			std::cout << "÷������ �߰��Ͻðڽ��ϱ�?(Y/N): " << std::endl;
			std::cin >> b;
			if (b == 'N' || b == 'n') {
				break;
			}

			printDefaultIngredientList();
			std::cout << "�Է�: ";
			std::cin >> optionalIngreNum;
			orderedCoffeeList.at(i).addIngreList(getDefaultIngredient(optionalIngreNum - 1));
		}

		std::cout << std::endl << "�޴��� �߰��Ͻðڽ��ϱ�?(Y/N): ";
		std::cin >> c;
		if (c == 'N' || c == 'n') {
			break;
		}
	}

	makeBill(orderedCoffeeList);
}

void makeBill(const std::vector<Coffee> _orderedCoffeeList) {
	std::cout << std::endl << "<�ֹ���>" << std::endl;

	for (int i = 0; i < _orderedCoffeeList.size(); i++) {
		std::cout << "  " << i + 1 << '.' << _orderedCoffeeList.at(i).getName() << ": " << _orderedCoffeeList.at(i).getCost() << "��" << std::endl;
	}

	std::cout << std::endl << std::endl;;
}