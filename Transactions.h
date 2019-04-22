//Transactions.h
#include <iostream>
#include <fstream>
#include <sstream> //for string conversion
#include <vector>
using namespace std;
#include "Customer.h"

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
class Transactions
{
	public:
		static void deposit(vector<Customer> &, string, string, double);
		static void withdraw(vector<Customer> &, string, string, double);
		static void toTransactionFile(vector<Customer> &, string, string, double);
		static string encrypt(string);
		static string decrypt(string);
};
#endif
