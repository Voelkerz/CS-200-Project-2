
//Transactions.h
#include<iostream>
using namespace std;

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

class Transactions
{
	public:
		Transactions();
		static void deposit(User*, int, int, string , double);
		static void withdraw((User*, int, int, string , double);)
		void toTransactionFile();
		void fromTransactionFile();
		Accounts acc;
		
	private:
		double transactionID;
		double amount;
};

#endif
