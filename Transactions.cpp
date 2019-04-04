//Transactions.cpp
#include "Transactions.h"

//default constructor
Transactions::Transactions()
{
	deposit(0.0);
	withdraw(0.0);
}

//mutators
double Transactions::deposit(double a)
{
	amount = a;
}

double Transactions::withdraw(double am)
{
	amount = am;
}

//accessors
void Transactions::toTransactionFile()
{
	
}

void Transactions::fromTransactionFile()
{
	
}
