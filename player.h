#pragma once
#include <iostream>
#include <list>
#include <memory>
#include "animalcard.h"
#include "hand.h"

using std::string;
using std::ostream;

class Player {
protected:
	string name;
	string secretAnimal;
	Hand playerHand;
public:
	string swapSecretAnimal(string& animal);
	void swapHands(Player &player);
	string getSecretAnimal();
	string getName();
	friend ostream& operator << (ostream &out , Player& );
	Player player(string& secretAnimal);
	void giveCard(std::shared_ptr<AnimalCard> card);
	void setSecretAnimal(string& animal);
};