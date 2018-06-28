#include"Block.h"

unsigned Block::generateHash() { 
	hash<string> hash1;
	hash<unsigned> hash2;
	hash<unsigned> hash_final;

	string to_hash = to_string(data.amount) + data.receiverkey + data.senderkey + to_string(data.time); // creates a hash

	return hash_final(hash1(to_hash) + hash2(previous_hash));
}

bool Block::hashValid() {

	return generateHash() == block_hash; // if data is manipulated, a new hash will generate which is != to the block_hash
}