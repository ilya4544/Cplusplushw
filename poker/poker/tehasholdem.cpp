#include "tehasholdem.h"
#include <iostream>
int bigBlind, smallBlind, nowBet, allCash, bound;

void TehasHoldem::trade(int index, std::vector<bool> & fold) {
	bool flag = false;
	if (bound == index) {
		flag = true;
		bound++;
	}
	while (index != bound) {
		if (index == (int)players.size()) index = 0;
		if (flag) {
			bound--;
			flag = false;
		}
		if (fold[index]) {
			index++;
			continue;
		}
		std::cout << players[index]->name() << " thinking..." << std::endl;
		int bidOld = players[index]->bid();
		int k = stepPlayer(players[index], nowBet);
		if (k == 0) {
			std::cout << players[index]->name() << " check" << std::endl;
			allCash += nowBet - bidOld;
		} else
		if (k > 0) {
			
			bound = index;
			nowBet += k;
			allCash += nowBet - bidOld;
			std::cout << players[index]->name() << " bet " << nowBet << std::endl;
		} else
		if (k == -1) {
			std::cout << players[index]->name() << " fold:(" << std::endl;
			fold[index] = true;
		}
		index++;
		if (index == (int)players.size()) index = 0;
	}
}

std::pair<int, int> TehasHoldem::maxCombination(Player * player, std::vector<Card> & openCards) const{
	std::vector<Card> all = openCards;
	all.push_back(lookCards(player)[0]);
	all.push_back(lookCards(player)[1]);
	std::vector<std::vector<Card> > allComb;
	std::vector<bool> used(7, false);
	int pair = 1;
	int highCard = 0;
	for (size_t i = 0; i < all.size(); i++) {
		if (used[i]) continue;
		std::vector<Card> search;
		std::vector<bool> usedIn(7, false);
		search.push_back(all[i]);
		usedIn[i] = true;
		for (size_t j = 0; j < all.size(); j++) {
			if (i == j) continue;
			if (all[i].look().second == all[j].look().second) {
				search.push_back(all[j]);
				usedIn[j] = true;
			}
		}
		if (highCard < all[i].look().second)
			highCard = all[i].look().second;
		if (search.size() > 1) {
			for (size_t i = 0; i < usedIn.size(); i++)
				used[i] = usedIn[i];
			allComb.push_back(search);
		}
		if (pair < (int)search.size()) {
			pair = (int)search.size();
		}
	}
	return std::make_pair(1, highCard);
}


std::vector<int> TehasHoldem::playRound() {
	//int count = countPlayers;
	nowBet = 20;
	allCash = 30;
	bound = bigBlind;
	std::vector<bool> fold(players.size(), false);
	std::vector<Card> openCards;

	for (size_t i = 0; i < players.size(); i++) {
		players[i]->getCard(deck);
		players[i]->getCard(deck);
	}

	players[smallBlind]->bet(10);
	players[bigBlind]->bet(20);
	trade(bound + 1, fold);
	for (int i = 0; i < 3; i++) {
		openCards.push_back(deck.get());
		openCards.back().open();
	}
//	paintOpenCards(openCards);
	trade(bound, fold);
	openCards.push_back(deck.get());
	openCards.back().open(); 
	trade(bound, fold);
	openCards.push_back(deck.get());
	openCards.back().open(); 
	trade(bound, fold);
	
	std::vector<std::pair<int, int> > results;
	for (size_t i = 0; i < players.size(); i++) {
		std::pair<int, int> result;
		if (fold[i])
			result = std::make_pair(-1, -1);
		else 
			result = maxCombination(players[i], openCards);
		results.push_back(result);
	}
	std::vector<int> winners;
	auto bestCombination = std::max_element(results.begin(), results.end());
	for (size_t i = 0; i < players.size(); i++)
		if (results[i] == *bestCombination) {
			std::cout << players[i]->name() << " win this round!" << std::endl;
			winners.push_back(i);
		}
	bigBlind++;
	if (bigBlind == (int)players.size()) bigBlind = 0;
	smallBlind++;
	if (smallBlind == (int)players.size()) smallBlind = 0;
	return winners;
}

void TehasHoldem::runGame(std::vector<Player*> playersAll) {
	deck = Deck(52);
	deck.shuffle();
	players = playersAll;

	for (size_t i = 0; i < players.size(); i++)
		addMoney(players[i], 2000);
	smallBlind = 0;
	bigBlind = 1;
	while (players.size() != 1) {
		std::vector<int> winners = playRound();
		for (size_t i = 0; i < winners.size(); i++)
			addMoney(players[winners[i]], (int)(allCash / winners.size()));
		for (auto it = players.begin(); it != players.end();)
			if (money((*it)) <= 0) {
				it = players.erase(it);
			}
			else {
				nullBid(*it);
				it++;
			}
	}
	std::cout << "Player " << players[0]->name() << " winner!" << std::endl;
}