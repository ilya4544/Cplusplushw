#include "deck.h"

//void Deck::add(Card card) {
//	deck.push_back(card);
//}

void Deck::genFourSuit(int v) {
	deck.push_back(std::move(Card(CLUB, v)));
	deck.push_back(std::move(Card(SPRADE, v)));
	deck.push_back(std::move(Card(HEART, v)));
	deck.push_back(std::move(Card(DIAMOND, v)));
}

void Deck::generateCard(int a) {
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

void Deck::get(std::vector<Card> & cards) {
	cards.push_back(std::move(deck[deck.size()-1]));
	deck.pop_back();
}

void Deck::shuffle() {
	srand((int)time(0));
	for (size_t i = 0; i < deck.size(); i++) {
		int r = rand() % deck.size();
		Card tmp = std::move(deck[i]);
		deck[i] = std::move(deck[r]);
		deck[r] = tmp;
	}
}