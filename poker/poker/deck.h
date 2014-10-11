#ifndef DECK_H
#define DECK_H
#include <vector>
#include <ctime>
#include <algorithm>
#include "card.h"
class Card;

// Singleton class Deck with lazy initialization
class Deck {
	Deck() {};
	Deck(Deck const&);              // Don't Implement
	void operator=(Deck const&);	// Don't implement

	std::vector<Card> deck;

	void genFourSuit(int v);
	void generateCard(int);
	void get(std::vector<Card> &);
	void shuffle();
	friend class Game;
public:
	static Deck& getInstance() {
		static Deck instance;
		return instance;
	}
};

#endif DECK_H