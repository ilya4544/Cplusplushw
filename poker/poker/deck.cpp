#include "deck.h"

void Deck::add(Card card) {
	deck.push_back(card);
}

void Deck::genFourSuit(int v) {
	add(Card(CLUB, v));
	add(Card(SPRADE, v));
	add(Card(HEART, v));
	add(Card(DIAMOND, v));
}

Deck::Deck(int a) {
	if (a >= 24) {
		genFourSuit(9);
		genFourSuit(10);
		genFourSuit(14);
		genFourSuit(11);
		genFourSuit(12);
		genFourSuit(13);
	}
	if (a >= 32) {
		genFourSuit(7);
		genFourSuit(8);
	}
	if (a >= 36) {
		genFourSuit(6);
	}
	if (a >= 52) {
		genFourSuit(2);
		genFourSuit(3);
		genFourSuit(4);
		genFourSuit(5);
	}
}

Card Deck::get() {
	Card a = deck.back();
	deck.pop_back();
	return a;
}

void Deck::shuffle() {
	srand((int)time(0));
	for (size_t i = 0; i < deck.size(); i++) {
		std::swap(deck[i], deck[rand() % deck.size()]);
	}
}