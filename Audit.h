//Audit.h
#include<iostream>
using namespace std;
#include "Customer.h"

#ifndef AUDIT_H
#define AUDIT_H
class Audit {
	public:
		static void printCustomerAccount(Customer*, int, string);
		static void printCustomerList(Customer*, int);
		static void fullTransactionHistory();
};
#endif
