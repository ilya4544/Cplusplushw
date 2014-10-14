#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <iostream>
#include <string>
#include <vector>
#include "Windows.h"
#include "card.h"

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

// Implement interaction with console(UI)
class UserInterface {
	HANDLE hConsole;
public:
	UserInterface(); // Default constructor
	void paintCards(std::vector<Card> & openCards) const; // Paint cards on console
};

#endif // !USERINTERFACE_H