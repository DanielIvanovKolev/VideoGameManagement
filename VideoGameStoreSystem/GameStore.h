#ifndef GAMESTORE_H
#define GAMESTORE_H

#include "CustomerSection.h"
#include "Console.h"

int main();
bool entryStaff();
int menuStaff();
int menuCustomer(Customer *customer);
void forget();
void bye();
int insideTheShop(Console *console);
int insideTheShopCustomer(Console *console, Customer *customer);
#endif



