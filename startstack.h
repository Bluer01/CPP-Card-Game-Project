#pragma once
#include <iostream>
#include <deque>
#include "animalcard.h"
#include "actioncard.h"

typedef std::shared_ptr<ActionCard> ActionPointer;

class StartStack : public AnimalCard {
protected:
	std::deque<ActionPointer> startStack;
	std::shared_ptr<StartCard> startCard;
public:
	StartStack& operator+=(ActionPointer);

	StartStack& operator-=(ActionPointer);

	std::shared_ptr<StartCard> getStartCard();

	StartStack();
};