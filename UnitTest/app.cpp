#include "controller.h"
#include "controller.cpp"
#include "player.cpp"
#include "carddeck.cpp"
#include "card.cpp"
#include <iostream>
#include <string>
using namespace std;

void main() {

	// FOR STUDENTS
	// Test Bullshit challenge phase
	Controller controller;

	string *playerNames = new string[4];
	playerNames[0] = "Javier";
	playerNames[1] = "Jude";
	playerNames[2] = "Lucy";
	playerNames[3] = "Sophie";

	cout << "New game" << endl << endl;
	controller.newGame(playerNames, 4);

	cout << "Current Player:     " << controller.getCurrentPlayer() << endl;
	
	controller.beginChallengePhase();
	cout << endl << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	cout << endl << "Next Player:        " << controller.getCurrentPlayer() << endl;

	controller.beginChallengePhase();
	cout << "Current Challenger: " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	cout << endl << "Next Player:        " << controller.getCurrentPlayer() << endl;

	controller.beginChallengePhase();
	cout << "Current Challenger: " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	cout << endl << "Next Player:        " << controller.getCurrentPlayer() << endl;

	controller.beginChallengePhase();
	cout << "Current Challenger: " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	cout << endl << "Next Player:        " << controller.getCurrentPlayer() << endl;

	controller.beginChallengePhase();
	cout << "Current Challenger: " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	cout << endl << "Next Player:        " << controller.getCurrentPlayer() << endl;

	controller.pass();
	cout << "Current Challenger: " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;

	controller.pass();
	cout << "Next Challenger:    " << controller.getCurrentChallenger() << endl;
}
