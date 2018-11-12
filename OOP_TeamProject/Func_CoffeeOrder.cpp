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

		if (firstBP == 2) { // ���� Ŀ�Ǹ� ������ ���� ����� ���
			int numOfBean = 0, numOfIngre = 0;
			std::string customName;

			std::cout << std::endl << "����, Ŀ���� �̸��� �����ּž� �մϴ�." << std::endl;
			std::cout << "Ŀ���� �̸��� �Է����ּ���: ";
			std::cin >> customName;
			Coffee customCoffee(customName);

			std::cout << std::endl << "���� Ŀ�ǿ� �� ���θ� �����ؾ� �մϴ�. ";
			std::cout << "���� ���� ī�信�� " << clerk.getData()->sizeofCoffeeBeanList() << "������ Ŀ�� ���ΰ� �ֽ��ϴ�." << std::endl;
			std::cout << "Ŀ�ǿ� �߰��ϰ��� �ϴ� ������ �������� �Է����ּ���: ";
			std::cin >> numOfBean;

			for (int i = 0; i < numOfBean; i++) {
				int _beanNum = 0;

				clerk.getData()->printDefaultCoffeeBeanList();
				std::cout << std::endl << "�߰��ϰ��� �ϴ� ������ ��ȣ�� �Է����ּ���: ";
				std::cin >> _beanNum;
				customCoffee.addBeanList(clerk.getData()->getDefaultCoffeeBean(_beanNum - 1));
			}

			std::cout << std::endl << "�������� Ŀ�ǿ� �� ÷������ �����ؾ� �մϴ�. ";
			std::cout << "���� ���� ī�信�� " << clerk.getData()->sizeofIngredientList() << "������ ÷������ �ֽ��ϴ�." << std::endl;
			std::cout << "Ŀ�ǿ� �߰��ϰ��� �ϴ� ÷������ �������� �Է����ּ���: ";
			std::cin >> numOfIngre;

			for (int i = 0; i < numOfIngre; i++) {
				int _ingreNum = 0;

				clerk.getData()->printDefaultIngredientList();
				std::cout << std::endl << "�߰��ϰ��� �ϴ� ÷������ ��ȣ�� �Է����ּ���: ";
				std::cin >> _ingreNum;
				customCoffee.addIngreList(clerk.getData()->getDefaultIngredient(_ingreNum - 1));
			}

			clerk.saveCustom(customCoffee);
			std::cout << "��� �۾��� �Ϸ�Ǿ����ϴ�. ���� '�����޴� �ֹ��ϱ�'�� ���� �߰��� Ŀ�Ǹ� �ֹ��� �� �ֽ��ϴ�!" << std::endl << std::endl;
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

			std::cout << "�ֹ��� ��� �Ͻðڽ��ϱ�?(Y/N)" << std::endl;
			std::cin >> fifthBP;
			if (fifthBP == 'N' || fifthBP == 'n') {
				break;
			}
		}
	}

	clerk.makeBill();
}