#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

//�������� �ʱ�ȭ�� ���� ���
#include "GlobalVar.h"

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
bool selectMainFunction() {
	int argi = 0;
	std::cin >> argi;

	switch (argi) {
	case 1:
		coffeeOrderSelected();
		break;
	case 2:
		dataSettingSelected();
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
	init();

	do {
		printMainScreen();
	} while (selectMainFunction() != false);

	system("pause");
	return 0;
}