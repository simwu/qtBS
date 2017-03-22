#pragma once

#include "player.h"
#include "carddeck.h"

class Controller
{
	
	private:
        Player		**players;
        CardDeck	*cardDeck;
		int			numberOfPlayers;
		int			currentPlayer;
		int			currentChallenger;
        Card		**discardDeck;
        Card		**playerDiscardDeck;
		int			discardNumber;
		int			playerDiscardNumber;
		int			currentCardNumber;

		bool		bullShitInProgress;

		void		nextCard();
		void		nextPlayer();
		void		nextChallenger();

	public:
		Controller();
		~Controller();

		const string VERSION = "Bullshit! Version 0.5";

        void newGame(string *playerNames, int numberOfPlayers);
		
		bool gameIsInProgress();
		list<Card*>* getPlayersHand(int playerNumber);
		int getCardsLeft(int playerNumber);
		void play(int cardNumber);
		void challengeFinished();
		int getNumberOfPlayers();
		int getCurrentPlayer();
		string getPlayerName(int playerNumber);
		string getCurrentCard();
		bool bullshit();
		int getPlayerDiscardNumber();
		int beginChallengePhase();
		int getCurrentCardNumber();

		int getCurrentChallenger();
		bool isBullshitInProgress();
		void pass();
		int getDiscardNumber();

		// FOR TEST PURPOSES ONLY
        Player* getPlayer(int playerNumber);
};

