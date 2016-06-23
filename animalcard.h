#pragma once
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

enum EvenOdd { EVEN, ODD, DEFAULT };
enum Orientation { UP, DOWN };
enum SplitType { NOSPLIT, SPLITTWO, SPLITTHREE, SPLITFOUR };
const char animals[] = { 'b', 'd', 'w', 'h', 'm' }; // Used for assigning a chracter randomly to a card array position


class AnimalCard {
protected:
	EvenOdd d_EvenOdd;
	Orientation d_Orientation;
	char animalCard[2][2] = { 'z' }; // 'z' is used as a placeholder, so that we also know if there's a print/assignment problem

public:
	AnimalCard(EvenOdd _EvenOdd = EVEN, Orientation _Orientation = UP);

	virtual void setOrientation(Orientation) = 0;

	virtual void setRow(EvenOdd) = 0;

	virtual EvenOdd getRow();

	virtual void printRow(ostream&, EvenOdd);

	//char** getRow();

};

class Splits : public AnimalCard {
public:
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);

	Splits(SplitType _SplitType = NOSPLIT, EvenOdd _EvenOdd = EVEN, Orientation _Orientation = UP);
};

class Joker : public Splits {
public:
	Joker();
};

class StartCard : public Splits {
public:
	StartCard();
};