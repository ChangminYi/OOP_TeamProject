#include "CaffeClerk.h"

/*
점원이 갖고 있는 카페의 데이터를 반환
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
영수증 생성 함수
주문한 커피와 그 가격을 출력
*/

void CaffeClerk::makeBill() {
	std::vector<CoffeeBean *> _beanList;
	std::vector<Ingredient *> _IngreList;

	std::cout << std::endl << "---------------<주문서>---------------" << std::endl;

	for (int i = 0; i < this->orderedCoffeeList.size(); i++) {
		std::cout << "  " << i + 1 << '.' << this->orderedCoffeeList.at(i).getName() << ": " << this->orderedCoffeeList.at(i).getCost() << "원" << std::endl;

		_beanList = this->orderedCoffeeList.at(i).getBeanList();
		_IngreList = this->orderedCoffeeList.at(i).getIngreList();

		std::cout << "    원두" << std::endl;
		for (int j = 0; j < _beanList.size(); j++) {
			std::cout << "    " << _beanList.at(j)->getName() << ": " << _beanList.at(j)->getCost() << "원" << std::endl;
		}

		std::cout << std::endl << "    첨가물" << std::endl;
		for (int j = 0; j < _IngreList.size(); j++) {
			std::cout << "    " << _IngreList.at(j)->getName() << ": " << _IngreList.at(j)->getCost() << "원" << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl << std::endl;
}

/*
커스텀된 커피(또는 새로 제작한 커피)를 데이터에 저장
*/

void CaffeClerk::saveCustom(Coffee& _newCoffee) {
	_newCoffee.setCost();
	this->cd->addCoffee(_newCoffee);
}