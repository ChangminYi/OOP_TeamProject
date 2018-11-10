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


void addCoffeeBean(CaffeData *_cd);
void deleteCoffeeBean(CaffeData *_cd);
void modifyCoffeeBean(CaffeData *_cd);
void selectCoffeeBeanSetting(CaffeData *_cd);


void addIngredient(CaffeData *_cd);
void deleteIngredient(CaffeData *_cd);
void modifyIngredient(CaffeData *_cd);
void selectIngredientSetting(CaffeData *_cd);


void addCoffeeBeanToCoffee(CaffeData *_cd);
void deleteCoffeeBeanFromCoffee(CaffeData *_cd);
void addIngredientToCoffee(CaffeData *_cd);
void deleteIngredientFromCoffee(CaffeData *_cd);
void addCoffee(CaffeData *_cd);
void deleteCoffee(CaffeData *_cd);
void selectCoffeeSetting(CaffeData *_cd);


void dataSettingSelected(CaffeData *_cd);

#endif