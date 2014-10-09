#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "card.h"
#include "Windows.h"
#include <string>
#include <vector>
#include <iostream>

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

class UserInterface {
	HANDLE hConsole;
public:
	UserInterface();
	void paintCards(std::vector<Card> & openCards) const;
};

#endif USERINTERFACE_H