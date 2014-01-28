#ifndef PLAYINGCARD_HPP_
#define PLAYINGCARD_HPP_

class PlayingCard {
public:
	enum Suit {
		CLUBS = 1, SPADES = 2,
		HEARTS = 3, DIAMONDS = 4
	};
	enum Rank {
		ACE = 1, TWO = 2, THREE = 3,
		FOUR = 4, FIVE = 5, SIX = 6,
		SEVEN = 7, EIGHT = 8, NINE = 9,
		TEN = 10, JACK = 11, QUEEN = 12,
		KING = 13
	};

	PlayingCard() = delete;
	PlayingCard(const Suit s, const Rank r): suit(s), rank(r) {}

	Suit GetSuit() { return suit; }
	Rank GetRank() { return rank; }

	PlayingCard* SetNext(PlayingCard* n) { return next = n; }
	PlayingCard* GetNext() { return next; }

private:
	const Suit suit;
	const Rank rank;
	PlayingCard* next = nullptr;
};

class PlayingCardSorter {
public:
	void operator()(PlayingCard** head) {
		//NOTHING YET
	}
};

#endif
