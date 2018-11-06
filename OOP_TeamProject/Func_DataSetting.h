#pragma once
/*�ۼ���: ��â��
 *���α׷� ���� �� ������ ������ ���� �Լ����� ������ ��� ����
 *���� ȭ�鿡�� 2���� �������� �� ����Ǵ� �Լ���
 */

#ifndef FUNC_DATASETTING
#define FUNC_DATASETTING


void printDataSetting();
void printAddDeleteModify();
void printAddDeleteModify_Coffee();


void addCoffeeBean(CaffeData *);
void deleteCoffeeBean(CaffeData *);
void modifyCoffeeBean(CaffeData *);
void selectCoffeeBeanSetting(CaffeData *);


void addIngredient(CaffeData *);
void deleteIngredient(CaffeData *);
void modifyIngredient(CaffeData *);
void selectIngredientSetting(CaffeData *);


void addCoffeeBeanToCoffee(CaffeData *);
void deleteCoffeeBeanFromCoffee(CaffeData *);
void addIngredientToCoffee(CaffeData *);
void deleteIngredientFromCoffee(CaffeData *);
void addCoffee(CaffeData *);
void deleteCoffee(CaffeData *);
void selectCoffeeSetting(CaffeData *);


void dataSettingSelected(CaffeData *);

#endif