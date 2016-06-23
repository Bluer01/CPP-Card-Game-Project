#pragma once
#include <iostream>
#include "animalcard.h"
#include "player.h"

class Table;

struct QueryResult {
	string q_playerName = "";
	int q_cardRow = 0;
	int q_cardCol = 0;

	int q_card2Row = 0;
	int q_card2Col = 0;
};

class ActionCard : public StartCard {
protected:
	char actionCard[2][2] = { 'Z' };
public:
	virtual QueryResult query() = 0;

	virtual void perform(Table&, Player*, QueryResult) = 0;
};

class BearAction : public ActionCard {
public:
	virtual QueryResult query(Table&);
	virtual void perform(Table&, Player*, QueryResult);
	BearAction();

};

class DeerAction : public ActionCard {

public:
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
	DeerAction();

};

class HareAction : public ActionCard {

public:
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
	HareAction();
};

class MooseAction : public ActionCard {

public:
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
	MooseAction();
};

class WolfAction : public ActionCard {

public:
	virtual QueryResult query();
	virtual void perform(Table&, Player*, QueryResult);
	WolfAction();
};