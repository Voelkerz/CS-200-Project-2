//Accounts.h
#include<iostream>
using namespace std;

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

class Accounts
{
	public:
		Accounts();
		void setAccountNumber();
		void setAccountType(string);
		void setBalance(double);
		double getAccountNumber();
		string getAccountType();
		double getBalance();
		
	private:
		double accountNumber;
		string AccountType;
		double accountBalance;
};
#endif
