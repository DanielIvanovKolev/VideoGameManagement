// VideoGameStoreSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CustomerSection.h"
#include "GameStore.h"
#include "Console.h"

int main()
{
	Customer customer;
	while (menuCustomer(&customer));
	bye();
	return 0;
}

int menuCustomer(Customer *customer){
	Console console;
	customer->existingAcc();
	int menuChoice;
	system("cls");
	system("color 1e");
	printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
	printf("\n\t\t\tWelcome! Please login or register to your account!  \n");
	printf("\n\t\t\t========================================================\n\n");
	printf("\n\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\n\t\t\t1. Login\n\n\t\t\t2. Register\n\n\t\t\t3. Forgot username or password\n\n\t\t\t4. Exit\n");
	printf("\n\n\t\t\tSelect your choice:");
	scanf("%d", &menuChoice);

	switch (menuChoice)
	{
	case 1:
		if (customer->login(&console)){
			while(insideTheShopCustomer(&console, customer));
		}
		break;
	case 2:
		customer->registerForm();
		return 1;
	case 3:
		customer->forget();
		return 1;
	case 4:
		return 0;
	default:
		system("cls");
		printf("\n\n\n\n\t\t           You have made some sort of a mistake! Please Try Again");
		system("pause>nul");
		main();
	}

	return 0;
}

int insideTheShop(Console *console){
initial:
	Customer customer;
	int menuChoice;
	system("cls");
	system("color 1e");
	printf("\n\t\t\t== == == == == == == == == ==\n");
	printf("\n\t\t\t    Welcome to the shop!  \n");
	printf("\n\t\t\t=============================\n\n");
	printf("\n\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\n\t\t\t1. Playstation\n\n\t\t\t2. XBOX\n\n\t\t\t3. PC\n\n\t\t\t4. Nintendo\n\n\t\t\t5. Return to the intial screen\n");
	printf("\n\n\t\t\tSelect your choice:");
	scanf("%d", &menuChoice);
	
	switch (menuChoice)
	{
	case 1:
		console->listOfGames(menuChoice);
		return 1;
	case 2:
		console->listOfGames(menuChoice);
		return 1;
	case 3:
		console->listOfGames(menuChoice);
		return 1;
	case 4:
		console->listOfGames(menuChoice);
		return 1;
	case 5:
		return 1;
	default:
		goto initial;
	}
	return 1;
}

int insideTheShopCustomer(Console *console, Customer *customer){
initial:
	int menuChoice;
	system("cls");
	system("color 1e");
	printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
	printf("\n\t\t\t Hello %s! Have a great time in the shop :)  \n", customer->loginUser);
	printf("\n\t\t\t========================================================\n\n");
	printf("\n\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\n\t\t\t1. View Game List\n\n\t\t\t2. Add funds\n\n\t\t\t3. Basket\n\n\t\t\t4. Checkout\n\n\t\t\t5. Log out\n");
	printf("\n\n\t\t\tSelect your choice:");
	scanf("%d", &menuChoice);
	
	switch (menuChoice)
	{
	case 1:
		insideTheShop(console);
		goto initial;
	case 2:
		customer->addMoney();
		goto initial;
	case 3:
		console->basketInfo();
		goto initial;
	case 4:
		customer->balance(console);
		goto initial;
	case 5:
		menuCustomer(customer);
		return 0;
	default:
		goto initial;
	}
	
	return 1;
	
}




