#pragma once
using namespace std; 
#include "animalcard.h"
#include "deck.h"
#include <algorithm>


class AnimalCardFactory {
	Deck<shared_ptr<AnimalCard> > deck; 
	AnimalCardFactory();
public:
	static AnimalCardFactory* getFactory();
	Deck<shared_ptr<AnimalCard>> getDeck();
};