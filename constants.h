#pragma once
#include <string>
using namespace std;

const int MIN_PLAYERS	= 2;
const int MAX_PLAYERS	= 4;

// CARD

const int SUITS			= 4;
const int CARDS			= 13;

const int NO_CARD		= 0;

const int SPADES		= 1;
const int CLUBS			= 2;
const int HEARTS		= 3;
const int DIAMONDS		= 4;
const int ACE			= 1;
const int JACK			= 11;
const int QUEEN			= 12;
const int KING			= 13;

// VIEW

const int LABELS_HGROUP_HEIGHT          = 50;
const int DISCARD_DECK_HGROUP_HEIGHT    = 200;
const int CARD_IMAGE_LABEL_WIDTH        = 100;
const int PLAYER_HAND_HGROUP_HEIGHT     = 200;
const int BUTTONS_GROUPBOX_HEIGHT       = 100;
const int VIEW_BUTTONS_HEIGHT           = 50;
const int VIEW_BUTTONS_WIDTH            = 100;

// NEW GAME VIEW

const int NEW_GAME_VIEW_WIDTH           = 300;
const int NEW_GAME_VIEW_HEIGHT          = 300;
const int NEW_GAME_BUTTONS_GROUP_HEIGHT = 50;
const int NEW_GAME_BUTTON_WIDTH         = 100;
const int NEW_GAME_BUTTON_HEIGHT        = 25;
const int NEW_GAME_NAMES_VGROUP_HEIGHT  = 200;
const int NEW_GAME_NAMES_HGROUP_HEIGHT  = 50;

// MESSAGE VIEW

const int MESSAGE_VIEW_WIDTH            = 765;
const int MESSAGE_VIEW_HEIGHT           = 100;
const int MESSAGE_BUTTON_GROUP_HEIGHT   = 50;
const int MESSAGE_BUTTON_WIDTH          = 100;
const int MESSAGE_BUTTON_HEIGHT         = 25;

const string IMAGE_PATH = ":/resources/images/";
