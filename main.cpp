#include <iostream>
#include "animalcard.h"
#include "Table.h"
#include "deck.h"
#include "AnimalCardFactory.h"
#include "hand.h"

using namespace std;

void animalCardPrinter(AnimalCard* card) {
	card->printRow(cout, EVEN);
	cout << endl;
	card->printRow(cout, ODD);
	cout << endl;

}

void animalCardTest() {

	cout << "Testing nosplit card" << endl;
	AnimalCard* card = new Splits(NOSPLIT);
	animalCardPrinter(card);

	cout << "Testing splittwo card" << endl;
	AnimalCard* card2 = new Splits(SPLITTWO);
	animalCardPrinter(card2);
	
	cout << "Testing splitthree card" << endl;
	AnimalCard* card3 = new Splits(SPLITTHREE);
	animalCardPrinter(card3);

	cout << "Testing splitfour card" << endl;
	AnimalCard* card4 = new Splits(SPLITFOUR);
	animalCardPrinter(card4);

	cout << "Testing splittwo down orientation" << endl;
	card2->setOrientation(DOWN);
	animalCardPrinter(card2);

	cout << "Testing splitthree down orientation" << endl;
	card3->setOrientation(DOWN);
	animalCardPrinter(card3);

	cout << "Testing the printRow, getRow and setRow methods" << endl;
	card2->setRow(EVEN);
	card2->printRow(cout, DEFAULT);
	cout << endl;
	card2->setRow(ODD);
	card2->printRow(cout, DEFAULT);
	cout << endl << endl;
	card2->setRow(ODD);
	card2->printRow(cout, DEFAULT);
	cout << endl;
	card2->setRow(EVEN);
	card2->printRow(cout, DEFAULT);



	delete card;
	delete card2;
	delete card3;
	delete card4;
}


int main(int narg, char *args[]) {
	Deck<shared_ptr<AnimalCard> > deck;
	Table tab;
	int noPlayers = 0;
	Player* players = 0;

	/*
	if (narg > 1) {
		// open file and check for errors
		ifstream ifs; // associated with file 
		ifs >> deck;
		ifs >> tab;
		ifs >> noPlayers;
		players = new Player*[noPlayers];
		for (int pl = 0; pl<noPlayers; ++pl) {
			players[pl] = new Player();
			ifs >> players[pl]; // will load hand of player
		}
	}
	else {
		AnimalCardFactory* factory = AnimalCardFactory::get();
		deck = factory->getDeck();
		cout << "Number of Players?" << endl;
		cin >> noPlayers;
		players = new Player*[noPlayers];
		Hand = deck.getHand();
		for (int pl = 0; pl<noPlayers; ++pl) {
			cout << "Name of player " << pl << "?" << endl;
			std::string name;
			cin >> name;
			players[pl] = new Player(name);
			for (int i = 0; i<3; ++i) {
				players[pl].hd += deck.draw();
			}
		}
	}

	bool won{ false };

	while (!won) {
		for (int pl = 0; pl < noPlayers; ++pl) {
			cout << tab;
			players[pl] += deck.draw();
			cout << players[pl];
			bool next = true;
			do {
				int cardNo;
				cout << "Which card to play? (0 to "
					<< players[pl].hd.noCards() << ")? ";
				cin >> cardNo;
				std::shared_ptr<AnimalCard> ac = players[pl].hd[cardNo];
				players[pl].hd -= ac;
				// try downcasting to action card
				std::shared_ptr<ActionCard> action =
					dynamic_pointer_cast<ActionCard>(ac);
				if (action != nullptr) {
					// on success
					cout << "Top (1) or bottom (0) of start stack? " << endl;
					int tmp;
					cin >> tmp;
					if (tmp > 0)
						tab += action;
					else {
						tab -= action;
						// Perform action
						QueryResult q = action->query();
						action->perform(tab, players, q);
					}
				}
				else {
					int row, col;
					cout << "Where should the card go? (row column)" << endl;
					cin >> row >> col;
					int extraCard = tab.addAt(ac, row, col);
					if (extraCard == 0) {
						// illegal card
						next = false;
					}
					else {
						for (int c = 1; c < extraCard; ++c) {
							players[pl] += deck.draw();
						}
					}
				}
				if (next) {
					for (int pl = 0; pl < noPlayers; ++pl) {
						tab.win(players[pl].getSecretAnimal());
					}
				}
			}
		}

	}
	

/*	animalCardTest();
	char c;
	cin >> c;*/
}