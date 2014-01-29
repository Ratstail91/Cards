/* Copyright: (c) Kayne Ruse 2014
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
*/
#include "card_list.hpp"
#include "playing_card.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef CardList<PlayingCard, AceHigh, CardShuffler<PlayingCard>> PlayingCardList;

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