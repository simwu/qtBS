#include "controller.h"

Controller::Controller()
{
	currentPlayer		= 0;
	currentChallenger	= 0;
	numberOfPlayers		= 0;
	discardNumber		= 0;
	playerDiscardNumber = 0;
	currentCardNumber	= 0;
	bullShitInProgress	= false;
}

Controller::~Controller()
{

}

void Controller::newGame(string *playerNames, int numberOfPlayers)
{
    // Create each player and  give them their name
    players = new Player*[numberOfPlayers];

	// Initialize each Player and give each Player its new name
    for (int playerNumber = 0; playerNumber < numberOfPlayers; playerNumber++)
    {
        players[playerNumber] = new Player(playerNames[playerNumber]);
	} 

	this->numberOfPlayers = numberOfPlayers;
	

    // Create the Discard Decks
    discardDeck = new Card*[SUITS * CARDS - 1];
    playerDiscardDeck = new Card*[SUITS * CARDS - 1];

    for (int card = 0; card < SUITS * CARDS; card++)
    {
        discardDeck[card]          = nullptr;
        playerDiscardDeck[card]    = nullptr;
    }

	discardNumber		= 0;
	playerDiscardNumber = 0;

	// Create the Card Deck
	cardDeck = new CardDeck();

	// Shuffle the card deck
    cardDeck->shuffle();

	// Deal each Player's hand
	currentPlayer = 1;

    for (int card = 1; card <= SUITS * CARDS; card++)
    {
        players[currentPlayer - 1]->draw(cardDeck->deal());
		nextPlayer();
	}

	currentPlayer		= 1;

	currentChallenger	= 0;

	currentCardNumber	= ACE;
}

void Controller::nextPlayer()
{
    if (currentPlayer < numberOfPlayers)
    {
		currentPlayer++;
	}
    else
    {
		currentPlayer = 1;
	}
}

bool Controller::gameIsInProgress()
{
	bool inProgress = true;

    for (int playerNumber = 0; playerNumber < numberOfPlayers; playerNumber++)
    {
        if (players[playerNumber]->getCardsLeft() == 0)
        {
			inProgress = false;
			break;
		}
	}
	return inProgress;
}

bool Controller::isBullshitInProgress()
{
	return bullShitInProgress;
}

Player* Controller::getPlayer(int playerNumber)
{
	return players[playerNumber - 1];
}

list<Card*>* Controller::getPlayersHand(int playerNumber)
{
    return players[playerNumber - 1]->getPlayerHand();
}

int Controller::getCardsLeft(int playerNumber)
{
    return players[playerNumber - 1]->getCardsLeft();
}

void Controller::play(int cardNumber)
{
    playerDiscardDeck[playerDiscardNumber] = players[currentPlayer - 1]->play(cardNumber);
	playerDiscardNumber++;
}

void Controller::challengeFinished()
{

    if (playerDiscardNumber > 0)
    {
		// No challege took place. Copy the Player Discard Deck to the Discard Deck
        for (int cardNumber = 0; cardNumber < playerDiscardNumber; cardNumber++)
        {
			discardDeck[discardNumber] = playerDiscardDeck[cardNumber];
			discardNumber++;
			
			// Clear the Card from the discard deck
            playerDiscardDeck[cardNumber] = nullptr;
		}
		playerDiscardNumber = 0;
	}

	bullShitInProgress = false;
	currentChallenger = 0;

    if (gameIsInProgress())
    {
		nextPlayer();

		nextCard();
	}
}

int Controller::getNumberOfPlayers()
{
	return numberOfPlayers;
}

int Controller::getCurrentPlayer()
{
	return currentPlayer;
}

string Controller::getPlayerName(int playerNumber)
{
    return players[playerNumber - 1]->getName();
}

string Controller::getCurrentCard()
{
	string currentCard = "";

    switch (currentCardNumber)
    {
        case ACE:
        {
			currentCard = "Ace";
			break;
		}
        case JACK:
        {
			currentCard = "Jack";
			break;
		}
        case QUEEN:
        {
			currentCard = "Queen";
			break;
		}
        case KING:
        {
			currentCard = "King";
			break;
		}
        default:
        {
			currentCard = to_string(currentCardNumber);
		}
	}
	return currentCard;
}

void Controller::nextCard()
{
    if (currentCardNumber < KING)
    {
		currentCardNumber++;
	}
    else
    {
		currentCardNumber = ACE;
	}
}

bool Controller::bullshit()
{
	bool bull = false;

	// Check the Cards played by the current Player against the current play Card
    for (int cardNumber = 0; cardNumber < playerDiscardNumber; cardNumber++)
    {
        if (playerDiscardDeck[cardNumber] != nullptr && playerDiscardDeck[cardNumber]->getCardNumber() != currentCardNumber)
        {
			bull = true;
			break;
		}
	}

    if (bull)
    {
		// Give the current Player all the Cards played so far
        for (int cardNumber = 0; cardNumber < playerDiscardNumber; cardNumber++)
        {
            players[currentPlayer - 1]->draw(playerDiscardDeck[cardNumber]);

			// Clear the Card from the discard deck
            playerDiscardDeck[cardNumber] = nullptr;
		}

        for (int cardNumber = 0; cardNumber < discardNumber; cardNumber++)
        {
            players[currentPlayer - 1]->draw(discardDeck[cardNumber]);

			// Clear the Card from the discard deck
            discardDeck[cardNumber] = nullptr;
		}
	}
    else
    {
		// Give the challenger Player all the Cards played so far
        for (int cardNumber = 0; cardNumber < playerDiscardNumber; cardNumber++)
        {
            players[currentChallenger - 1]->draw(playerDiscardDeck[cardNumber]);

			// Clear the Card from the discard deck
            playerDiscardDeck[cardNumber] = nullptr;
		}

        for (int cardNumber = 0; cardNumber < discardNumber; cardNumber++)
        {
			players[currentChallenger - 1]->draw(discardDeck[cardNumber]);

			// Clear the Card from the discard deck
            discardDeck[cardNumber] = nullptr;
		}		
	}
	playerDiscardNumber = 0;
	discardNumber		= 0;
	
	challengeFinished();

	return bull;
}

int Controller::getPlayerDiscardNumber()
{
	return playerDiscardNumber;
}

int Controller::getCurrentCardNumber()
{
	return currentCardNumber;
}

int Controller::beginChallengePhase()
{
	bullShitInProgress = true;
	currentChallenger = 0;

	nextChallenger();

	return currentChallenger;
}

void Controller::nextChallenger()
{
	if (currentChallenger < numberOfPlayers)
	{
		currentChallenger++;

		if (currentChallenger == currentPlayer)
		{
			if (currentChallenger < numberOfPlayers)
			{
				currentChallenger++;
			}
			else
			{
				challengeFinished();
			}
		}
	}
	else
	{
		challengeFinished();
	}
}

int Controller::getCurrentChallenger()
{
	return currentChallenger;
}

void Controller::pass()
{
	nextChallenger();
}

int Controller::getDiscardNumber()
{
	return discardNumber;
}
