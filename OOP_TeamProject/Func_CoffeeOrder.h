#pragma once
/*작성자: 여일구
 *커피 주문을 위한 함수들을 정의한 헤더 파일
 *메인 화면에서 1번을 선택했을 때 실행되는 함수들
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