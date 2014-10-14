#ifndef DECK_H
#define DECK_H
#include <algorithm>
#include <ctime>
#include <vector>
#include "card.h"
class Card;

// Singleton class Deck with lazy initialization
class Deck {
	Deck() {};
	Deck(Deck const&);              // Don't Implement
	void operator=(Deck const&);	// Don't implement

	std::vector<Card> deck;

	void genFourSuit(Value v);
	void generateCard(int);
	void get(std::vector<Card> &);
	void shuffle();
	friend class Game;
public:
	static Deck& getInstance() { // Return an instance of deck
		static Deck instance;
		return instance;
	}
};

#endif // !DECK_H