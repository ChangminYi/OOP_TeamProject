#include "Func_CoffeeOrder.h"


/*
�ֹ��� �޴� �Լ�
Ŀ��, �ش� Ŀ�ǿ� �߰��ϰ� ���� ÷�����̳� ���θ� �����Ͽ� �߰� ����

*/

void coffeeOrderSelected(CaffeData* _cd) {
	CaffeData *currentData = _cd;
	std::vector<Coffee> orderedCoffeeList; //�ֹ��� Ŀ�� ���

	unsigned int orderdCoffeeNum, optionalCoffeeBeanNum, optionalIngreNum;
	char a = NULL, b = NULL, c = NULL;

	for (int i = 0; ; i++) {
		bool checkCustom = false; // �ֹ��� Ŀ�ǿ� �߰����� ������ ������������ üũ.

		std::cout << std::endl << "�ֹ��� Ŀ���� ��ȣ�� �Է��� �ּ���." << std::endl;
		currentData->printDefaultCoffeeList();
		std::cout << "�Է�: ";
		std::cin >> orderdCoffeeNum;
		orderedCoffeeList.push_back(currentData->getDefaultCoffee(orderdCoffeeNum - 1));

		for (int j = 0; ; j++) {
			std::cout << "���θ� �߰��Ͻðڽ��ϱ�?(Y/N): " << std::endl;
			std::cin >> a;
			if (a == 'N' || a == 'n') {
				break;
			}

			checkCustom = true;
			currentData->printDefaultCoffeeBeanList();
			std::cout << "�Է�: ";
			std::cin >> optionalCoffeeBeanNum;
			orderedCoffeeList.at(i).addBeanList(currentData->getDefaultCoffeeBean(optionalCoffeeBeanNum - 1));
		}

		for (int j = 0; ; j++) {
			std::cout << "÷������ �߰��Ͻðڽ��ϱ�?(Y/N): " << std::endl;
			std::cin >> b;
			if (b == 'N' || b == 'n') {
				break;
			}

			checkCustom = true;
			currentData->printDefaultIngredientList();
			std::cout << "�Է�: ";
			std::cin >> optionalIngreNum;
			orderedCoffeeList.at(i).addIngreList(currentData->getDefaultIngredient(optionalIngreNum - 1));
		}

		if (checkCustom) {
			std::cout << std::endl << "�⺻ �޴����� ������ �ִ� ��ǰ�� �����մϴ�." << std::endl << "�� ��ǰ�� �����Ͻðڽ��ϱ�?(Y/N): ";
			std::cin >> c;
			if (c == 'N' || c == 'n') {
				break;
			}

			std::string _newCoffeeName;
			std::cout << "�߰��� Ŀ���� �̸��� �Է����ּ���: ";
			std::getline(std::cin, _newCoffeeName);
			Coffee _newCoffee = Coffee(_newCoffeeName, orderedCoffeeList.at(i).getBeanList(), orderedCoffeeList.at(i).getIngreList());
			currentData->addCoffee(_newCoffee);
		}
	}

	makeBill(orderedCoffeeList);
}

/*
������ ���� �Լ�
�ֹ��� Ŀ�ǿ� �� ������ ���
*/

void makeBill(const std::vector<Coffee> _orderedCoffeeList) {
	std::cout << std::endl << "<�ֹ���>" << std::endl;

	for (int i = 0; i < _orderedCoffeeList.size(); i++) {
		std::cout << "  " << i + 1 << '.' << _orderedCoffeeList.at(i).getName() << ": " << _orderedCoffeeList.at(i).getCost() << "��" << std::endl;
	}

	std::cout << std::endl << std::endl;;
}