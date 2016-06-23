#pragma once
#include <iostream>
#include <vector>
#include <memory>

template <class T> 
class Deck : public vector<T> {
private:
	//vector<shared_ptr<T>> deck;
public:
	Deck(): vector<T>() {}
	shared_ptr<T> draw() {

		shared_ptr<T> temp = std::vector::front();
		std::vector::erase(deck.front());
		return temp;
	}

	auto begin() {
		return vector::begin();
	}
	auto end() {
		return vector::end();
	}
	auto insert(vector::const_iterator<T> it, int pos, T t) {
		return vector::insert(it, pos, T t);
	}
};
