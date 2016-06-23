#pragma once
#include <list>
#include <memory>
#include "animalcard.h"
#include <iostream>
#include <exception>
using namespace std; 

class Hand {
public:
	list<shared_ptr<AnimalCard>> hand;
	Hand();
	Hand& operator+=(shared_ptr<AnimalCard>);
	Hand& operator-=(shared_ptr<AnimalCard>);
	shared_ptr<AnimalCard> operator[](int);
	int noCards();
	friend ostream &operator << (ostream &, const Hand&);


};

class MissingCard : public exception {
	virtual const char* what() const throw() {
	
		return "Card is missing exception";
	}

};