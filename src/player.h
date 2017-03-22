#pragma once

#include "card.h"
#include <list>
#include <string>
using namespace std;

class Player {

	private:
		string		name;
        list<Card*> *playerHand;
		int			cardsLeft;

		bool		sortedPlayerHand;
		void		sortPlayerHand();
	public:
        Player(string name);
		~Player();

        string getName();
        void draw(Card *card);
        Card* play(int cardNumber);
		int getCardsLeft();
        list<Card*>* getPlayerHand();
};

