#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#include "GlobalVar.h"
#include "Func_DataSetting.h"
#include "Order.h"

//global variables (in GlobalVar.cpp)
extern std::vector<CoffeeBean> defaultCoffeeBeanList;
extern std::vector<Ingredient> defaultIngredientList;
extern std::vector<Coffee> defaultCoffeeList;
extern std::vector<Order> customOrderList;
extern CoffeeBean defaultCoffeeBean;


/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// ȭ�� ��� �Լ� /////////////////////////////////////

//Ŀ���� ���� ����ϴ� �Լ�
void printCoffeeBeanOfCoffee(Coffee arg) {
	for (int i = 0; i < arg.getBeanList().size(); i++) {
		std::cout << "      " << i + 1 << ". " << arg.getBeanList().at(i).getName() << std::endl;
	}

	return;
}

//Ŀ���� ÷���� ����ϴ� �Լ�
void printIngredientOfCoffee(Coffee arg) {
	for (int i = 0; i < arg.getIngreList().size(); i++) {
		std::cout << "      " << i + 1 << ". " << arg.getIngreList().at(i).getName() << std::endl;
	}

	return;
}

//main���� 2���� ������ ��� ȭ���� ����ϴ� �Լ�
void printDataSetting() {
	std::cout << "  1. ����" << std::endl;
	std::cout << "  2. ÷����" << std::endl;
	std::cout << "  3. Ŀ��" << std::endl;
	std::cout << "  4. ���" << std::endl;
	std::cout << "����: ";
	return;
}

//���ο� ÷���� ��� ���� ȭ��
void printAddDeleteModify() {
	std::cout << "  1. �߰�" << std::endl;
	std::cout << "  2. ����" << std::endl;
	std::cout << "  3. ����" << std::endl;
	std::cout << "����: ";
	return;
}

//Ŀ�� ��� ���� ȭ��
void printAddDeleteModify_Coffee() {
	std::cout << "  1. Ŀ�ǿ� ���� �߰�" << std::endl;
	std::cout << "  2. Ŀ�ǿ��� ���� ����" << std::endl;
	std::cout << "  3. Ŀ�ǿ� ÷���� �߰�" << std::endl;
	std::cout << "  4. Ŀ�ǿ��� ÷���� ����" << std::endl;
	std::cout << "  5. Ŀ�� �߰�" << std::endl;
	std::cout << "  6. Ŀ�� ����" << std::endl;
	std::cout << "����: ";
	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// Ŀ���� ���� �Լ� ////////////////////////////////////

//���� �߰� �Լ�
void addCoffeeBean() {
	std::string newCoffeeBeanName;
	unsigned int newCost = 0;

	std::cout << "�߰��� ���� �̸�: ";
	std::cin.ignore();
	std::getline(std::cin, newCoffeeBeanName);
	std::cout << "���� ����: ";
	std::cin >> newCost;

	defaultCoffeeBeanList.push_back(CoffeeBean(newCoffeeBeanName, newCost));
	
	return;
}

//���� ���� �Լ�
void deleteCoffeeBean() {
	printDefaultCoffeeBeanList();

	int idx = 0;
	do {
		std::cout << "������ ���� ��ȣ: ";
		std::cin >> idx;
	} while (idx < 1 || idx > defaultCoffeeBeanList.size());

	defaultCoffeeBeanList.erase(defaultCoffeeBeanList.begin() + (idx - 1));

	return;
}

//���� ���� �Լ�
void modifyCoffeeBean() {
	printDefaultCoffeeBeanList();
	
	int idx = 0;
	do {
		std::cout << "������ ���� ��ȣ: ";
		std::cin >> idx;
	} while (idx < 1 || idx > defaultCoffeeBeanList.size());

	//�̸� ����
	char yn = 0;
	do {
		std::cout << "�̸��� �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		std::string newName = defaultCoffeeBeanList.at(idx - 1).getName();
		std::cout << "�� �̸��� �Է��ϼ���: ";
		std::cin.ignore();
		std::getline(std::cin, newName);
		defaultCoffeeBeanList.at(idx - 1).setName(newName);
	}

	//���� ����
	yn = 0;
	do {
		std::cout << "������ �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		unsigned int newCost = defaultCoffeeBeanList.at(idx - 1).getCost();
		std::cout << "�� ������ �Է��ϼ���: ";
		std::cin >> newCost;
		defaultCoffeeBeanList.at(idx - 1).setCost(newCost);
	}
	
	return;
}

//���ο��� �� �۾� �����ϴ� �Լ�
void selectCoffeeBeanSetting() {
	printAddDeleteModify();
	
	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			addCoffeeBean();
			break;
		case 2:
			//deletion
			deleteCoffeeBean();
			break;
		case 3:
			//modify
			modifyCoffeeBean();
			break;
		default:
			std::cout << "�ùٸ� �Է��� �ƴմϴ�." << std::endl;
		}
	} while (tmp < 1 || tmp > 3);

	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// ÷���� ���� �Լ� ////////////////////////////////////

