#pragma once
/*작성자: 이창민
 *프로그램 실행 중 데이터 수정을 위한 함수들을 정의한 헤더 파일
 *메인 화면에서 2번을 선택했을 때 실행되는 함수들
 */

#ifndef FUNC_DATASETTING
#define FUNC_DATASETTING


void printDataSetting();
void printAddDeleteModify();
void printAddDeleteModify_Coffee();


void addCoffeeBean();
void deleteCoffeeBean();
void modifyCoffeeBean();
void selectCoffeeBeanSetting();


void addIngredient();
void deleteIngredient();
void modifyIngredient();
void selectIngredientSetting();


void addCoffeeBeanToCoffee();
void deleteCoffeeBeanFromCoffee();
void addIngredientToCoffee();
void deleteIngredientFromCoffee();
void addCoffee();
void deleteCoffee();
void selectCoffeeSetting();


void dataSettingSelected();

#endif