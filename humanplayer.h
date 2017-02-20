#pragma once

#include "player.h"

class HumanPlayer : Player
{

	private:

	public:
        HumanPlayer(string name);
		~HumanPlayer();

		void play();
};

