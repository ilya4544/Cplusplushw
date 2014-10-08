#include "userInterface.h"

UserInterface::UserInterface() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void UserInterface::paintCards(std::vector<Card> openCards) const {
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
			s = 0;
			break;
		}
		if (card.look().first == HEART || card.look().first == DIAMOND) {
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | LightRed));
		} else
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
		std::cout << s << s << s << s << s << s << s  << s << std::endl;
		char num;
		switch (card.look().second) {
		case 11:
			num = 'J';
			break;
		case 12:
			num = 'Q';
			break;
		case 13:
			num = 'K';
			break;
		case 14:
			num = 'A';
			break;
		default:
			num = (char)card.look().second + '0';
			break;
		}

		for (int i = 0; i < 5; i++) {
		if (i == 2)
			std::cout << s <<"  " << num << "   " << s << std::endl;
		else
			std::cout << s <<"      " << s << std::endl;
		}
		std::cout << s << s << s << s << s << s << s << s << std::endl;
	}
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
}