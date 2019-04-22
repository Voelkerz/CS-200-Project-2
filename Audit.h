//Audit.h
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Customer.h"

#ifndef AUDIT_H
#define AUDIT_H
class Audit {
	public:
		static void printCustomerAccount(vector<Customer>, string);
		static void printCustomerList(vector<Customer>);
		static void fullTransactionHistory(vector<Customer>);
		static string encrypt(string);
		static string decrypt(string);
};
#endif
