#include "Func_CoffeeOrder.h"
#include "CaffeClerk.h"

/*
�ֹ��� �޴� �Լ�
Ŀ��, �ش� Ŀ�ǿ� �߰��ϰ� ���� ÷�����̳� ���θ� �����Ͽ� �߰� ����
*/

void coffeeOrderSelected(CaffeData* _cd) {
	CaffeClerk clerk(_cd); // ī������ ��ü

	int orderedCoffeeNum = 0, optionalCoffeeBeanNum = 0, optionalIngreNum = 0;

	for (int i = 0; ; i++) {
		int firstBP = 0;
		char secondBP = NULL, thirdBP = NULL, fourthBP = NULL, fifthBP = NULL;
		bool checkCustom = false; // �ֹ��� Ŀ�ǿ� �߰����� ������ ������������ üũ.

		std::cout << "1. ���� �޴����� �ֹ��ϱ�" << std::endl << "2. ������ Ŀ�� �ֹ��ϱ�" << std::endl;
		std::cout << "�Է�: ";
		std::cin >> firstBP;

		if (firstBP == 2) { // ���� Ŀ�Ǹ� ������ ���� ����� ���(Func_dataSetting�� addCoffee �Լ� ����)
			std::string newCoffeeName = "������ Ŀ��";
			std::cout << "���ο� Ŀ�� �̸��� �Է��ϼ���: ";
			std::cin.ignore();
			std::getline(std::cin, newCoffeeName);

			int tmp = 0;
			std::vector<CoffeeBean *> newBean;
			clerk.getData()->printDefaultCoffeeBeanList();
			do {
				std::cout << "���θ� �߰��ϼ��� (�� �߰������� 0): ";
				std::cin >> tmp;

				if (tmp < 0 || tmp > clerk.getData()->sizeofCoffeeBeanList()) {
					std::cout << "�߸��� �Է��Դϴ�." << std::endl;
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
				std::cout << "÷������ �߰��ϼ��� (�� �߰������� 0): ";
				std::cin >> tmp;

				if (tmp < 0 || tmp > clerk.getData()->sizeofIngredientList()) {
					std::cout << "�߸��� �Է��Դϴ�." << std::endl;
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
			std::cout << "������ Ŀ�Ǹ� �����Ͻðڽ��ϱ�?(Y/N): ";
			char a = NULL;
			std::cin >> a;
			if (a == 'Y' || a == 'y') {
				clerk.getData()->addCoffee(newCustomCoffee);
			}
		}
		else { // ������ ����� �޴��� �������� �ֹ��ϴ� ���
			std::cout << std::endl << "�ֹ��� Ŀ���� ��ȣ�� �Է��� �ּ���." << std::endl;
			clerk.getData()->printDefaultCoffeeList();
			std::cout << "�Է�: ";
			std::cin >> orderedCoffeeNum;

			Coffee newCoffee = clerk.getData()->getDefaultCoffee(orderedCoffeeNum - 1);

			std::vector<CoffeeBean> *DefaultCoffeeBeanList = clerk.getData()->getDefaultCoffeeBeanList();
			std::vector<Ingredient> *DefaultIngredientList = clerk.getData()->getDefaultIngredientList();

			for ( ; ; ) {
				std::cout << "���θ� �߰��Ͻðڽ��ϱ�?(Y/N): ";
				std::cin >> secondBP;
				if (secondBP == 'N' || secondBP == 'n') {
					break;
				}

				checkCustom = true;
				clerk.getData()->printDefaultCoffeeBeanList();
				std::cout << "�Է�: ";
				std::cin >> optionalCoffeeBeanNum;

				newCoffee.addBeanList(&DefaultCoffeeBeanList->at(optionalCoffeeBeanNum - 1));
			}

			for ( ; ; ) {
				std::cout << "÷������ �߰��Ͻðڽ��ϱ�?(Y/N): ";
				std::cin >> thirdBP;
				if (thirdBP == 'N' || thirdBP == 'n') {
					break;
				}

				checkCustom = true;
				clerk.getData()->printDefaultIngredientList();
				std::cout << "�Է�: ";
				std::cin >> optionalIngreNum;
				
				newCoffee.addIngreList(&DefaultIngredientList->at(optionalIngreNum - 1));
			}

			if (checkCustom) {
				std::cout << std::endl << "�⺻ �޴����� ������ �ִ� ��ǰ�� �����մϴ�." << std::endl << "�� ��ǰ�� �����Ͻðڽ��ϱ�?(Y/N): ";
				std::cin >> fourthBP;
				if (fourthBP == 'Y' || fourthBP == 'y') {


					std::string _newCoffeeName;
					std::cout << "�߰��� Ŀ���� �̸��� �Է����ּ���: ";
					std::cin >> _newCoffeeName;
					newCoffee.setName(_newCoffeeName);
					//Coffee _newCoffee = Coffee(_newCoffeeName, clerk.getOrderedList().at(i).getBeanList(), clerk.getOrderedList().at(i).getIngreList());
					clerk.saveCustom(newCoffee);
				}
			}

			clerk.addOrder(newCoffee);

			std::cout << "�ֹ��� ��� �Ͻðڽ��ϱ�?(Y/N): ";
			std::cin >> fifthBP;
			if (fifthBP == 'N' || fifthBP == 'n') {
				break;
			}
		}
	}

	clerk.makeBill();
}