#pragma once

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

void coffeeOrderSelected(CaffeData *_cd);	//커피 주문 선택 시 기능 선택 함수

#endif // !COFFEEORDERFUNC