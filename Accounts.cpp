//Accounts.cpp
#include "Accounts.h"

//default constructor
Accounts::Accounts()
{
	setAccountNumber(0.0);
	setAccountType(" ");
	setBalance(0.0);
}
 
//mutators
void Accounts::setAccountNumber(double acc)
{
	accountNumber = acc;
}

void Accounts::setAccountType(string type)
{
	accountType = type;
}

void Accounts::setBalance(double bal)
{
	accountBalance = bal;
}

//accessors
double Accounts::getAccountNumber()
{
	return accountNumber;
}

string Accounts::getAccountType()
{
	return accountType;
}

double Accounts::getBalance()
{
	return accountBalance;
}
