//Transactions.cpp
#include "Transactions.h"

//mutators
void Transactions::deposit(Customer* custList, int custPos, string customerID, string accNum, double amount)
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
	
	Transactions::toTransactionFile(custList, custPos, customerID, accNum, amount);
}

void Transactions::withdraw(Customer* custList, int custPos, string customerID, string accNum, double withdraw)
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
	
	Transactions::toTransactionFile(custList, custPos, customerID, accNum, -withdraw);
}



//accessors
void Transactions::toTransactionFile(Customer* custList, int custPos, string id, string accNum, double amount) {
	
	ostringstream convert; //for string conversion
	string converted; //for string conversion
	ofstream transFile;
	transFile.open("transactions.txt", ios_base::app);
	
	for (int i=0; i<custPos; i++) {
		if (custList[i].getID() == id) {
			transFile <<endl<<encrypt(id)<<"\t"<<encrypt(accNum)<<"\t";
			
			//Converting double to a string and encrypting into file
			convert << amount;
			converted = convert.str();
			transFile <<encrypt(converted)<<"\t";
		}
	}
	
	transFile.close();
}

void Transactions::fromTransactionFile() {
	
}

string Transactions::encrypt(string encpt) {
/*	char key = 'a';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}

*/	return encpt;
}

string Transactions::decrypt(string decpt) {
/*	char key = 'a';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
*/	return decpt;
}
