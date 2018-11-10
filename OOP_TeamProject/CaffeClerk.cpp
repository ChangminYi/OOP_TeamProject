#include "CaffeClerk.h"

/*
������ ���� �ִ� ī���� �����͸� ��ȯ
*/

CaffeData* CaffeClerk::getData() {
	return this->cd;
}

std::vector<Coffee> CaffeClerk::getOrderedList() {
	return this->orderedCoffeeList;
}

void CaffeClerk::addBean(int listIdx, int beanIdx) {
	CoffeeBean tmp = this->cd->getDefaultCoffeeBean(beanIdx);
	this->orderedCoffeeList.at(listIdx).addBeanList(tmp);
}

void CaffeClerk::addIngre(int listIdx, int ingreIdx) {
	Ingredient tmp = this->cd->getDefaultIngredient(ingreIdx);
	this->orderedCoffeeList.at(listIdx).addIngreList(tmp);
}

void CaffeClerk::addOrder(int _idx) {
	this->orderedCoffeeList.push_back(this->cd->getDefaultCoffee(_idx));
}

void CaffeClerk::addOrder(Coffee& _coffee) {
	this->orderedCoffeeList.push_back(_coffee);
}

/*
������ ���� �Լ�
�ֹ��� Ŀ�ǿ� �� ������ ���
*/

void CaffeClerk::makeBill() {
	std::vector<CoffeeBean *> _beanList;
	std::vector<Ingredient *> _IngreList;

	std::cout << std::endl << "---------------<�ֹ���>---------------" << std::endl;

	for (int i = 0; i < this->orderedCoffeeList.size(); i++) {
		std::cout << "  " << i + 1 << '.' << this->orderedCoffeeList.at(i).getName() << ": " << this->orderedCoffeeList.at(i).getCost() << "��" << std::endl;

		_beanList = this->orderedCoffeeList.at(i).getBeanList();
		_IngreList = this->orderedCoffeeList.at(i).getIngreList();

		std::cout << "    ����" << std::endl;
		for (int j = 0; j < _beanList.size(); j++) {
			std::cout << "    " << _beanList.at(j)->getName() << ": " << _beanList.at(j)->getCost() << "��" << std::endl;
		}

		std::cout << std::endl << "    ÷����" << std::endl;
		for (int j = 0; j < _IngreList.size(); j++) {
			std::cout << "    " << _IngreList.at(j)->getName() << ": " << _IngreList.at(j)->getCost() << "��" << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl << std::endl;
}

/*
Ŀ���ҵ� Ŀ��(�Ǵ� ���� ������ Ŀ��)�� �����Ϳ� ����
*/

void CaffeClerk::saveCustom(Coffee& _newCoffee) {
	_newCoffee.setCost();
	this->cd->addCoffee(_newCoffee);
}