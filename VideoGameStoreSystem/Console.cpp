#include "stdafx.h"
#include "Console.h"
#include "GameStore.h"

char *playstationGames[3] = { "Horizon Zero Dawn", "God of War", "Uncharted"};
char *xboxGames[3] = { "Forza Horizon", "Halo", "Senua's Saga" };
char *pcGames[3] = { "CS GO", "Euro Truck Simulator", "Minecraft" };
char *nintednoGames[3] = { "Zelda", "Super Mario Bros", "Animal Crossing" };
int countBasketItems = 0, q = 0;

Console::Console(void){
	consoleName[0] = '\0';
	q = 0 , p = 0;
	moneyBalance = 0;
	for (int j = 0; j < 6; j++){
		gameInfo[j].gameName[0] = '\0';
		gameInfo[j].yearRelease[0] = '\0';
		gameInfo[j].price = 0;
	}

	for (int j = 0; j < 10; j++){
		basketInside[j].basket[0] = '\0';
		basketInside[j].moneyInBasket = 0;
	}
}

void Console::listOfGames(int choice){
	FILE *games;
	switch (choice)
	{
	case 1:
		games = fopen("games.txt", "w+");
		strcpy(consoleName, "Playstation");
		strcpy(gameInfo[0].yearRelease, "2017\0");
		strcpy(gameInfo[1].yearRelease, "2020\0");
		strcpy(gameInfo[2].yearRelease, "2015\0");

		gameInfo[0].price = 39.99;
		gameInfo[1].price = 49.99;
		gameInfo[2].price = 59.99;

		for (int i = 0; i < 3; i++){
			fputs(playstationGames[i], games);
			fputs("\n", games);
			strcpy(gameInfo[i].gameName, playstationGames[i]);
		}
		fclose(games);
		printConsoleMenu();
		break;

	case 2:
		games = fopen("games.txt", "w+");
		strcpy(consoleName, "Xbox");
		strcpy(gameInfo[0].yearRelease, "2012\0");
		strcpy(gameInfo[1].yearRelease, "2021\0");
		strcpy(gameInfo[2].yearRelease, "2013\0");

		gameInfo[0].price = 19.99;
		gameInfo[1].price = 25.99;
		gameInfo[2].price = 80.50;

		for (int i = 0; i < 3; i++){
			fputs(xboxGames[i], games);
			fputs("\n", games);
			strcpy(gameInfo[i].gameName, xboxGames[i]);
		}

		fclose(games);
		printConsoleMenu();
		break;
	case 3:
		games = fopen("games.txt", "w+");
		strcpy(consoleName, "PC");
		strcpy(gameInfo[0].yearRelease, "2011\0");
		strcpy(gameInfo[1].yearRelease, "2022\0");
		strcpy(gameInfo[2].yearRelease, "2017\0");

		gameInfo[0].price = 21.99;
		gameInfo[1].price = 43.99;
		gameInfo[2].price = 16.99;

		for (int i = 0; i < 3; i++){
			fputs(pcGames[i], games);
			fputs("\n", games);
			strcpy(gameInfo[i].gameName, pcGames[i]);
		}

		fclose(games);
		printConsoleMenu();
		break;
	case 4:
		games = fopen("games.txt", "w+");
		strcpy(consoleName, "Nintendo");
		strcpy(gameInfo[0].yearRelease, "2013\0");
		strcpy(gameInfo[1].yearRelease, "2004\0");
		strcpy(gameInfo[2].yearRelease, "2007\0");

		gameInfo[0].price = 9.99;
		gameInfo[1].price = 67.99;
		gameInfo[2].price = 40.99;

		for (int i = 0; i < 3; i++){
			fputs(nintednoGames[i], games);
			fputs("\n", games);
			strcpy(gameInfo[i].gameName, nintednoGames[i]);
		}

		fclose(games);
		printConsoleMenu();
		break;
	default:
		break;
	}
}

