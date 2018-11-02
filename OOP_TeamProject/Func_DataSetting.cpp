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
	std::cout << "  1. ���� �߰�" << std::endl;
	std::cout << "  2. ���� ����" << std::endl;
	std::cout << "  3. ÷���� �߰�" << std::endl;
	std::cout << "  4. ÷���� ����" << std::endl;
	std::cout << "  5. Ŀ�� �߰�" << std::endl;
	std::cout << "  6. Ŀ�� ����" << std::endl;
	std::cout << "����: ";
	return;
}

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

//Ŀ�ǿ��� �� �۾� �����ϴ� �Լ�
void selectCoffeeSetting() {
	printAddDeleteModify_Coffee();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//coffeebean addition
			break;
		case 2:
			//coffeebean deletion
			break;
		case 3:
			//addon addition
			break;
		case 4:
			//addon deletion
			break;
		case 5:
			//coffee addition
			break;
		case 6:
			//coffee deletion
			break;
		default:
			std::cout << "�ùٸ� �Է��� �ƴմϴ�." << std::endl;
		}
	} while (tmp < 1 || tmp > 6);

	return;
}

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
