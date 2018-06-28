#pragma once
#include"TransactionData.h"


class Block
{
private:
	int index;
	unsigned block_hash;
	unsigned previous_hash;
	unsigned generateHash(); // generate new hash code

public:
	Block(int idx, TransactionData trans, unsigned prev_hash) { // construct a new block
		index = idx;
		data = trans;
		previous_hash = prev_hash;
		block_hash = generateHash();
	}

	unsigned getHash() {

		return block_hash;
	}
	unsigned getPreviousHash() {

		return previous_hash;
	}

	int getIndex() {

		return index;
	}

	TransactionData data;

	bool hashValid();

};
