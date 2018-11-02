#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

//�ֹ��� ���� �����͸� ������ Ŭ���� ���
#include "Order.h"

//���α׷� �۵��� ���� �Լ��� ������ ���
#include "Func_CoffeeOrder.h"
#include "Func_DataSetting.h"


Ingredient defaultIngredient[] = {
	Ingredient("Choco Syrup", 500),
	Ingredient("Charamel Syrup", 500),
	Ingredient("Hazelnut Syrup", 500),
	Ingredient("Vanilla Syrup", 500),
	Ingredient("Whipping Cream", 500),
	Ingredient("Milk Foam", 500),
	Ingredient("Water", 500)
};

Coffee defaultCoffee[]{
	Coffee("Espresso"),
	Coffee("Espresso Con Panna"),
	Coffee("Espresso Macchiato"),
	Coffee("Americano"),
	Coffee("Vienna"),
	Coffee("Caffe Latte"),
	Coffee("Hazelnut Latte"),
	Coffee("Vanilla Latte"),
	Coffee("Caramel Latte"),
	Coffee("Caramel Macchiato"),
	Coffee("Cappuccino"),
	Coffee("Caffe Mocha"),
	Coffee("White Chocolate Mocha"),
	Coffee("Caramel Mocha"),
	Coffee("Mochaccino")
};


void printMainScreen() {
	std::cout << "  1. Ŀ�� �ֹ�" << std::endl;
	std::cout << "  2. ����" << std::endl;
	std::cout << "  3. ����" << std::endl;
	std::cout << "����: ";
	return;
}

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

int main() {
	do {
		printMainScreen();
	} while (selectMainFunction() != false);

	system("pause");
	return 0;
}