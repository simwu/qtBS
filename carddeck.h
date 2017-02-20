#pragma once

#include "card.h"

class CardDeck
{

	private:
        Card	***cardDeck;
		int		numberOfCards;

	public:
		CardDeck();
		~CardDeck();

		void shuffle();
        Card* deal();
};

