#ifndef CONSOLE_H
#define CONSOLE_H

typedef struct{
	char gameName[40];
	char yearRelease[20];
	double price;
}GameInfo;

typedef struct{
	char basket[40];
	double moneyInBasket;
}BasketInside;

class Console{
private:
	char consoleName[15];
	GameInfo gameInfo[6];
	BasketInside basketInside[10];
public:
	int q, p;
	double moneyBalance;
	Console(void);
	Console(char *pconsolename, Console &console);
	void listOfGames(int choice);
	int addToBasket(int gameChoice);
	void basketInfo();
	void printConsoleMenu();
	void checkout();
};
#endif