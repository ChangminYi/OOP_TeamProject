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

#include "CaffeData.h"
#include "Func_DataSetting.h"
#include "Order.h"



/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// ȭ�� ��� �Լ� /////////////////////////////////////

//Ŀ���� ���� ����ϴ� �Լ�
void printCoffeeBeanOfCoffee(Coffee *arg) {
	for (int i = 0; i < arg->getBeanList().size(); i++) {
		std::cout << "      " << i + 1 << ". " << arg->getBeanList().at(i)->getName() << std::endl;
	}

	return;
}

//Ŀ���� ÷���� ����ϴ� �Լ�
void printIngredientOfCoffee(Coffee *arg) {
	for (int i = 0; i < arg->getIngreList().size(); i++) {
		std::cout << "      " << i + 1 << ". " << arg->getIngreList().at(i)->getName() << std::endl;
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
void addCoffeeBean(CaffeData *_caffeData) {
	std::string newCoffeeBeanName;
	unsigned int newCost = 0;

	std::cout << "�߰��� ���� �̸�: ";
	std::cin.ignore();
	std::getline(std::cin, newCoffeeBeanName);
	std::cout << "���� ����: ";
	std::cin >> newCost;

	_caffeData->addCoffeeBean(CoffeeBean(newCoffeeBeanName, newCost));
	
	return;
}

//���� ���� �Լ�
void deleteCoffeeBean(CaffeData *_caffeData) {
	_caffeData->printDefaultCoffeeBeanList();

	int idx = 0;
	do {
		std::cout << "������ ���� ��ȣ (��Ҵ� 0): ";
		std::cin >> idx;

		if (idx < 0 || idx > _caffeData->sizeofCoffeeBeanList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx == 0) {
			break;
		}
		else {
			_caffeData->deleteCoffeeBean(idx - 1);
		}
	} while (idx < 0 || idx > _caffeData->sizeofCoffeeBeanList());

	return;
}

//���� ���� �Լ�
void modifyCoffeeBean(CaffeData *_caffeData) {
	_caffeData->printDefaultCoffeeBeanList();
	
	int idx = 0;
	do {
		std::cout << "������ ���� ��ȣ (��Ҵ� 0): ";
		std::cin >> idx;

		if (idx > _caffeData->sizeofCoffeeBeanList() || idx < 0) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx == 0) {
			return;
		}
	} while (idx < 0 || idx > _caffeData->sizeofCoffeeBeanList());

	//�̸� ����
	char yn = 0;
	do {
		std::cout << "�̸��� �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		std::string newName = _caffeData->getDefaultCoffeeBean(idx - 1).getName();
		std::cout << "�� �̸��� �Է��ϼ���: ";
		std::cin.ignore();
		std::getline(std::cin, newName);
		_caffeData->getDefaultCoffeeBean(idx - 1).setName(newName);
	}

	//���� ����
	yn = 0;
	do {
		std::cout << "������ �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		unsigned int newCost = _caffeData->getDefaultCoffeeBean(idx - 1).getCost();
		std::cout << "�� ������ �Է��ϼ���: ";
		std::cin >> newCost;
		_caffeData->getDefaultCoffeeBean(idx - 1).setCost(newCost);
		_caffeData->updateCost();
	}
	
	return;
}

//���ο��� �� �۾� �����ϴ� �Լ�
void selectCoffeeBeanSetting(CaffeData *_caffeData) {
	printAddDeleteModify();
	
	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			addCoffeeBean(_caffeData);
			break;
		case 2:
			//deletion
			deleteCoffeeBean(_caffeData);
			break;
		case 3:
			//modify
			modifyCoffeeBean(_caffeData);
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
void addIngredient(CaffeData *_caffeData) {
	std::string newIngredientName;
	unsigned int newCost = 0;

	std::cout << "�߰��� ÷���� �̸�: ";
	std::cin.ignore();
	std::getline(std::cin, newIngredientName);
	std::cout << "÷���� ����: ";
	std::cin >> newCost;

	_caffeData->addIngredient(Ingredient(newIngredientName, newCost));

	return;
}

//÷���� ���� �Լ�
void deleteIngredient(CaffeData *_caffeData) {
	_caffeData->printDefaultIngredientList();

	int idx = 0;
	do {
		std::cout << "������ ÷���� ��ȣ: ";
		std::cin >> idx;

		if (idx < 0 || idx > _caffeData->sizeofIngredientList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else if (idx == 0) {
			break;
		}
		else {
			_caffeData->deleteIngredient(idx - 1);
		}
	} while (idx < 1 || idx > _caffeData->sizeofIngredientList());

	return;
}

//÷���� ���� �Լ�
void modifyIngredient(CaffeData *_caffeData) {
	_caffeData->printDefaultIngredientList();

	int idx = 0;
	do {
		std::cout << "������ ÷���� ��ȣ (��Ҵ� 0): ";
		std::cin >> idx;

		if (idx < 0 || idx > _caffeData->sizeofIngredientList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx == 0) {
			return;
		}
	} while (idx < 0 || idx > _caffeData->sizeofIngredientList());

	//�̸� ����
	char yn = 0;
	do {
		std::cout << "�̸��� �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		std::string newName = _caffeData->getDefaultIngredient(idx - 1).getName();
		std::cout << "�� �̸��� �Է��ϼ���: ";
		std::cin.ignore();
		std::getline(std::cin, newName);
		_caffeData->getDefaultIngredient(idx - 1).setName(newName);
	}

	//���� ����
	yn = 0;
	do {
		std::cout << "������ �����Ͻðڽ��ϱ�? (Y or N): ";
		std::cin >> yn;
	} while (yn != 'Y' && yn != 'N');
	if (yn == 'Y') {
		unsigned int newCost = _caffeData->getDefaultIngredient(idx - 1).getCost();
		std::cout << "�� ������ �Է��ϼ���: ";
		std::cin >> newCost;
		_caffeData->getDefaultIngredient(idx - 1).setCost(newCost);
		_caffeData->updateCost();
	}

	return;
}

//÷�������� �� �۾� �����ϴ� �Լ�
void selectIngredientSetting(CaffeData *_caffeData) {
	printAddDeleteModify();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//addition
			addIngredient(_caffeData);
			break;
		case 2:
			//deletion
			deleteIngredient(_caffeData);
			break;
		case 3:
			//modify
			modifyIngredient(_caffeData);
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
void addCoffeeBeanToCoffee(CaffeData *_caffeData) {
	_caffeData->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "Ŀ������ �߰��� Ŀ�� ��ȣ�� ������ �ּ��� (��Ҵ� 0): ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList());

	_caffeData->printDefaultCoffeeBeanList();
	int idx_bean = 0;
	do {
		std::cout << "�߰��� ���� ��ȣ�� ������ �ּ��� (�� �߰������� 0): ";
		std::cin >> idx_bean;

		if (idx_bean < 0 || idx_bean > _caffeData->sizeofCoffeeBeanList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx_bean == 0) {
			break;
		}
		else {
			_caffeData->getDefaultCoffee(idx_coffee - 1).addBeanList(_caffeData->getDefaultCoffeeBean(idx_bean - 1));
		}
	} while (idx_bean != 0);

	return;
}

//Ŀ�ǿ� Ŀ���� ���� �Լ�
void deleteCoffeeBeanFromCoffee(CaffeData *_caffeData) {
	_caffeData->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "Ŀ������ ������ Ŀ�� ��ȣ�� ������ �ּ��� (��Ҵ� 0): ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList());

	Coffee *toRemove = &_caffeData->getDefaultCoffee(idx_coffee - 1);

	int idx_bean = 0;
	do {
		if (toRemove->getBeanList().empty()) {
			std::cout << "���ΰ� �����ϴ�." << std::endl;
			idx_bean = 0;
			break;
		}
		else {
			printCoffeeBeanOfCoffee(toRemove);

			std::cout << "������ ���� ��ȣ�� ������ �ּ��� (�� ���������� 0): ";
			std::cin >> idx_bean;

			if (idx_bean < 0 || idx_bean > toRemove->getBeanList().size()) {
				std::cout << "�߸��� �Է��Դϴ�." << std::endl;
				continue;
			}
			else if (idx_bean == 0) {
				break;
			}
			else {
				toRemove->removeBeanList(idx_bean - 1);
			}
		}
	} while (idx_bean != 0);

	return;
}

//Ŀ�ǿ� ÷���� �߰� �Լ�
void addIngredientToCoffee(CaffeData *_caffeData) {
	_caffeData->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "÷������ �߰��� Ŀ�� ��ȣ�� ������ �ּ��� (��Ҵ� 0): ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList());

	_caffeData->printDefaultIngredientList();
	int idx_ingre = 0;
	do {
		std::cout << "�߰��� ÷���� ��ȣ�� ������ �ּ��� (�� �߰������� 0): ";
		std::cin >> idx_ingre;

		if (idx_ingre < 0 || idx_ingre > _caffeData->sizeofIngredientList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx_ingre == 0) {
			break;
		}
		else {
			_caffeData->getDefaultCoffee(idx_coffee - 1).addIngreList(_caffeData->getDefaultIngredient(idx_ingre - 1));
		}
	} while (idx_ingre != 0);

	return;
}

//Ŀ�ǿ� ÷���� ���� �Լ�
void deleteIngredientFromCoffee(CaffeData *_caffeData) {
	_caffeData->printDefaultCoffeeList();

	int idx_coffee = 0;
	do {
		std::cout << "Ŀ������ ������ Ŀ�� ��ȣ�� ������ �ּ���: ";
		std::cin >> idx_coffee;

		if (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (idx_coffee == 0) {
			return;
		}
	} while (idx_coffee < 0 || idx_coffee > _caffeData->sizeofCoffeeList());

	Coffee *toRemove = &_caffeData->getDefaultCoffee(idx_coffee - 1);

	int idx_ingre = 0;
	do {
		if (toRemove->getIngreList().empty()) {
			std::cout << "÷������ �����ϴ�." << std::endl;
			idx_ingre = 0;
			break;
		}
		else {
			printIngredientOfCoffee(toRemove);

			std::cout << "������ ÷���� ��ȣ�� ������ �ּ��� (�� ���������� 0): ";
			std::cin >> idx_ingre;

			if (idx_ingre < 0 || idx_ingre > toRemove->getIngreList().size()) {
				std::cout << "�߸��� �Է��Դϴ�." << std::endl;
				continue;
			}
			else if (idx_ingre == 0) {
				break;
			}
			else {
				toRemove->removeIngreList(idx_ingre - 1);
			}
		}
	} while (idx_ingre != 0);

	return;
}

//Ŀ�� �߰� �Լ�
void addCoffee(CaffeData *_caffeData) {
	std::string newCoffeeName;
	std::cout << "���ο� Ŀ�� �̸��� �Է��ϼ���: ";
	std::cin.ignore();
	std::getline(std::cin, newCoffeeName);

	int tmp = 0;
	std::vector<CoffeeBean *> newBean;
	_caffeData->printDefaultCoffeeBeanList();
	do {
		std::cout << "���θ� �߰��ϼ��� (�� �߰������� 0): ";
		std::cin >> tmp;

		if (tmp < 0 || tmp > _caffeData->sizeofCoffeeBeanList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}
		else if (tmp == 0) {
			break;
		}
		else {
			newBean.push_back(&_caffeData->getDefaultCoffeeBeanList()->at(tmp - 1));
		}
	} while (tmp != 0);

	tmp = 0;
	std::vector<Ingredient *> newIngre;
	_caffeData->printDefaultIngredientList();
	do {
		std::cout << "÷������ �߰��ϼ��� (�� �߰������� 0): ";
		std::cin >> tmp;

		if (tmp < 0 || tmp > _caffeData->sizeofIngredientList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else if (tmp == 0) {
			break;
		}
		else {
			newIngre.push_back(&_caffeData->getDefaultIngredientList()->at(tmp - 1));
		}
	} while (tmp != 0);

	Coffee newCoffee(newCoffeeName, newBean, newIngre);
	_caffeData->addCoffee(newCoffee);
	return;
}

//Ŀ�� ���� �Լ�
void deleteCoffee(CaffeData *_caffeData) {
	_caffeData->printDefaultCoffeeList();
	
	int toDelete = 0;
	do {
		std::cout << "������ Ŀ�� ��ȣ�� �Է��ϼ��� (��Ҵ� 0): ";
		std::cin >> toDelete;

		if (toDelete < 0 || toDelete > _caffeData->sizeofCoffeeList()) {
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else if (toDelete == 0) {
			break;
		}
		else {
			_caffeData->deleteCoffee(toDelete - 1);
		}
	} while (toDelete != 0);
	return;
}

//Ŀ�ǿ��� �� �۾� �����ϴ� �Լ�
void selectCoffeeSetting(CaffeData *_data) {
	printAddDeleteModify_Coffee();

	int tmp = 0;
	do {
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//coffeebean addition
			addCoffeeBeanToCoffee(_data);
			break;
		case 2:
			//coffeebean deletion
			deleteCoffeeBeanFromCoffee(_data);
			break;
		case 3:
			//addon addition
			addIngredientToCoffee(_data);
			break;
		case 4:
			//addon deletion
			deleteIngredientFromCoffee(_data);
			break;
		case 5:
			//coffee addition
			addCoffee(_data);
			break;
		case 6:
			//coffee deletion
			deleteCoffee(_data);
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
void dataSettingSelected(CaffeData *_data) {
	int tmp = 0;

	do {
		printDataSetting();
		std::cin >> tmp;

		switch (tmp) {
		case 1:
			//function which calls setting of coffeebean
			selectCoffeeBeanSetting(_data);
			break;
		case 2:
			//function which calls setting of addon
			selectIngredientSetting(_data);
			break;
		case 3:
			//function which calls setting of coffee itself
			selectCoffeeSetting(_data);
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