//÷���� �߰� �Լ�
void addIngredient() {
	std::string newIngredientName;
	unsigned int newCost = 0;

	std::cout << "�߰��� ÷���� �̸�: ";
	std::cin.ignore();
	std::getline(std::cin, newIngredientName);
	std::cout << "÷���� ����: ";
	std::cin >> newCost;

	defaultIngredientList.push_back(Ingredient(newIngredientName, newCost));

	return;
}

//÷���� ���� �Լ�
void deleteIngredient() {
	printDefaultIngredientList();

	int idx = 0;
	do {
		std::cout << "������ ÷���� ��ȣ: ";
		std::cin >> idx;
	} while (idx < 1 || idx > defaultIngredientList.size());

	defaultIngredientList.erase(defaultIngredientList.begin() + (idx - 1));

	return;
}

//÷���� ���� �Լ�
void modifyIngredient() {
	printDefaultIngredientList();

	int idx = 0;
	do {
		std::cout << "������ ÷���� ��ȣ: ";
		std::cin >> idx;
	} while (idx < 1 || idx > defaultIngredientList.size());

	//�̸� ����
	char yn = 0;
	do {
		std::cout << "�̸��� �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		std::string newName = defaultIngredientList.at(idx - 1).getName();
		std::cout << "�� �̸��� �Է��ϼ���: ";
		std::cin.ignore();
		std::getline(std::cin, newName);
		defaultIngredientList.at(idx - 1).setName(newName);
	}

	//���� ����
	yn = 0;
	do {
		std::cout << "������ �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		unsigned int newCost = defaultIngredientList.at(idx - 1).getCost();
		std::cout << "�� ������ �Է��ϼ���: ";
		std::cin >> newCost;
		defaultIngredientList.at(idx - 1).setCost(newCost);
	}

	return;
}

//÷�������� �� �۾� �����ϴ� �Լ�
void selectIngredientSetting() {
	printAddDeleteModify();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			addIngredient();
			break;
		case 2:
			//deletion
			deleteIngredient();
			break;
		case 3:
			//modify
			modifyIngredient();
			break;
		default:
			std::cout << "�ùٸ� �Է��� �ƴմϴ�." << std::endl;
		}
	} while (tmp < 1 || tmp > 3);

	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Ŀ�� ���� �Լ� ////////////////////////////////////

//Ŀ�ǿ� Ŀ���� �߰� �Լ�
void addCoffeeBeanToCoffee() {
	printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "Ŀ������ �߰��� Ŀ�� ��ȣ�� ������ �ּ���: ";
		std::cin >> idx_coffee;
	} while (idx_coffee < 1 || idx_coffee > defaultCoffeeList.size());

	printDefaultCoffeeBeanList();
	int idx_bean = 0;
	do {
		do {
			std::cout << "�߰��� ���� ��ȣ�� ������ �ּ��� (�� �߰������� 0): ";
			std::cin >> idx_bean;
		} while (idx_bean < 0 || idx_bean > defaultCoffeeBeanList.size());

		if (idx_bean != 0) {
			defaultCoffeeList.at(idx_coffee - 1).addBeanList(defaultCoffeeBeanList.at(idx_bean - 1));
		}
	} while (idx_bean != 0);

	return;
}

