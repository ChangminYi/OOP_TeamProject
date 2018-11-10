#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

//�������� �ʱ�ȭ�� ���� ���
#include "CaffeData.h"

//�ֹ��� ���� �����͸� ������ Ŭ���� ���
#include "Order.h"

//���α׷� �۵��� ���� �Լ��� ������ ���
#include "Func_CoffeeOrder.h"
#include "Func_DataSetting.h"


//���� ȭ�� ��� �Լ�
void printMainScreen() {
	std::cout << "  1. Ŀ�� �ֹ�" << std::endl;
	std::cout << "  2. ����" << std::endl;
	std::cout << "  3. ����" << std::endl;
	std::cout << "����: ";
	return;
}

//�۾� �й� �Լ�
bool selectMainFunction(CaffeData* _cd) {
	int argi = 0;
	std::cin >> argi;

	switch (argi) {
	case 1:
		coffeeOrderSelected(_cd);
		break;
	case 2:
		dataSettingSelected(_cd);
		break;
	case 3:
		return false;
	default:
		std::cout << "�ùٸ� �Է��� �ƴմϴ�." << std::endl;
	}
	return true;
}

//���� �Լ�
int main() {
	CaffeData* defData = new CaffeData();

	do {
		printMainScreen();
	} while (selectMainFunction(defData) != false);

	system("pause");

	delete defData;
	return 0;
}