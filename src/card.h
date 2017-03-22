#pragma once

#include "constants.h"
#include <string>
using namespace std;

class Card
{

	private:
		int suitNumber;
		int cardNumber;

	public:
        Card();
        Card(int suit, int card);
		~Card();

		int getSuitNumber();
        int getCardNumber();

		string toString();
		string toGraphic();
};

