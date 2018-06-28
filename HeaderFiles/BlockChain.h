#pragma once
#include"Block.h"

class BlockChain
{
private:
	Block createGenesisBlock();

public:
	vector<Block> chain;
	Block *getLatestBlock(); // for validation

	BlockChain() {

		Block genesis = createGenesisBlock();
		chain.push_back(genesis);
	}

	void addBlock(TransactionData data);
	bool chainValid();
	void printChain();


};