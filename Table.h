#pragma once
#include "animalcard.h"
#include "actioncard.h"
#include "startstack.h"

using namespace std; 

class Table {
	enum CompareType { UP, RIGHT, LEFT, DOWN };
	bool check(string, shared_ptr<AnimalCard>);
	shared_ptr<AnimalCard> table[103][103];
	bool match(shared_ptr<AnimalCard>, shared_ptr<AnimalCard>, CompareType);
	shared_ptr<StartStack> start;
	static vector<Player*> players;
	int upper_col; 
	int upper_row;
	int lower_col; 
	int lower_row; 

public: 
	Table();
	int addAt(shared_ptr<AnimalCard>, int row, int col); 
	Table& operator += (shared_ptr<ActionCard>);
	Table& operator -= (shared_ptr<ActionCard>); 
	shared_ptr<AnimalCard> pickAt(int row, int col);
	bool win(string& animal);
	//static Player* findPlayer(string);
	friend ostream &operator << (ostream &, const Table&);
	Player* findPlayer(string);
	void rotateAnimals();
};