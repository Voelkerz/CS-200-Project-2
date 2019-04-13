//Accounts.cpp
#include "Accounts.h"

//default constructor
Accounts::Accounts()
{
	setAccountNumber("Null");
	setAccountType("Null");
	setBalance(0.0);
}
 
//mutators
void Accounts::setAccountNumber(string acc)
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
string Accounts::getAccountNumber()
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
