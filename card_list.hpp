#ifndef CARDLIST_HPP_
#define CARDLIST_HPP_

#include "card_shuffler.hpp"

template<typename Card, typename Sorter, typename Shuffler = CardShuffler<Card>>
class CardList {
public:
	Card* Push(Card*);
	Card* Peek(int index = 0);
	Card* Pop(int index = 0, int count = 1);

	void Sort() { sorter(&head); }
	void Shuffle() { shuffler(&head); }

private:
	Card* head = nullptr;
	Sorter sorter;
	Shuffler shuffler;
};

template<typename Card, typename Sorter, typename Shuffler>
Card* CardList<Card,Sorter,Shuffler>::Push(Card* slab) {
	//recieve any number of cards
	if (!slab) return nullptr;
	Card* tmp = head;
	head = slab;
	while (slab->GetNext()) slab = slab->GetNext();
	slab->SetNext(tmp);
}

template<typename Card, typename Sorter, typename Shuffler>
Card* CardList<Card,Sorter,Shuffler>::Peek(int index) {
	Card* it = head;
	while (it && index--) it = it->GetNext();
	return it;
}

template<typename Card, typename Sorter, typename Shuffler>
Card* CardList<Card,Sorter,Shuffler>::Pop(int index, int count) {
	//nothing to return
	if (!head) return nullptr;

	if (index == 0) {
		//returning the first card
		Card* ret = head, *tail = head;
		while(tail->GetNext() && --count) tail = tail->GetNext();
		head = tail->GetNext();
		tail->SetNext(nullptr);
		return ret;
	}

	//locate the slab
	Card* prev = head;
	while(prev && --index) prev = prev->GetNext();
	Card* tail = prev;
	while(tail && count--) tail = tail->GetNext();

	//prev or tail overruns the list
	if (!prev) return nullptr;
	if (!tail) {
		Card* ret = prev->GetNext();
		prev->SetNext(nullptr);
		return ret;
	}

	//cut the slab out
	Card* ret = prev->GetNext();
	prev->SetNext(tail->GetNext());
	tail->SetNext(nullptr);

	return ret;
}

#endif
