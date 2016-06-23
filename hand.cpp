#include "hand.h"


//adds a pointer to the animal card to the Hand
Hand& Hand::operator+=(shared_ptr<AnimalCard> new_ptr) {
	hand.push_front(new_ptr);
	return *this; 
}
//removes the card equivalent to the argument from Hand
Hand& Hand::operator-=(shared_ptr<AnimalCard> to_remove) {
	for (list<shared_ptr<AnimalCard>>::iterator it = hand.begin(); it != hand.end(); it++) {
		if (*it == to_remove) {
			hand.remove(to_remove);
			return *this;
		}
	}
	//throw exception if the card doesn't exist
	if (to_remove == NULL) {
		throw new MissingCard();
	}
	return *this;
}
//returns the animalCard at a given index
//improve? Maybe? No? 
std::shared_ptr<AnimalCard> Hand::operator[](int index) {
	int i = 0;
	for (list<shared_ptr<AnimalCard>>::iterator itr = hand.begin(); itr != hand.end(); itr++) {
		if (i == index) {
			return *itr;
		}
		i++;
	}

	
}
//return number of Cards in Hand
int Hand::noCards() {
	return hand.size();
}

Hand::Hand() {}

ostream& operator << (ostream &out, const Hand& h) {

	for (int i = 0; i < h.hand.size(); i++) {
		out << i << "  ";
	}
	out << "  " << endl;
	for (auto it = h.hand.begin(); it != h.hand.end(); it++) {
		(*it)->printRow(out, EVEN);
		out << " ";
	}
	out << endl;
	for (auto it = h.hand.begin(); it != h.hand.end(); it++) {
		(*it)->printRow(out, ODD);
		out << " ";
	}
	return out;
}