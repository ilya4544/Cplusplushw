#include "deck.h"

void Deck::genFourSuit(Value v) {
	deck.emplace_back(std::move(Card(CLUB, v)));
	deck.emplace_back(std::move(Card(SPRADE, v)));
	deck.emplace_back(std::move(Card(HEART, v)));
	deck.emplace_back(std::move(Card(DIAMOND, v)));
}

void Deck::generateCard(int a) {
	if (a >= 24) {
		genFourSuit(Nine);
		genFourSuit(Ten);
		genFourSuit(Ace);
		genFourSuit(Jack);
		genFourSuit(Queen);
		genFourSuit(King);
	}
	if (a >= 32) {
		genFourSuit(Seven);
		genFourSuit(Eight);
	}
	if (a >= 36) {
		genFourSuit(Six);
	}
	if (a >= 52) {
		genFourSuit(Two);
		genFourSuit(Three);
		genFourSuit(Four);
		genFourSuit(Five);
	}
}

void Deck::get(std::vector<Card> & cards) {
	cards.emplace_back(std::move(deck[deck.size()-1]));
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