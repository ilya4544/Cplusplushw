#include "userInterface.h"

UserInterface::UserInterface() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void UserInterface::paintCards(std::vector<Card> & openCards) {
	for (auto card : openCards) {
		char s;
		switch (card.look().first)
		{
		case HEART:
			s = 3;
			break;
		case DIAMOND:
			s = 4;
			break;
		case CLUB:
			s = 5;
			break;
		case SPRADE:
			s = 6;
			break;
		default:
			break;
		}
		if (card.look().first == HEART || card.look().first == DIAMOND) {
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | LightRed));
		}
		else
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
			std::cout << s << s << s << s << s << s << s  << s << std::endl;
		for (int i = 0; i < 5; i++) {
			if (i == 2)
				std::cout << s <<"  " << card.look().second << "  " << s << std::endl;
			else
				std::cout << s <<"      " << s << std::endl;
		}
		std::cout << s << s << s << s << s << s << s << s << std::endl;
	}
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
}