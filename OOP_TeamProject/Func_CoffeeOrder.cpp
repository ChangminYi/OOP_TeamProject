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
		char secondBP = NULL, thirdBP = NULL;
		bool checkCustom = false; // �ֹ��� Ŀ�ǿ� �߰����� ������ ������������ üũ.

		do {
			std::cout << "1. ���� �޴����� �ֹ��ϱ�" << std::endl << "2. ������ Ŀ�� �ֹ��ϱ�" << std::endl;
			std::cout << "�Է�: ";
			std::cin >> firstBP;
			if (firstBP != 1 && firstBP != 2) {
				std::cout << "�߸��� �Է��Դϴ�. " << std::endl;
			}
			else {
				break;
			}
		} while (firstBP == 1 || firstBP == 2);

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

			while(1){
				char a = NULL;
				std::cout << "������ Ŀ�Ǹ� �����Ͻðڽ��ϱ�?(Y/N): ";
				std::cin >> a;
				if (a == 'Y') {
					clerk.getData()->addCoffee(newCustomCoffee);
					break;
				}
				else if (a == 'N') {
					break;
				}
				else {
					std::cout << "�߸��� �Է��Դϴ�." << std::endl;
				}
			}
		}
		else { // ������ ����� �޴��� �������� �ֹ��ϴ� ���
			clerk.getData()->printDefaultCoffeeList();
			std::cout << std::endl << "�ֹ��� Ŀ���� ��ȣ�� �Է��� �ּ���." << std::endl;
			while(1) {
				std::cout << "�Է�: ";
				if (orderedCoffeeNum > 0 || orderedCoffeeNum <= clerk.getData()->sizeofCoffeeList()) {
					std::cin >> orderedCoffeeNum;

					break;
				}
				std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			}

			Coffee newCoffee = clerk.getData()->getDefaultCoffee(orderedCoffeeNum - 1);

			std::vector<CoffeeBean> *DefaultCoffeeBeanList = clerk.getData()->getDefaultCoffeeBeanList();
			std::vector<Ingredient> *DefaultIngredientList = clerk.getData()->getDefaultIngredientList();

			clerk.getData()->printDefaultCoffeeBeanList();
			do {
				std::cout << "�߰��� ���� ��ȣ�� �Է����ּ���(�� �߰������� 0): ";
				std::cin >> optionalCoffeeBeanNum;
				if (optionalCoffeeBeanNum < 0 || optionalCoffeeBeanNum > clerk.getData()->sizeofCoffeeBeanList()) {
					std::cout << "�߸��� �Է��Դϴ�" << std::endl;
					continue;
				}
				else if (optionalCoffeeBeanNum == 0) {
					break;
				}
				else {
					checkCustom = true;
					newCoffee.addBeanList(&DefaultCoffeeBeanList->at(optionalCoffeeBeanNum - 1));
				}
			} while (optionalCoffeeBeanNum != 0);

			clerk.getData()->printDefaultIngredientList();
			do {
				std::cout << "�߰��� ÷���� ��ȣ�� �Է����ּ���(�� �߰������� 0): ";
				std::cin >> optionalIngreNum;
				if (optionalIngreNum < 0 || optionalIngreNum > clerk.getData()->sizeofIngredientList()) {
					std::cout << "�߸��� �Է��Դϴ�" << std::endl;
				}
				else if (optionalIngreNum == 0) {
					break;
				}
				else {
					checkCustom = true;
					newCoffee.addIngreList(&DefaultIngredientList->at(optionalIngreNum - 1));
				}
			} while (optionalIngreNum != 0);

			if (checkCustom) {
				while(1) {
					std::cout << std::endl << "�⺻ �޴����� ������ �ִ� ��ǰ�� �����մϴ�." << std::endl << "�� ��ǰ�� �����Ͻðڽ��ϱ�?(Y/N): ";
					std::cin >> secondBP;

					if (secondBP == 'Y') {
						std::string newCoffeeName;
						std::cout << "�߰��� Ŀ���� �̸��� �Է����ּ���: ";
						std::cin >> newCoffeeName;
						newCoffee.setName(newCoffeeName);
						clerk.saveCustom(newCoffee);
						break;
					}
					else if (secondBP == 'N') {
						break;
					}
					else {
						std::cout << "�߸��� �Է��Դϴ�" << std::endl;
					}

				}
			}
			clerk.addOrder(newCoffee);
		}

		std::cout << "�ֹ��� ��� �Ͻðڽ��ϱ�?(Y/N): ";
		std::cin >> thirdBP;
		while(1){
			if (thirdBP == 'N') {
				clerk.makeBill();
				return;
			}
			else if (thirdBP == 'Y') {
				break;
			}
			else {
				std::cout << "�߸��� �Է��Դϴ�" << std::endl;
			}
		}
	}
}