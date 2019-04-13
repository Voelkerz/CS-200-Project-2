//Audit.h
#include <iostream>
#include <fstream>
using namespace std;
#include "Customer.h"

#ifndef AUDIT_H
#define AUDIT_H
class Audit {
	public:
		static void printCustomerAccount(Customer*, int, string);
		static void printCustomerList(Customer*, int);
		static void fullTransactionHistory(Customer*, int);
		static string encrypt(string);
		static string decrypt(string);
};
#endif
