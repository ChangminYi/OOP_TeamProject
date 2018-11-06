#pragma once
/*�ۼ���: ���ϱ�
 *Ŀ�� �ֹ��� ���� �Լ����� ������ ��� ����
 *���� ȭ�鿡�� 1���� �������� �� ����Ǵ� �Լ���
 */
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR

#ifndef STRING
#define STRING
#include <string>
#endif // !STRING

#include "CaffeData.h"
#include "Order.h"

#ifndef FUNC_COFFEEORDER
#define FUNC_COFFEEORDER

void coffeeOrderSelected();
void makeBill(const std::vector<Coffee> _orderedCoffeeList);

#endif // !COFFEEORDERFUNC