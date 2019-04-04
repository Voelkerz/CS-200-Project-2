//Transactions.h
#include<iostream>
using namespace std;

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

class Transactions
{
	public:
		Transactions();
		double deposit(double);
		double withdraw(double);
		void toTransactionFile();
		void fromTransactionFile();
		
	private:
		double transactionID;
		double amount;
};

#endif