//Ŀ�ǿ� Ŀ�ǰ� ���� �Լ�
void deleteCoffeeBeanFromCoffee() {
	printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "Ŀ������ ������ Ŀ�� ��ȣ�� ������ �ּ���: ";
		std::cin >> idx_coffee;
	} while (idx_coffee < 1 || idx_coffee > defaultCoffeeList.size());

	Coffee &toRemove = defaultCoffeeList.at(idx_coffee - 1);

	int idx_bean = 0;
	do {
		do {
			if (toRemove.getBeanList().empty()) {
				std::cout << "���ΰ� �����ϴ�." << std::endl;
				idx_bean = 0;
				break;
			}
			else {
				printCoffeeBeanOfCoffee(toRemove);

				std::cout << "������ ���� ��ȣ�� ������ �ּ��� (�� ���������� 0): ";
				std::cin >> idx_bean;

				if (idx_bean > 0) {
					toRemove.removeBeanList(idx_bean - 1);
				}
			}
		} while (idx_bean != 0);
	} while (idx_bean < 0 || idx_bean > toRemove.getBeanList().size());

	return;
}

//Ŀ�ǿ� ÷���� �߰� �Լ�
void addIngredientToCoffee() {
	printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "÷������ �߰��� Ŀ�� ��ȣ�� ������ �ּ���: ";
		std::cin >> idx_coffee;
	} while (idx_coffee < 1 || idx_coffee>defaultCoffeeList.size());

	printDefaultIngredientList();
	int idx_ingre = 0;
	do {
		do {
			std::cout << "�߰��� ÷���� ��ȣ�� ������ �ּ��� (�� �߰������� 0): ";
			std::cin >> idx_ingre;
		} while (idx_ingre < 0 || idx_ingre > defaultCoffeeBeanList.size());

		if (idx_ingre != 0) {
			defaultCoffeeList.at(idx_coffee - 1).addIngreList(defaultIngredientList.at(idx_ingre - 1));
		}
	} while (idx_ingre != 0);

	return;
}

//Ŀ�ǿ� ÷���� ���� �Լ�
void deleteIngredientFromCoffee() {
	printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "Ŀ������ ������ Ŀ�� ��ȣ�� ������ �ּ���: ";
		std::cin >> idx_coffee;
	} while (idx_coffee < 1 || idx_coffee > defaultCoffeeList.size());

	Coffee &toRemove = defaultCoffeeList.at(idx_coffee - 1);

	int idx_ingre = 0;
	do {
		do {
			if (toRemove.getIngreList().empty()) {
				std::cout << "÷������ �����ϴ�." << std::endl;
				idx_ingre = 0;
				break;
			}
			else {
				printIngredientOfCoffee(toRemove);

				std::cout << "������ ÷���� ��ȣ�� ������ �ּ��� (�� ���������� 0): ";
				std::cin >> idx_ingre;

				if (idx_ingre > 0) {
					toRemove.removeIngreList(idx_ingre - 1);
				}
			}
		} while (idx_ingre != 0);
	} while (idx_ingre < 0 || idx_ingre > toRemove.getIngreList().size());

	return;
}

//Ŀ�� �߰� �Լ�
void addCoffee() {

}

//Ŀ�� ���� �Լ�
void deleteCoffee() {

	return;
}

//Ŀ�ǿ��� �� �۾� �����ϴ� �Լ�
void selectCoffeeSetting() {
	printAddDeleteModify_Coffee();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//coffeebean addition
			addCoffeeBeanToCoffee();
			break;
		case 2:
			//coffeebean deletion
			deleteCoffeeBeanFromCoffee();
			break;
		case 3:
			//addon addition
			addIngredientToCoffee();
			break;
		case 4:
			//addon deletion
			deleteIngredientFromCoffee();
			break;
		case 5:
			//coffee addition
			addCoffee();
			break;
		case 6:
			//coffee deletion
			deleteCoffee();
			break;
		default:
			std::cout << "�ùٸ� �Է��� �ƴմϴ�." << std::endl;
		}
	} while (tmp < 1 || tmp > 6);

	return;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// ��� ���� �Լ� ///////////////////////////////////

//main���� 2���� ������ ��� ����� �����ϴ� �Լ�
void dataSettingSelected() {
	int tmp = 0;

	do {
		printDataSetting();
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//function which calls setting of coffeebean
			selectCoffeeBeanSetting();
			break;
		case 2:
			//function which calls setting of addon
			selectIngredientSetting();
			break;
		case 3:
			//function which calls setting of coffee itself
			selectCoffeeSetting();
			break;
		case 4:
			//end of data setting
			return;
		default:
			std::cout << "�ùٸ� �Է��� �ƴմϴ�." << std::endl;
		}
	} while (tmp < 1 || tmp > 4);

	return;
}
