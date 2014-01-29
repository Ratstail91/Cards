#include "card_list.hpp"
#include "playing_card.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef CardList<PlayingCard, AceLow, CardShuffler<PlayingCard>> PlayingCardList;

void dumpList(PlayingCardList* clist) {
	for (PlayingCard* it = clist->Peek(0); it; it = it->GetNext()) {
		cout << "Suit: " << it->GetSuit() << "\t\t";
		cout << "Rank: " << it->GetRank() << endl;
	}
	cout << endl;
}

int main() {
	srand(chrono::system_clock::now().time_since_epoch().count());
	PlayingCardList clist;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 13; i++) {
			clist.Push(new PlayingCard(PlayingCard::Suit(j+1), PlayingCard::Rank(i+1)));
		}
	}

	dumpList(&clist);
	clist.Shuffle();
	dumpList(&clist);
	clist.Sort();
	dumpList(&clist);

	while(clist.Peek()) delete clist.Pop();

	return 0;
}