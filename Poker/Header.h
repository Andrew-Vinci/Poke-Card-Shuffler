#pragma once

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


class Deck {

	struct Cards {
		int mCardNumber;
		string mCardSuit;
		Cards* mNext = NULL;
	};

private:
	Cards* mHead = NULL;

public:
	void createDeck();
	void displayDeck(Cards* card);
	void shuffleDeck(Cards* card);

};
