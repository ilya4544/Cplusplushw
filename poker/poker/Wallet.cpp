#include "Wallet.h"

Wallet::Wallet() {
	money = 0;
}

int Wallet::bid() const {
	return bidPlayer;
}

int Wallet::getMoney() const {
	return money;
}
