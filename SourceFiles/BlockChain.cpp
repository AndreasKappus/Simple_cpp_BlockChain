#include"BlockChain.h"

Block BlockChain::createGenesisBlock() { 

	time_t current_timestamp;
	TransactionData data; 
	data.amount = 0;
	data.receiverkey = "None";
	data.senderkey = "None";
	data.time = time(&current_timestamp);

	hash<int> hash1;
	Block genesis(0, data, hash1(0)); // genesis block will have no amount as it's the first one.

	return genesis;
}

Block *BlockChain::getLatestBlock() {

	return &chain.back(); 
}

void BlockChain::addBlock(TransactionData data) { // transaction data is needed to add a new blocks

	int index = (int)chain.size(); // index the blockchain based of size
	unsigned previous_hash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0; // the ? is ternary which takes 3 arguments(quite nifty)
	Block newBlock(index, data, previous_hash); 
	chain.push_back(newBlock); // push the new block onto the chain which includes the index, transactional data and the previous hash
}

bool BlockChain::chainValid() {

	vector<Block>::iterator it;

	for (it = chain.begin(); it != chain.end(); ++it) { // access data in the chain through an iterator (again nifty)

		Block currentBlock = *it;
		if (!currentBlock.hashValid()) {
			return false; // simple security measure, if hash has been tampered with, then it no longer becomes valid.
		}

		if (it != chain.begin()) {
			Block prevBlock = *(it - 1);
			if (currentBlock.getPreviousHash() != prevBlock.getHash()) { // check if previous hash is equal, another simple security measure
				return false;
			}
		}
	}

	return true;
}

void BlockChain::printChain() {

	vector<Block>::iterator it;

	for (it = chain.begin(); it != chain.end(); ++it) { // iterate through the values of the chain 

		Block current = *it;
		cout << "\n\nBlock=======";
		cout << "\nIndex: " << current.getIndex();
		cout << "\nAmount: " << current.data.amount;
		cout << "\nSender Key: " << current.data.senderkey;
		cout << "\n Receiver Key: " << current.data.receiverkey;
		cout << "\n timestamp: " << current.data.time;
		cout << "\nHash: " << current.getHash();
		cout << "\nPrevious Hash: " << current.getPreviousHash();
		cout << "\nblock valid: " << current.hashValid();
	}
}