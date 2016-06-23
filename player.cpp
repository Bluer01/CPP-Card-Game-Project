#include "player.h"
#include "hand.h"
#include <algorithm>
#include <string>


Player Player::player(string &animal) {
	secretAnimal = animal;
}

string Player::swapSecretAnimal(string& animal) {
	string a = animal;
	for (int i = 0; a[i]; i++) a[i] = tolower(a[i]);
	if (a == "bear"  || a == "deer" ||
		a == "moose" || a == "wolf" ||
		a == "hare")
	{
		string oldSecretAnimal = secretAnimal;
		secretAnimal = animal;
		return oldSecretAnimal;
	}
}

string Player::getSecretAnimal() {
	return secretAnimal;
}

void Player::swapHands(Player &player) {
	Hand tempHand;
	tempHand = player.playerHand;

	player.playerHand = playerHand;

	playerHand = tempHand;
}

string Player::getName() {
	return name;
}

ostream& operator<< (ostream &out, Player& p) {
	out << "Player name: " << p.getName() << endl;
	out << "Player's hand: " << p.playerHand << endl;
	out << "Player's secret animal: " << p.getSecretAnimal() << endl;
}

void Player::giveCard(shared_ptr<AnimalCard> card) {
	playerHand += card;
}

void Player::setSecretAnimal(string& animal) {
	name = animal;
}


