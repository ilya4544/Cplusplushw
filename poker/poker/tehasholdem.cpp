#include "tehasholdem.h"
int bigBlind, smallBlind, nowBet, allCash, bound;

void TehasHoldem::trade(int index, std::vector<bool> & fold, std::vector<Card> & openCards) {
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
		int bidOld = players[index]->bidPlay();
		int k = stepPlayer(players[index], nowBet);
		if (k == 0) {
			std::cout << players[index]->name() << " check" << std::endl;
			allCash += nowBet - bidOld;
		}
		else
			if (k > 0) {

			bound = index;
			nowBet += k;
			allCash += nowBet - bidOld;
			std::cout << players[index]->name() << " bet " << nowBet << std::endl;
			}
			else
				if (k == -1) {
			std::cout << players[index]->name() << " fold:(" << std::endl;
			fold[index] = true;
				}
		index++;
		if (index == (int)players.size()) index = 0;
	}
}

//Custom comparator to sort cards
bool comparator(std::pair<int,int> & left, std::pair<int,int> & right) {
	if (left.second == right.second)
		return left.first < right.first;
	return left.second < right.second;
}

std::pair<int, int> TehasHoldem::maxCombination(Player * player, std::vector<Card> & openCards) const{
	std::vector<std::pair<int, int> > all;
	for (size_t i = 0; i < openCards.size(); i++)
		all.push_back(openCards[i].look());
	all.push_back(lookCards(player)[0].look());
	all.push_back(lookCards(player)[1].look());
	std::vector<std::vector<std::pair<int, int> > > allComb;
	std::sort(all.begin(), all.end(), comparator);

	int cntStrit = 0, cntFlesh = 0, highCard = all[0].second, cntPair = 0, indexPair = 0;
	std::vector<int> flesh(4);
	std::pair<int, int> highComb(0, 0);
	std::vector<int> suitPrev;
	flesh[all[0].first]++;
	for (size_t i = 1; i < all.size(); i++) {
		flesh[all[i].first]++; // Counting for flesh 

		if (highCard < all[i].second) highCard = all[i].second; //Finding high card

		if (all[i].second - all[i - 1].second == 1) {
			if (cntPair != 0) {
				cntPair = 0;
				indexPair++;
			}
			cntStrit++;
			if (all[i].first == all[i - 1].first)
				cntFlesh++;
			else {
				bool flag = false;
				for (auto it : suitPrev)
					if (all[i].first == it) {
					cntFlesh++;
					flag = true;
					}
				if (!flag) cntFlesh = 0;
			}
			suitPrev.clear();
		}
		else
			if (all[i].second - all[i - 1].second == 0) { //Finding pair
			if (cntPair != 0) {
				allComb[indexPair].push_back(all[i]);
				cntPair++;
			}
			else {
				std::vector<std::pair<int, int> > tmp;
				tmp.push_back(all[i - 1]);
				tmp.push_back(all[i]);
				allComb.push_back(tmp);
				cntPair = 2;
			}
			suitPrev.push_back(all[i - 1].first);
			}
			else
				if (all[i].second - all[i - 1].second > 1) {
			if (cntPair != 0) {
				cntPair = 0;
				indexPair++;
			}
			if (cntStrit >= 4) {
				if (cntFlesh >= 4) { //Strit-flesh
					highComb.first = 9;
					highComb.second = all[i].second;
				}
				else { //Strit
					highComb.first = 5;
					highComb.second = all[i].second;
				}
			}
			cntStrit = 0;
			cntFlesh = 0;
			suitPrev.clear();
				}
	}
	if (cntStrit >= 4) {
		if (cntFlesh >= 4) { // Strit-flesh
			highComb.first = 9;
			highComb.second = all.back().second;
		}
		else { // Strit
			highComb.first = 5;
			highComb.second = all.back().second;
		}
	}

	// Check flesh
	for (int i = 3; i >= 0; i--)
		if (flesh[i] >= 5) {
		if (highComb.first < 6) {
			highComb.first = 6;
			highComb.second = highCard;
		}
		}

	for (int i = allComb.size() - 1; i >= 0; i--) {
		if (allComb[i].size() == 4) { //Found care(4 card)
			if (highComb.first < 8) {
				highComb.first = 8;
				highComb.second = allComb[i][0].second;
			}
			break;
		}
		if (allComb[i].size() == 3) {
			if (highComb.first < 4) {
				if (highComb.first > 1) { // Was pair or two pairs + triple = full house
					highComb.first = 7;
					if (highComb.second < allComb[i][0].second) highComb.second = allComb[i][0].second;
				}
				else {
					highComb.first = 4;
					highComb.second = allComb[i][0].second;
				}
			}
		}
		if (allComb[i].size() == 2) {
			if (highComb.first == 4) { //Was triple + 1 pair = full house
				highComb.first = 7;
				if (highComb.second < allComb[i][0].second) highComb.second = allComb[i][0].second;
			}
			else if (highComb.first == 2) { //Was 1 pair + 1 pair = two pairs
				highComb.first = 3;
				if (highComb.second < allComb[i][0].second) highComb.second = allComb[i][0].second;
			}
			else if (highComb.first < 2) { //Nothing + 1 pair = 1 pair
				highComb.first = 2;
				highComb.second = allComb[i][0].second;
			}
		}
	}

	if (highComb.first == 0) { // If nothing, then high card
		highComb.first = 1;
		highComb.second = highCard;
	}

	return highComb;
}


std::vector<int> TehasHoldem::playRound() {
	nowBet = 20;
	allCash = 30;
	bound = bigBlind;
	std::vector<bool> fold(players.size(), false);
	std::vector<Card> openCards;

	for (size_t i = 0; i < players.size(); i++) {
		getCard(players[i]);
		getCard(players[i]);
	}

	bet(players[smallBlind], 10);
	bet(players[bigBlind], 20);
	trade(bound + 1, fold, openCards);
	for (int i = 0; i < 3; i++) {
		getFromDeck(openCards);
		openCards.back().open();
	}
	uInterface.paintCards(openCards);
	trade(bound, fold, openCards);
	getFromDeck(openCards);
	openCards.back().open();
	uInterface.paintCards(openCards);
	trade(bound, fold, openCards);
	getFromDeck(openCards);
	openCards.back().open();
	uInterface.paintCards(openCards);
	trade(bound, fold, openCards);

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
	generateCardDeck(52);
	shuffleDeck();
	players = playersAll;

	for (size_t i = 0; i < players.size(); i++)
		addMoney(players[i], 2000);
	smallBlind = 0;
	bigBlind = 1;
	while (players.size() > 1) {
		std::vector<int> winners = playRound();
		for (size_t i = 0; i < winners.size(); i++)
			addMoney(players[winners[i]], (int)(allCash / winners.size()));
		for (auto it = players.begin(); it != players.end();)
			if (money((*it)) <= 0) {
			it = players.erase(it);
			}
			else {
				clearCards(*it);
				nullBid(*it);
				it++;
			}
	}
	std::cout << "Player " << players[0]->name() << " winner!" << std::endl;
	system("pause");
}