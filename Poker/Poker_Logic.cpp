
#include "Header.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;



void Deck::displayDeck(Cards* card) {

    int count = 0;

	while (card != NULL) {

        cout << card->mCardNumber << " ";
		cout << card->mCardSuit << endl;

		card = card->mNext;

        count++;

	}

    cout << "Card Count: " << count << endl;


}

void Deck::shuffleDeck(Cards* card) {

    int number;
    int count = 0;
    int tempNumber;
    string tempSuit;
    const int DECK_SIZE = 51;
    Cards* deck, * ptr;

    srand(time(NULL));


    while (count <= 100000) {

        deck = card;

        number = rand() % DECK_SIZE + 1;

        ptr = deck;

        for (int i = 1; i <= number; i++) {
            ptr = ptr->mNext;
        }

        tempNumber = ptr->mCardNumber;
        tempSuit = ptr->mCardSuit;

        ptr->mCardNumber = deck->mCardNumber;
        ptr->mCardSuit = deck->mCardSuit;

        deck->mCardNumber = tempNumber;
        deck->mCardSuit = tempSuit;

        count++;

    }


    displayDeck(card);

    delete ptr;
    //delete deck;

}

void Deck::createDeck() {

	int j;

	const int DECK_SIZE = 52;
	const int CARD_NUMBER = 13;

	Cards* card = NULL;
    Cards* ptr, *temp;

    int count = 0;

    mHead = card;

    for (j = 1; j <= CARD_NUMBER; j++) {

        ptr = new Cards;
        ptr->mCardNumber = j;
        ptr->mCardSuit = "Diamond";
        ptr->mNext = NULL;

        if (card == NULL) {
            card = ptr;
        }
        else {
            temp = card;
            while (temp->mNext != NULL) {
                temp = temp->mNext;
            }
            temp->mNext = ptr;
        }
    }

    temp = card;
    
    for (j = 1; j <= CARD_NUMBER; j++) {

        ptr = new Cards;
        ptr->mCardNumber = j;
        ptr->mCardSuit = "Hearts";
        ptr->mNext = NULL;

        if (card == NULL) {
            card = ptr;
        }
        else {
            temp = card;
            while (temp->mNext != NULL) {
                temp = temp->mNext;
            }
            temp->mNext = ptr;
        }
    }

    temp = card;

    for (j = 1; j <= CARD_NUMBER; j++) {

        ptr = new Cards;
        ptr->mCardNumber = j;
        ptr->mCardSuit = "Club";
        ptr->mNext = NULL;

        if (card == NULL) {
            card = ptr;
        }
        else {
            temp = card;
            while (temp->mNext != NULL) {
                temp = temp->mNext;
            }
            temp->mNext = ptr;
        }
    }

    temp = card;

    for (j = 1; j <= CARD_NUMBER; j++) {

        ptr = new Cards;
        ptr->mCardNumber = j;
        ptr->mCardSuit = "Spade";
        ptr->mNext = NULL;

        if (card == NULL) {
            card = ptr;
        }
        else {
            temp = card;
            while (temp->mNext != NULL) {
                temp = temp->mNext;
            }
            temp->mNext = ptr;
        }
    }

    //displayDeck(card);
    shuffleDeck(card);

    cout << "--------------------------------------------------------------" << endl;

    //displayDeck(card);

    delete ptr;
    delete temp;
    delete card;

}