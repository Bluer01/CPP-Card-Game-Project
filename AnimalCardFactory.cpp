#include "AnimalCardFactory.h"

//Constructor. Produces a random order of the cards
//Order has to be differen with every execution of the program
//Produces a deck of 5 NS, 10 ST, 20 STh, 15 SF
AnimalCardFactory::AnimalCardFactory() {
	for (int i = 0; i < 5; i++) {
		shared_ptr<AnimalCard> card(new Splits(NOSPLIT)); 
		deck.insert(deck.begin(), i , card);
	}
	for (int i = 5; i < 15; i++) {
		shared_ptr<AnimalCard> card(new Splits(SPLITTWO));
		deck.insert(deck.begin(), i , card); 
	}
	for (int i = 15; i < 35; i++) {
		shared_ptr<AnimalCard> card(new Splits(SPLITTHREE));
		deck.insert(deck.begin(), i, card);
	}
	for (int i = 35; i < 50; i++) {
		shared_ptr<AnimalCard> card(new Splits(SPLITFOUR));
		deck.insert(deck.begin(), i, card);
	}
	deck.insert(deck.begin, 50, shared_ptr<AnimalCard>(new Joker())); 
	random_shuffle(deck.begin(), deck.end()); 
}
//returns a pointer to the only instance of AnimalFactory
 AnimalCardFactory * AnimalCardFactory::getFactory()
{
	static AnimalCardFactory* factory; 

	return factory; 
}

//returns a Deck with all animal cards with different order 
Deck<shared_ptr<AnimalCard>> AnimalCardFactory::getDeck() {
	 random_shuffle(deck.begin(), deck.end());
	 return deck; 
}
