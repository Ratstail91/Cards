#include "card_list.hpp"
#include "playing_card.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>

using namespace std;

void dumpList(CardList<PlayingCard, PlayingCardSorter>* clist) {
	for (PlayingCard* it = clist->Peek(0); it; it = it->GetNext()) {
		cout << "Suit: " << it->GetSuit() << "\t\t";
		cout << "Rank: " << it->GetRank() << endl;
	}
	cout << endl;
}

int main() {
	srand(chrono::system_clock::now().time_since_epoch().count());
	CardList<PlayingCard, PlayingCardSorter> clist;

	for (int i = 1; i <= 13; i++) {
		clist.Push(new PlayingCard(PlayingCard::Suit::CLUBS, PlayingCard::Rank(i)));
	}

	dumpList(&clist);

	clist.Shuffle();

	dumpList(&clist);

	while(clist.Peek()) delete clist.Pop();

	return 0;
}