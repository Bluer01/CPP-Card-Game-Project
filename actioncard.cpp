#include "actioncard.h"
#include <string>
#include "Table.h"
#include "player.h"


/* Makes a certain position on the field a bear action card
 *
 * The animal action card methods work as follows:
 *   AnimalAction() - 'Constructor' that sets a position on the board as that action card (capital of animal first letter)
 *   query() - Asks player for some input related to the specific action card
 *   perform() - Performs the action stated for the action card
 *
*/

BearAction::BearAction() {
	for (int i = 0; i < 2; i++) { // Row
		for (int j = 0; j < 2; j++) { // Column
			actionCard[i][j] = 'B';
		}
	}
}

QueryResult BearAction::query(Table& _Table) {
	QueryResult player;
	cout << "Please provide the player that you wish to switch hands with: " << endl;
	getline(cin, player.q_playerName);
	_Table.findPlayer(player.q_playerName);
	return player;
}

// Performs a hand swap with a chosen player
void BearAction::perform(Table& _Table, Player* _Player, QueryResult _QueryResult) {
	_Player->swapHands(*_Table.findPlayer(_QueryResult.q_playerName));
}


WolfAction::WolfAction() {
	for (int i = 0; i < 2; i++) { // Row
		for (int j = 0; j < 2; j++) { // Column
			actionCard[i][j] = 'W';
		}
	}
}

QueryResult WolfAction::query() {
	QueryResult card;
	cout << "Please provide the coordinates of the card that you wish to place into your hand from the table: " << endl;
	cout << "Row: " << endl;
	cin >> card.q_cardRow;
	cout << "Column: " << endl;
	cin >> card.q_card2Col;
	return card;
}

void WolfAction::perform(Table& _Table, Player* _Player, QueryResult _QueryResult) {
	// Allows a player to pick up a card from the table and place it in the player's hand
	_Player->giveCard(_Table.pickAt(_QueryResult.q_cardRow, _QueryResult.q_cardCol));
}

HareAction::HareAction() {
	for (int i = 0; i < 2; i++) { // Row
		for (int j = 0; j < 2; j++) { // Column
			actionCard[i][j] = 'H';
		}
	}
}

QueryResult HareAction::query() {
	QueryResult card;
	cout << "Please provide the coordinates of the card that you wish to move: " << endl;
	cout << "Row: " << endl;
	cin >> card.q_cardRow;
	cout << "Column: " << endl;
	cin >> card.q_cardCol;
	cout << "Please provide the coordinates of the location that you wish to move to: " << endl;
	cout << "Row: " << endl;
	cin >> card.q_card2Row;
	cout << "Column: " << endl;
	cin >> card.q_card2Col;
	return card;
}

// Moves a card from one position on the board to another
void HareAction::perform(Table& _Table, Player* _Player, QueryResult _QueryResult) {
	_Table.addAt(_Table.pickAt(_QueryResult.q_cardRow, _QueryResult.q_cardCol), _QueryResult.q_card2Row, _QueryResult.q_card2Col);
}

MooseAction::MooseAction() {
	for (int i = 0; i < 2; i++) { // Row
		for (int j = 0; j < 2; j++) { // Column
			actionCard[i][j] = 'M';
		}
	}
}

QueryResult MooseAction::query() {
	QueryResult result;
}

void MooseAction::perform(Table& _Table, Player* _Player, QueryResult _QueryResult) {
	// Triggers a rotation of secret animals from player 1 to player 2, etc.
	_Table.rotateAnimals();
}

DeerAction::DeerAction() {
	for (int i = 0; i < 2; i++) { // Row
		for (int j = 0; j < 2; j++) { // Column
			actionCard[i][j] = 'D';
		}
	}
}

QueryResult DeerAction::query() {
	QueryResult player;
	cout << "Please choose a player to swap secret animal with: " << endl;
	cin >> player.q_playerName;
	return player;
}

// Swaps the secret animal with another player
void DeerAction::perform(Table& _Table, Player* _Player, QueryResult _QueryResult) {
	Player* targetPlayer = _Table.findPlayer(_QueryResult.q_playerName);
	_Player->setSecretAnimal(_Player->swapSecretAnimal(targetPlayer->getName()));
}