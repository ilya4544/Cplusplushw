#include "RealPlayer.h"

RealPlayer::RealPlayer() : Player() {}

RealPlayer::RealPlayer(std::string name, int m) : Player(name, m) {}

int RealPlayer::run(int nowBet) {
	while (true) {
		std::cout << "If you want to see your card?(l). Check, raise or fold?(c/r/f)" << std::endl;
		std::string str;
		std::cin >> str;
		if (str == "c") {
			bet(nowBet);
			return 0;
		}
		if (str == "r") {
			int raise;
			std::cout << "Enter your new bet:";
			std::cin >> raise;
			bet(raise);
			return raise - nowBet;
		}
		if (str == "f") {
			return -1;
		}
		std::cout << "Sorry, enter correct answer" << std::endl;
	}
}
