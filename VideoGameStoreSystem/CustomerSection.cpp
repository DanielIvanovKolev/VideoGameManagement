#include "stdafx.h"
#include "CustomerSection.h"
#include "Console.h"
#include "GameStore.h"

int i = 0, checkNumFromFile = 0, p, flag = 0, l = 1;
double moneyCheckout = 0;

Customer::Customer(void){
	loginUser[0] = '\0';
	for (int j = 0; j < 8; j++){
		customerInfo[j].username[0] = '\0';
		customerInfo[j].password[0] = '\0';
		customerInfo[j].clientId = '\0';
		customerInfo[j].money = '\0';
	}
}

int Customer::login(Console *console){
	FILE *logFp;
	Customer customer;
	console->q = 0; console->moneyBalance = 0 , p = 0;
	int check = 0;
	char password[30], usernameFromFile[30], passwordFromFile[30];
	system("cls");
	printf("\n\n\n\n\tPlease enter the following details about your account!:");
	
	logFp = fopen("customer.txt", "r");

	do{
		fflush(stdin);
		printf("\n\n\n\n\tUsername : ");
		gets(loginUser);
	} while (!loginUser[0] || strlen(loginUser) > 20);

	do{
		fflush(stdin);
		printf("\n\n\n\n\tPassword : ");
		gets(password);
	} while (!password[0] || strlen(password) > 20);

	while (!feof(logFp)){
		fscanf(logFp, "%s %s", usernameFromFile, passwordFromFile);
		if (!strcmp(usernameFromFile, loginUser) && !strcmp(passwordFromFile, password)){
			check = 1;
		}
	}

	if (check){
		system("cls");
		printf("\n\n\n\n\tYou have succesfully logged in!");
		system("pause>nul");
		fclose(logFp);
		return 1;
	}
	else{
		system("cls");
		printf("\n\n\n\n\t    Wrong username or password! Try again!");
		system("pause>nul");
		menuCustomer(&customer);
	}
	return 1;
}

void Customer::registerForm(){
	FILE * regfp, *checkNumAcc;
	char usernameFromFile[30], passwordFromFile[30], checkNum[2];

	checkNumAcc = fopen("checkNumAcc.txt", "a+");
	while (!feof(checkNumAcc)){
		fscanf(checkNumAcc, "%s", checkNum);
	}
	checkNumFromFile = atoi(checkNum);
	fclose(checkNumAcc);

	if (checkNumFromFile > 8){
		system("cls");
		printf("\n\n\n\n\t      Maximum number of accounts reached!!! Exiting....");
		printf("\n\n\n\n\t      Please contact support! Thanks!");
		system("pause>nul");
		main();
	}

	system("cls");
	regfp = fopen("customer.txt", "a+");
	do{
		fflush(stdin);
		system("cls");
		printf("Username : ");
		gets(customerInfo[i].username);
	} while (!customerInfo[i].username[0] || strlen(customerInfo[0].username) > 30);

	while (!feof(regfp)){
		fscanf(regfp, "%s %s", usernameFromFile, passwordFromFile);
		if (!strcmp(customerInfo[i].username, usernameFromFile)){
			printf("\n\n\n\n\t     This Username already exist!!!");
			system("pause>nul");
			main();
		}
	}

	fputs(customerInfo[i].username, regfp);
	fputs(" ", regfp);
	do{
		fflush(stdin);
		system("cls");
		printf("Password : ");
		gets(customerInfo[i].password);
	} while (!customerInfo[i].password[0] || strlen(customerInfo[0].password) > 30);


	fputs(customerInfo[i].password, regfp);
	fputs(" ", regfp);
	fclose(regfp);
	i++;
	system("cls");
	printf("\n\n\n\n\t                    Registration Succesfull!!!");

	checkNumAcc = fopen("checkNumAcc.txt", "a+");
	while (!feof(checkNumAcc)){
		fscanf(checkNumAcc, "%s", checkNum);
	}
	checkNumFromFile = atoi(checkNum);
	checkNumFromFile++;
	checkNum[0] = checkNumFromFile + '0';
	fputc(checkNum[0], checkNumAcc);
	fputs(" ", checkNumAcc);
	fclose(checkNumAcc);

	system("pause>nul");
}

