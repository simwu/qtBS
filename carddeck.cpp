#include "carddeck.h"
#include <stdlib.h>				// srand, rand
#include <time.h>				// time

CardDeck::CardDeck()
{
    cardDeck = new Card**[SUITS];

    for (int row = 0; row < SUITS; row++)
    {
        cardDeck[row] = new Card*[CARDS];
    }

	for (int suit = 0; suit < SUITS; suit++)
	{
		for (int card = 0; card < CARDS; card++)
		{
			cardDeck[suit][card] = nullptr;
		}
	}
	// Initialize random seed
	srand(time(NULL));
}

CardDeck::~CardDeck()
{

}

void CardDeck::shuffle()
{
	int suitNumber = 0;
	int cardNumber = 0;
	bool found	   = false;

	// Create and initialize the card deck checklist parallel array
	bool checkList[SUITS][CARDS];
	
    for (int row = 0; row < SUITS; row++)
    {
        for (int col = 0; col < CARDS; col++)
        {
			checkList[row][col] = false;
		}
	}

	// Randomly shuffle the cards
    for (int suit = 0; suit < SUITS; suit++)
    {

        for (int card = 0; card < CARDS; card++)
        {

			found = false;

            while (!found)
            {

				suitNumber = rand() % SUITS + 1;		// Generate a number between 1 and 4
				cardNumber = rand() % CARDS + 1;		// Generate a number between 1 and 13

                if (checkList[suitNumber - 1][cardNumber - 1] == false)
                {
                    Card *newCard = new Card(suitNumber, cardNumber);
					cardDeck[suit][card] = newCard;

					checkList[suitNumber - 1][cardNumber - 1] = true;
					found = true;
				}
			}
		}
	}

	numberOfCards = SUITS * CARDS;
}

Card* CardDeck::deal()
{
	int suitNumber	= 0;
	int cardNumber	= 0;
	bool found		= false;
	 
	// Create a blank Card
    Card *card = nullptr;

    if (numberOfCards > 0)
    {
        while (!found)
        {
			suitNumber = rand() % SUITS + 1;		// Generate a number between 1 and 4
			cardNumber = rand() % CARDS + 1;		// Generate a number between 1 and 13

            if (cardDeck[suitNumber - 1][cardNumber - 1] != nullptr)
            {
				// Copy the Card found
                card = new Card(cardDeck[suitNumber - 1][cardNumber - 1]->getSuitNumber(), cardDeck[suitNumber - 1][cardNumber - 1]->getCardNumber());

				// Indicate this Card has been dealt
                cardDeck[suitNumber - 1][cardNumber - 1] = nullptr;
				numberOfCards--;

				found = true;
			}
		}
	}
	return card;
}




