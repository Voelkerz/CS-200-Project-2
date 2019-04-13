//Accounts.h
#include<iostream>
using namespace std;

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

class Accounts
{
	public:
		Accounts();
		void setAccountNumber(string);
		void setAccountType(string);
		void setBalance(double);
		string getAccountNumber();
		string getAccountType();
		double getBalance();
		
	private:
		string accountNumber;
		string accountType;
		double accountBalance;
};
#endif
