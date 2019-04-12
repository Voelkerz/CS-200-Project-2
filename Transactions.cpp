//Transactions.cpp
#include "Transactions.h"

//default constructor
Transactions::Transactions()
{
	deposit(0.0);
	withdraw(0.0);
}

//mutators
void Transactions::deposit(User* userList, int userPos, int max, string customerID, double a)
{
	double balance;
	amount = a
	for (int i = 0; i < max; i++ )
	{
		if (customerID == userList[i]->getID)
			{
				userList[i]->acc.getBalance() = balance;
				balance = balance + amount;
				userList[i]->acc.setBalance(balance);
			};
	};
}

void Transactions::withdraw(User* userList, int userPos, int max, string customerID, double a)
{
	double balance;
	amount = a
	for (int i = 0; i < max; i++ )
	{
		if (customerID == userList[i]->getID)
			{
				userList[i]->acc.getBalance() = balance;
				if (withdraw > balance)
				{
					cout << "ERROR: NOT ENOUGH FUNDS";
				};
				else
				{
					balance = balance - withdraw;
					userList[i]->acc.setBalance(balance);
				};
			};
	};
}



//accessors
void Transactions::toTransactionFile()
{
	
}

void Transactions::fromTransactionFile()
{
	
}
