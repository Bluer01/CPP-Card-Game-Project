#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "animalcard.h"
#include <map>

using namespace std;
typedef map<char, int> char_counter; 

AnimalCard::AnimalCard(EvenOdd _EvenOdd, Orientation _Orientation) 
	: d_EvenOdd(_EvenOdd), d_Orientation(_Orientation) {}


EvenOdd AnimalCard::getRow() {
	return d_EvenOdd;
}

/*
	If it ends up being default (not given a preference), finds whatever
	the card's current row is. Otherwise, it prints the row provided of
	the card.
*/
void AnimalCard::printRow(ostream& out, EvenOdd _EvenOdd = DEFAULT) {
	if (_EvenOdd == DEFAULT) {
		_EvenOdd = getRow();
	}
	if (_EvenOdd == EVEN) {
		out << animalCard[0][0] << animalCard[0][1];
	}
	else {
		out << animalCard[1][0] << animalCard[1][1];
	}
}

/*
	The orientation can only be up or down, which flips it 180 degrees, 
	so it swaps the positions of the characters in the array, using
	a temporary character array to store the character it wants to swap
	from where the character moved from in the destination position
*/
void Splits::setOrientation(Orientation _Orientation) {
	if (d_Orientation != _Orientation) {
		char temp = animalCard[0][0];
		animalCard[0][0] = animalCard[1][1];
		animalCard[1][1] = temp;
		temp = animalCard[0][1];
		animalCard[0][1] = animalCard[1][0];
		animalCard[1][0] = temp;
	}

	d_Orientation = _Orientation;
}

void Splits::setRow(EvenOdd _EvenOdd) {
	if (_EvenOdd != DEFAULT) {
		d_EvenOdd = _EvenOdd;
	}
}

// This checks if the card provided is a valid card (only useful for when making the card)
bool inline isValidCard(char card[2][2]/*, vector<std::shared_ptr<AnimalCard>> deck*/) {
	if ( ( card[0][0] == card[1][1] || card[0][1] == card[1][0] ) // If there is a diagonal match for the animal character...
		&& !(card[0][1] == card[1][0] 
			&& card[1][0] == card[1][1] 
			&& card[1][1] == card[0][1] ) // ...but it's not a nosplit (all characters the same) card
		) {	
		return false;
	}
	return true;
}

int inline animalCount(char* animalArray) {
	char_counter count;
	int animalCounter = 0;

	count['b'] = 0;
	count['h'] = 0;
	count['m'] = 0;
	count['d'] = 0;
	count['w'] = 0;

	for (int i = 0; i < 4; i++) {
		count[animalArray[i]]++;
		}
	
	for (auto it = count.begin(); it != count.end(); it++) {
		if (it->second != 0) {
			animalCounter++;
		}
	}
		return animalCounter;
}

bool inline isValidSplitTwo(char card[2][2]) { 

	if (animalCount((char*)card) == 2) {
		return true;
	}
	return false; 
}

bool inline isValidNoSplit(char card[2][2]) { 

	if (animalCount((char*)card) == 1) {
		return true;
	}

	return false;
}

bool inline isValidSplitThree(char card[2][2]) { 

	if (animalCount((char*)card) == 3) {
		return true;
	}

	return false; 
}

bool inline isValidSplitFour(char card[2][2]) { 
	
	if (animalCount((char*)card) == 4) {
		return true;
	}

	return false; 
}

bool inline isValidType(char card[2][2], SplitType split) {
	if (split == NOSPLIT) {
		return isValidNoSplit(card);
	}
	else if (split == SPLITTWO) {
		return isValidSplitTwo(card);
	}
	else if (split == SPLITTHREE) {
		return isValidSplitThree(card);
	}
	else if (split == SPLITFOUR) {
		return isValidSplitFour(card);
	}
	return false;
}

/*
	Simplifies the derived classes from NoSplit, SplitTwo, etc. into Splits
*/
Splits::Splits(SplitType _SplitType, EvenOdd _EvenOdd, Orientation _Orientation)
	: AnimalCard(_EvenOdd, _Orientation) {
	
	do {
		for (int i = 0; i < 2; i++) { // Row
			for (int j = 0; j < 2; j++) { // Column
				animalCard[i][j] = animals[rand() % (4 + 1)]; // Assigns a random character from the animals character array
			}												  // to each position in the card array
		}
	} while (!isValidCard(animalCard) || !isValidType(animalCard, _SplitType)); // Makes a new array until it's a valid card
}

Joker::Joker() {
	for (int i = 0; i < 2; i++) { // Row
		for (int j = 0; j < 2; j++) { // Column
			animalCard[i][j] = 'j';
		}
	}
}

StartCard::StartCard() {
	for (int i = 0; i < 2; i++) { // Row
		for (int j = 0; j < 2; j++) { // Column
			animalCard[i][j] = 'c';
		}
	}
}
