#ifndef CARDSHUFFLER_HPP_
#define CARDSHUFFLER_HPP_

#include <cstdlib>

template<typename Card>
class CardShuffler {
public:
	void operator()(Card** head) {
		//count the number of cards
		int size = 0;
		Card* it = *head;
		while (it) it = it->GetNext(), size++;

		//shuffle the cards
		Card* tmpHead = nullptr;
		while(size) {
			Push(&tmpHead, PopRandom(head, size));
			size--;
		}

		*head = tmpHead;
	}

private:
	Card* PopRandom(Card** head, int size) {
		//choose a card to return
		int i = rand() % size;

		//returning the top card
		if (i == 0) {
			Card* ret = *head;
			(*head) = (*head)->GetNext();
			return ret;
		}

		//find the prev of the card to return
		Card* prev = *head;
		while(--i) prev = prev->GetNext();

		//pop this card
		Card* ret = prev->GetNext();
		prev->SetNext(ret->GetNext());
		ret->SetNext(nullptr);

		return ret;
	}
	void Push(Card** head, Card* n) {
		n->SetNext(*head);
		(*head) = n;
	}
};

#endif
