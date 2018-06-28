#pragma once
#include<string>
#include<vector>
#include<ctime>
#include<iostream>

using namespace std;

struct TransactionData {
	double amount;
	string senderkey;
	string receiverkey;
	time_t time;

	TransactionData() {};

	TransactionData(double amt, string sender, string receiver, time_t n_time) {

		amount = amt;
		senderkey = sender;
		receiverkey = receiver;
		time = n_time;
	}
};