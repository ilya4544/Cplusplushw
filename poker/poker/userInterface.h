#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "game.h"
#include "Windows.h"
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

class userInterface {
	HANDLE hConsole;
public:
	userInterface() {
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	//void paintOpenCards(std::vector<Card> & openCards);
};
/*
void userInterface::paintOpenCards(std::vector<Card> & openCards) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto card : openCards) {
		if (card.look().first == HEART || card.look().first == DIAMOND) {
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Red));
		}
		else
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
		std::cout << "*******" << std::endl;
		for (int i = 0; i < 5; i++) {
			if (i == 2)
				std::cout << "*  " << card.look().second << "  *" << std::endl;
			else
				std::cout << "*      *" << std::endl;
		}
		std::cout << "*******" << std::endl;
	}
}*/

#endif USERINTERFACE_H