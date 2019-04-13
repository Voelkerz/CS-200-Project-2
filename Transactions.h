//Transactions.h
#include <iostream>
#include <fstream>
#include <sstream> //for string conversion
using namespace std;
#include "Customer.h"

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

class Transactions
{
	public:
		static void deposit(Customer*, int, string, string, double);
		static void withdraw(Customer*, int, string, string, double);
		static void toTransactionFile(Customer*, int, string, string, double);
		static void fromTransactionFile();
		static string encrypt(string);
		static string decrypt(string);
		
	private:
		double transactionID;
};

#endif
