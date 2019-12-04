#include <iostream>
#include "Stack.h"
using namespace std;

struct Card
{
	int num; //number on the card ex. 0-9
	string color; //color of the card (red, blue, green, yellow)
	char effect; //(reverse, draw 2, draw 4, switch color)
};

int main()
{
	//initialize stacks (deck, player hands, active deck)

	//deck
		//create all numbered/colored cards
		//create all special cards

	//game loop
		//handle player turns
		//handle legal moves for player and ai
		//determine when game is won

	cout << "Press enter to continue...";
	cin.get();
	cin.ignore();
	return 0;
}