void Customer::forget(){
	FILE *forFp;
	int i = 0, check = 0;
	char username[30], usernameFromFile[30], passwordFromFile[30];
	forFp = fopen("customer.txt", "r");
	system("cls");
	printf("\n\n\n\n\t   Please enter the last username you remember! \n");
	while (i < 3){
		do{
			fflush(stdin);
			printf("\n\t   Username : ");
			gets(username);
		} while (!username[0] || strlen(username) > 30);

		while (!feof(forFp)){
			fscanf(forFp, "%s %s", usernameFromFile, passwordFromFile);
			if (!strcmp(usernameFromFile, username)){
				check = 1;
				break;
			}
		}
		if (check){
			printf("\n\n\n\n\t   Welcome %s! Your password is: %s", usernameFromFile, passwordFromFile);
			system("pause>nul");
			break;
		}
		else{
			printf("You have entered wrong username!!! Try Again\n\n");
			system("pause>nul");
		}
		i++;
		if (i == 3){
			printf("\n\n\n\n\t    You have entered wrong username too many times! Bye!");
			system("pause>nul");
		}
	}
}

void Customer::existingAcc(){
	FILE *existingAccount;
	int k = 0;
	existingAccount = fopen("customer.txt", "r");
	while (!feof(existingAccount)){
		fscanf(existingAccount, "%s %s", customerInfo[k].username, customerInfo[k].password);
		k++;
	}
	fclose(existingAccount);
}

void Customer::addMoney(){
	FILE *checkNumAcc;
	int numAcc = 0;
	p++;
	char checkNum[2];
	checkNumAcc = fopen("checkNumAcc.txt", "a+");
	while (!feof(checkNumAcc)){
		fscanf(checkNumAcc, "%s", checkNum);
	}
	numAcc = atoi(checkNum);
	fclose(checkNumAcc);
	if (l){
		l = 0;
		flag = 1;
		for (int j = 0; j < numAcc; j++){
			if (!strcmp(loginUser, customerInfo[j].username)){
				system("cls");
				system("color 1e");
				do{
					system("cls");
					printf("\n\t\t\t Enter how much money you want to add to your account: ");
					scanf("%lf", &customerInfo[j].money);
				} while (customerInfo[j].money < 0 || customerInfo[j].money > 99999);
				system("cls");
				printf("\n\t\t\t Funds added succesfully!!! ");
				system("pause>nul");
				return;
			}
		}
	}
	else{
		double tempFlagMoney = 0;
		for (int j = 0; j < numAcc; j++){
			if (!strcmp(loginUser, customerInfo[j].username)){
				system("cls");
				system("color 1e");
				do{
					system("cls");
					printf("\n\t\t\t Enter how much money you want to add to your account: ");
					scanf("%lf", &tempFlagMoney);
				} while (tempFlagMoney < 0 || tempFlagMoney > 99999);
				customerInfo[j].money += tempFlagMoney;
				system("cls");
				printf("\n\t\t\t Funds added succesfully!!! ");
				system("pause>nul");
				return;
			}
		}
	}
}

void Customer::balance(Console *console){
	FILE *checkNumAcc;
	int numAcc = 0;
	char checkNum[2];
	checkNumAcc = fopen("checkNumAcc.txt", "a+");
	while (!feof(checkNumAcc)){
		fscanf(checkNumAcc, "%s", checkNum);
	}
	numAcc = atoi(checkNum);
	fclose(checkNumAcc);
	for (int j = 0; j < numAcc; j++){
			if (!strcmp(loginUser, customerInfo[j].username)){
				if (flag){
					flag = 0;
					l = 1;
					console->moneyBalance += customerInfo[j].money;
					console->checkout();
				}
				else{
					console->checkout();
				}
			}
	}
	
}


void bye(){
	system("cls");
	printf("\n\n\n\n\t    Thank you for using our services! Goodbye!\n");
}

