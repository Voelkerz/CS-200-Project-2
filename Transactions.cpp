//Transactions.cpp
#include "Transactions.h"

//mutators
void Transactions::deposit(vector<Customer> &custList, string customerID, string accNum, double amount)
{
	double balance;

	for (int i = 0; i < custList.size(); i++ ) {
		if (customerID == custList[i].getID()) {
			for (int j=0; j<2; j++) {
				if (accNum == custList[i].acc[j].getAccountNumber()) {
					balance = custList[i].acc[j].getBalance();
					balance += amount;
					custList[i].acc[j].setBalance(balance);
				}
			}
		}
	}
	
	Transactions::toTransactionFile(custList, customerID, accNum, amount);
}

void Transactions::withdraw(vector<Customer> &custList, string customerID, string accNum, double withdraw)
{
	double balance;
	
	for (int i = 0; i < custList.size(); i++ ) {
		if (customerID == custList[i].getID()) {
			for (int j=0; j<2; j++) {
				if (accNum == custList[i].acc[j].getAccountNumber()) {
					balance = custList[i].acc[j].getBalance();
					if (withdraw > balance) {
						cout << "**Error: Not Enough Funds**";
					}
					else {
						balance = balance - withdraw;
						custList[i].acc[j].setBalance(balance);
					}
				}
			}
		}
	}
	
	Transactions::toTransactionFile(custList, customerID, accNum, -withdraw);
}



//accessors
void Transactions::toTransactionFile(vector<Customer> &custList, string id, string accNum, double amount) {
	
	ostringstream convert; //for string conversion
	string converted; //for string conversion
	ofstream transFile;
	transFile.open("transactions.txt", ios_base::app);
	
	for (int i=0; i<custList.size(); i++) {
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

string Transactions::encrypt(string encpt) {
	char key = 'a';
	string output = encpt;
	
	for (int i=0; i<encpt.size(); i++)
	{
		output[i] = encpt[i] ^ key;
	}
	
	return output;
}

string Transactions::decrypt(string decpt) {
	char key = 'a';
	string output = decpt;
	
	for (int i=0; i<decpt.size(); i++)
	{
		output[i] = decpt[i] ^ key;
	}
	
	
	return output;
}
