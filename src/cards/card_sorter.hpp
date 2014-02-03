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
#ifndef CARDSORTER_HPP_
#define CARDSORTER_HPP_

template<typename Card>
class CardSorter {
public:
	void operator()(Card** head) {
		//don't sort an empty list
		if (!(*head)) return;

		//initialize the tmp list
		Card* tmpHead = PopTop(head);

		while(*head) {
			//get the card to move
			Card* floatingCard = PopTop(head);

			//insert at the start
			if (Compare(floatingCard, tmpHead) < 0) {
				floatingCard->SetNext(tmpHead);
				tmpHead = floatingCard;
				continue;
			}

			//find it's spot
			for (Card* it = tmpHead; it; it = it->GetNext()) {
				//insert at the end
				if (!it->GetNext()) {
					Insert(it, floatingCard);
					break;
				}

				//insert in the middle
				if (Compare(floatingCard, it->GetNext()) < 0) {
					Insert(it, floatingCard);
					break;
				}
			}
		}

		//"return" the sorted list
		(*head) = tmpHead;
	}

protected:
	virtual int Compare(Card* lhs, Card* rhs) = 0;

	Card* PopTop(Card** head) {
		Card* ret = *head;
		(*head) = (*head)->GetNext();
		ret->SetNext(nullptr);
		return ret;
	}

	void Insert(Card* prev, Card* n) {
		n->SetNext(prev->GetNext());
		prev->SetNext(n);
	}
};

template<typename Card>
class DummySorter {
public:
	void operator()(Card**) {
		;//DO NOTHING
	}
};

#endif
