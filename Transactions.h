//Transactions.h
#include<iostream>
using namespace std;
#include "Customer.h"

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

class Transactions
{
	public:
		static void deposit(Customer*, int, int, string , double);
		static void withdraw(Customer*, int, int, string , double);
		static void toTransactionFile();
		static void fromTransactionFile();
		
	private:
		double transactionID;
};

#endif
