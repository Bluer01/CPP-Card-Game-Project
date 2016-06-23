#include<iostream>
#include "startstack.h"
#include "animalcard.h"




StartStack& StartStack::operator+=(ActionPointer actPointer) {
	startStack.push_front(actPointer); // The front is the top of the deck; the startCard is moved back
	return *this;					   // and so won't be an issue as an implicit animal card
}

StartStack& StartStack::operator-=(ActionPointer actPointer) {
	startStack.push_back(actPointer);
	return *this;
}

std::shared_ptr<StartCard> StartStack::getStartCard() {
	return startCard;
}

StartStack::StartStack() {
	shared_ptr<StartCard> startcard{new StartCard()};
}
