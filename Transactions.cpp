//Transactions.cpp
#include "Transactions.h"

//mutators
void Transactions::deposit(Customer* custList, int custPos, int max, string customerID, double amount)
{
	double balance;

	for (int i = 0; i < custPos; i++ )
	{
		if (customerID == custList[i].getID())
			{
				balance = custList[i].acc[0].getBalance();
				balance = balance + amount;
				custList[i].acc[0].setBalance(balance);
			}
	}
}

void Transactions::withdraw(Customer* custList, int custPos, int max, string customerID, double withdraw)
{
	double balance;
	
	for (int i = 0; i < custPos; i++ )
	{
		if (customerID == custList[i].getID())
			{
				balance = custList[i].acc[0].getBalance();
				if (withdraw > balance)
				{
					cout << "ERROR: NOT ENOUGH FUNDS";
				}
				else
				{
					balance = balance - withdraw;
					custList[i].acc[0].setBalance(balance);
				}
			}
	}
}



//accessors
void Transactions::toTransactionFile()
{
	
}

void Transactions::fromTransactionFile()
{
	
}