void Console::printConsoleMenu(){
initial:
	int gameChoice,choice;
	Console console;
	system("cls");
	system("color 1e");
	printf("\n\t\t\t== == == == == == == == == ==\n");
	printf("\n\t\t\t    List of %s games!  \n", consoleName);
	printf("\n\t\t\t=============================\n\n");
	printf("\n\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\n\t\t\tI. Name: %s \t Year Release: %s \t Price: %.2f\n\n\t\t\tII. Name: %s \t Year Release: %s \t Price: %.2f\n\n\t\t\tIII. Name: %s \t Year Release: %s \t Price: %.2f\n\n\t\t\t", gameInfo[0].gameName, gameInfo[0].yearRelease, gameInfo[0].price,
		gameInfo[1].gameName, gameInfo[1].yearRelease, gameInfo[1].price,
		gameInfo[2].gameName, gameInfo[2].yearRelease, gameInfo[2].price);
	printf("\n\n\t\t\t1. Add game to basket\n");
	printf("\n\t\t\t2. Return\n");
	printf("\n\t\t\tEnter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("\n\n\n\t\t\tSelect a game to add to basket: ");
		scanf("%d", &gameChoice);
		if (addToBasket(gameChoice)){
			goto initial;
		}
		else{
			break;
		}
	case 2:
		insideTheShop(&console);
	default:
		break;
	}
}

int Console::addToBasket(int gameChoice){
	if (q == 10){
		system("color 1e");
		printf("\n\n\t\t\tBasket is full, please proceed to checkout!!!");
		system("pause>nul");
		return 0;
	}

	switch (gameChoice)
	{
	case 1:
		strcpy(basketInside[q].basket, gameInfo[gameChoice - 1].gameName);
		basketInside[q].moneyInBasket += gameInfo[gameChoice - 1].price;
		q++;
		break;
	case 2:
		strcpy(basketInside[q].basket, gameInfo[gameChoice - 1].gameName);
		basketInside[q].moneyInBasket += gameInfo[gameChoice - 1].price;
		q++;
		break;
	case 3:
		strcpy(basketInside[q].basket, gameInfo[gameChoice - 1].gameName);
		basketInside[q].moneyInBasket += gameInfo[gameChoice - 1].price;
		q++;
		break;
	default:
		break;
	}
	return 1;
}

void Console::basketInfo(){
	if (basketInside[0].basket[0] == '\0'){
		system("cls");
		printf("\n\n\n\tThe basket is empty!!!");
		system("pause>nul");
		return;
	}
	system("cls");
	system("color 1e");
	printf("\n\n\n\t\t\t The games that you have been selected are:\n");
	for (int j = 0; j < q; j++){
		printf("\n#%d %s - %.2lf$", j + 1, basketInside[j].basket, basketInside[j].moneyInBasket);
	}
	system("pause>nul");
}

void Console::checkout(){
	if (basketInside[0].basket[0] == '\0'){
		system("cls");
		printf("\n\n\n\tThe basket is empty!!!");
		system("pause>nul");
		return;
	}
	basketInfo();
	int flag = 0, confirm = 0;
	double totalPrice = 0;
	for (int j = 0; j < q; j++){
		totalPrice += basketInside[j].moneyInBasket;
	}
	printf("\n\n\nYour total is: %.2lf$", totalPrice);
	printf("\n\n\nDo you want confirm the transaction(y/n)? :(Availiable balance: %.2lf)", moneyBalance);
	printf("\n\n\n1. Confirm Transaction");
	printf("\n\n\n2. Continue shopping");
	printf("\n\t\t\tEnter your choice: ");
	scanf("%d", &confirm);

	switch (confirm)
	{
	case 1:
		if (totalPrice > moneyBalance){
			printf("\n\n\n\t\t\t Insufficient funds!!!");
			system("pause>nul");
			return;
		}
		else{
			moneyBalance -= totalPrice;
			for (int j = 0; j < q; j++){
				basketInside[j].basket[0] = '\0';
				basketInside[j].moneyInBasket = 0;
			}
			q = 0;
			printf("\n\n\n\t\t\t Transaction confirmed!!!");
			printf("\n\n\n\t\t\t Your balance is: %lf", moneyBalance);
			system("pause>nul");
		}
	case 2:
		break;
	default:
		break;
	}
} 