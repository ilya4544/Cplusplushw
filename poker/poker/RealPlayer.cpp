#include "RealPlayer.h"

RealPlayer::RealPlayer() : Player() {}

RealPlayer::RealPlayer(std::string name) : Player(name) {}

int RealPlayer::run(int nowBet) const {
	for (;;) {
		std::cout << playerName << ", if you want to see your card?(l). Check, raise or fold?(c/r/f)" << std::endl;
		std::string str;
		std::cin >> str;

		if (str == "l") {
			uInterface.paintCards(cards);
		}
		else
			if (str == "c") {
			return nowBet;
			}
			else
				if (str == "r") {
			int raise;
			std::cout << "Enter your new bet:";
			std::cin >> raise;
			return raise;
				}
				else
					if (str == "f") {
			return -1;
					}
					else
						std::cout << "Sorry, enter correct answer" << std::endl;
	}
}