#include "player.h"

Player::Player(string name)
{
    this->name		 = name;
    playerHand		 = new list<Card*>();
    cardsLeft        = 0;
	sortedPlayerHand = false;
}

Player::~Player()
{

}

string Player::getName()
{
	return name;
}

void Player::draw(Card *card)
{
    playerHand->push_back(card);
	cardsLeft++;
	sortedPlayerHand = false;
}

Card* Player::play(int cardNumber)
{
	// Copy the Card to be removed
    list<Card*>::iterator it = playerHand->begin();
    advance(it, cardNumber - 1);

    Card *card = new Card((*it)->getSuitNumber(), (*it)->getCardNumber());

	// Remove the card played from the Player Hand
    playerHand->erase(it);

    cardsLeft--;

    return card;
}

int Player::getCardsLeft()
{
	return cardsLeft;
}

list<Card*>* Player::getPlayerHand()
{
	sortPlayerHand();
    return playerHand;
}

void Player::sortPlayerHand()
{
	if (!sortedPlayerHand)
	{
		playerHand->sort([](Card * first, Card* second)
		{
			return first->getCardNumber() < second->getCardNumber();
		});
		sortedPlayerHand = true;
	}
}
