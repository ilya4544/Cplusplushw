#include "tehasholdem.h"
int bigBlind, smallBlind, nowBet, allCash;
#include <iostream>

void TehasHoldem::trade(int index, std::vector<Player> & playersRound, std::vector<bool> & fold) {
	int bound = bigBlind;
	while (index != bound) {
		if (index == playersRound.size()) index = 0;
		if (fold[index]) {
			index++;
			continue;
		}
		int bidOld = playersRound[index].bid();
		int k = stepPlayer(playersRound[index], nowBet);
		if (k == 0) {
			allCash += nowBet - bidOld;
		}
		if (k > 0) {
			bound = index;
			nowBet += k;
			allCash += nowBet - bidOld;
		}
		if (k == -1) {
			fold[index] = true;
		}
		index++;
	}
	bigBlind++;
	if (bigBlind == countPlayers) bigBlind = 0;
	smallBlind++;
	if (smallBlind == countPlayers) smallBlind = 0;
}

std::pair<int, int> TehasHoldem::maxCombination(Player & player, std::vector<Card> & openCards) const{
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
		highCard = std::max(highCard, all[i].look().second);
		if (search.size() > 1) {
			for (size_t i = 0; i < usedIn.size(); i++)
				used[i] = usedIn[i];
			allComb.push_back(search);
		}
		pair = std::max(pair, (int)search.size());
	}
	return std::make_pair(1, highCard);
}


std::vector<Player> TehasHoldem::playRound() {
	int count = countPlayers;
	nowBet = 20;
	smallBlind = 0;
	bigBlind = 1;
	allCash = 30;
	std::vector<Player> playersRound = players;
	std::vector<bool> fold(playersRound.size(), false);
	std::vector<Card> openCards;

	for (size_t i = 0; i < playersRound.size(); i++) {
		playersRound[i].getCard(deck);
		playersRound[i].getCard(deck);
	}
	playersRound[smallBlind].bet(10);
	playersRound[bigBlind].bet(20);
	trade(bigBlind + 1, playersRound, fold);
	for (int i = 0; i < 3; i++) {
		openCards.push_back(deck.get());
		openCards.back().open();
	}
	trade(bigBlind + 1, playersRound, fold);
	openCards.push_back(deck.get());
	openCards.back().open(); 
	trade(bigBlind + 1, playersRound, fold);
	openCards.push_back(deck.get());
	openCards.back().open(); 
	trade(bigBlind + 1, playersRound, fold);
	
	std::vector<std::pair<int, int> > results;
	for (size_t i = 0; i < playersRound.size(); i++) {
		if (fold[i]) continue;
		//openCards += lookCards(playersRound[i]);
		std::pair<int, int> result = maxCombination(playersRound[i], openCards);
		results.push_back(result);
	}
	std::vector<Player> winners;
	auto bestCombination = std::max_element(results.begin(), results.end());
	for (size_t i = 0; i < playersRound.size(); i++)
		if (results[i] == *bestCombination)
			winners.push_back(playersRound[i]);
	return winners;
}

void TehasHoldem::runGame(std::vector<Player> playersAll) {
	deck = Deck(52);
	players = playersAll;

	for (size_t i = 0; i < players.size(); i++)
		addMoney(players[i], 2000);

	while (players.size() != 1) {
		std::vector<Player> winners = playRound();
		for (size_t i = 0; i < winners.size(); i++)
			addMoney(winners[i],(int) (allCash / winners.size()));
		for (auto it = players.begin(); it != players.end(); it++)
			if (money(*it) <= 0) {
				auto newIt = it;
				players.erase(newIt);
			}
	}
	std::cout << "Player " << players[0].name() << " winner!" << std::endl;
}