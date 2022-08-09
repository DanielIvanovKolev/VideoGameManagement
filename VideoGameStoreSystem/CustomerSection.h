#ifndef CUSTOMERSECTION_H
#define CUSTOMERSECTION_H
#include "Console.h"

typedef struct{
	char username[40];
	char password[20];
	int clientId;
	double money;
}CustomerInfo;

class Customer{
private:
	CustomerInfo customerInfo[10];
public:
	char loginUser[40];
	Customer(void);
	Customer(char *pUsername, char *pPassword, Customer &customer);
	int login(Console *console);
	void registerForm();
	void forget();
	void existingAcc();
	void addMoney();
	void balance(Console *console);
};

#endif

