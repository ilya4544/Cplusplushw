#include "userInterface.h"

UserInterface::UserInterface() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void UserInterface::paintCards(std::vector<Card> & openCards) const {
	for (size_t i = 0; i < openCards.size(); i++) {
		char s;
		switch (openCards[i].look().first)
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
		if (openCards[i].look().first == HEART || openCards[i].look().first == DIAMOND) {
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | LightRed));
		}
		else
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
		std::cout << s << s << s << s << s << s << s << s << std::endl;
		char num;
		switch (openCards[i].look().second) {
		case Jack:
			num = 'J';
			break;
		case Queen:
			num = 'Q';
			break;
		case King:
			num = 'K';
			break;
		case Ace:
			num = 'A';
			break;
		case Ten:
			num = 'T';
			break;
		default:
			num = (char)openCards[i].look().second + '0';
			break;
		}

		for (int i = 0; i < 5; i++) {
			if (i == 2)
				std::cout << s << "  " << num << "   " << s << std::endl;
			else
				std::cout << s << "      " << s << std::endl;
		}
		std::cout << s << s << s << s << s << s << s << s << std::endl;
	}
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
}