#include"BlockChain.h"


int main(void) {
	
	// dummy transactions, to show it kind of works...

	BlockChain bitpennies; // name of cryptocurrency

	time_t block1_time;
	TransactionData trans_data1(1.5, "Jeff", "Jim", time(&block1_time)); 
	bitpennies.addBlock(trans_data1);

	time_t block2_time;
	TransactionData trans_data2(2.6, "CJ", "Big Smoke", time(&block2_time));
	bitpennies.addBlock(trans_data2);

	bitpennies.printChain();

	cin.get();
	return 0;
}