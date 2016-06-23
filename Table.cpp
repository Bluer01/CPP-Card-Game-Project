#include "Table.h"
#include "startstack.h"
#include <sstream>

Table::Table(){
	table[52][52] = shared_ptr<AnimalCard>(new StartCard);
	upper_col = 52; 
	upper_row = 52; 
	lower_col = 52; 
	lower_row = 52; 

}
bool Table::match(shared_ptr<AnimalCard> match, shared_ptr<AnimalCard> other, CompareType dir) {
	ostringstream strm1;
	other->setRow(EVEN);
	strm1 << other;
	string str = strm1.str();
	const char* chr1 = str.c_str();

	ostringstream strm2; 
	other->setRow(ODD);
	strm2 << other; 
	
	str = strm2.str();
	const char* chr2 = str.c_str();

	ostringstream strm3;
	match->setRow(EVEN);
	strm3 << match;
	str = strm3.str();
	const char* chr3 = str.c_str();

	ostringstream strm4;
	match->setRow(ODD);
	strm4 << match;
	str = strm4.str();
	const char* chr4 = str.c_str();

	switch (dir)
	{
	case UP:
		if (chr2[0] == chr3[0] || chr2[1] == chr3[1]) {

			return true;
		}
		break;

	case RIGHT:
		if (chr3[1] == chr1[0] || chr4[1] == chr2[0]) {

			return true;
		}
		break;
	case LEFT:
		if (chr1[1] == chr3[0] || chr2[1] == chr4[0]) {

			return true;
		}
		break;
	case DOWN:
		if (chr1[0] == chr4[0] || chr1[1] == chr4[1]) {
		
			return true; 
		}
		break;
	}

}
//adds an AnimalCard at a given row and column index, if it can. 
//Returns an integer 1-4 indicating animals that can be matched
//returns 0 and doesn't add the card if no match found
int Table::addAt(shared_ptr<AnimalCard> newCard, int row, int col) {
	int matchNum = 0;
	if (col > 0) { 
		if (match(newCard, table[row][col - 1], DOWN)) {
			matchNum++;
		}
	}
	if (col < 102) {
		if (match(newCard, table[row][col + 1], RIGHT)) {
			matchNum++;
		}
	}
	if (row > 0) {
		if (match(newCard, table[row - 1][col], UP)) {
			matchNum++;
		}
	}
	if (row < 102) { 
		if (match(newCard, table[row + 1][col], LEFT)) {
			matchNum++;
		}
	}
	//to keep a track of the highest visited row and column
	if (matchNum >= 1) {
		table[row][col] = newCard; 
		if (upper_row > row) {
			upper_row = row; 
		}
		if (upper_col > col) {
			upper_col = col; 
		}
		if (lower_row < row) {
			lower_row = row; 
		}
		if (lower_col < row) {
			lower_col = col; 
		}
	}
	return matchNum;
}
//places a copy of the action card on top of the startStack in Table
Table& Table::operator += (shared_ptr<ActionCard> copyActionCrd) {

	*start.get() += copyActionCrd; 
	return *this;
}
//places a copy of the action card at the bottom of the startStack in Table
Table& Table::operator -= (shared_ptr<ActionCard> copyActionCrd) {

	*start.get() -= copyActionCrd;

	return *this;
}
//removes an AnimalCard at a given row and column from the table. 
shared_ptr<AnimalCard> Table::pickAt(int row, int col) {

	shared_ptr<AnimalCard> temp = table[row][col]; 
	table[row][col] = NULL; 
	return temp; 
}
//checks if there are matches for the given card 
bool Table::check(string animal, shared_ptr<AnimalCard> given) {
	ostringstream strm;
	given.get()->setRow(EVEN);
	strm << given;
	given.get()->setRow(ODD);
	strm << given;
	string str = strm.str();

	int found = str.find(animal);
	if (found != string::npos)
		return true; 
	return false; 
}

//returns true if the animal card in the string won. 
//Animal wins when there are seven matching cards
bool Table::win(string& animal) {
	int winNum = 0;
	for (int i = 0; i < 103; i++) {
		for (int j = 0; j < 103; j++) {
			if (check(animal, table[i][j])) {
				winNum++;
				if (winNum == 7) {
					break;
				}
			}
		}
	}
	return (winNum >= 7 ? true : false);

}


//Added in for BearAction
Player* Table::findPlayer(string playerName) {
	
	Player *toFind;

	for (auto it = players.begin(); it != players.end(); it++) {
		if(playerName == (*it)->getName()) {
			toFind = *it;
			return toFind;
		}
	}
}

ostream& operator << (ostream &out, const Table& t) {
	for (int i = 0; i < t.lower_col - t.upper_col; i++) {
		out << i;
	}
	out << "  " << endl;
	int index = 1;
	for (int i = t.upper_row; i <= t.lower_row; i++) {
		out << index;
		for (int it = t.upper_col; it <= t.lower_col; it++) {
			t.table[i][it]->setRow(EVEN);
			out << t.table;
		}
		out << " " << endl;
		for (int it = t.upper_col; it <= t.lower_col; it++) {
			t.table[i][it]->setRow(ODD);
			out << t.table;
		}
		out << " " << endl;
		index++;
	}
	/*string temp = t.players.back()->getSecretAnimal();

	for (auto it = t.players.rbegin(); it != t.players.rend() - 1; it++) {
		(*it)->setSecretAnimal((*(it + 1))->getSecretAnimal());
	}

	t.players.front()->setSecretAnimal(temp);*/
	return out; 
}