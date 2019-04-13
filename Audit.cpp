//Audit.cpp
#include "Audit.h"

//----------------------------------------------------------------------------------------------------------------------//
//													AUDIT FUNCTIONS														//
//----------------------------------------------------------------------------------------------------------------------//

void Audit::printCustomerAccount(Customer* custList, int custPos, string id) {
	
	for (int i=0; i<custPos; i++) {
		if (custList[i].getID() == id) {
			cout <<"\tName: "<<custList[i].getName()<<"\n"
				 <<"\tID: "<<custList[i].getID()<<endl;
			for (int j=0; j<2; j++) {
				if (custList[i].acc[j].getAccountType() != "Null") {
					cout <<"\t====================="<<"\n"
						 <<"\tAccount "<<j+1<<":"<<"\n"
						 <<"\tAccount Number: "<<custList[i].acc[j].getAccountNumber()<<"\n"
						 <<"\tAccount Type: "<<custList[i].acc[j].getAccountType()<<"\n"
						 <<"\tAccount Balance: $"<<custList[i].acc[j].getBalance()<<endl;
				}
			}
			cout <<"\t======================="<<endl;
			break;
		}
		cout <<"**Error: Customer ID Not Found**"<<endl;
	}
}

void Audit::printCustomerList(Customer* custList, int custPos) {
	
	for (int i=0; i<custPos; i++) {
		cout <<"ID: "<<custList[i].getID()<<"\tName: "<<custList[i].getName()<<endl;
	}
}

void Audit::fullTransactionHistory(Customer* custList, int custPos) {
	
	string data, custID, accNum, amount;
	int n=1;
	
	ifstream transFile("transactions.txt");
	
	if (transFile.is_open()) {
		while (getline(transFile, data)) {
			getline(transFile, data, '\t');
			custID = decrypt(data);
			getline(transFile, data, '\t');
			accNum = decrypt(data);
			getline(transFile, data, '\t');
			amount = decrypt(data);
			
			for (int i=0; i<custPos; i++) {
				if (custList[i].getID() == custID) {
					cout <<"Transaction #"<<n<<": Customer "<<custList[i].getID()<<" // ";
					for (int j=0; j<2; j++) {
						if (custList[i].acc[j].getAccountNumber() == accNum) {
							cout <<custList[i].acc[j].getAccountType()<<" // "<<" Account#: "<<accNum;
						}
					}
					cout <<" // "<<amount<<endl;
				}
				n++;	
			}
		}
		transFile.close();
	}
	//Give error if file is not open
	else {
		cout <<"**Error: Cannot Open Login File**";
	}
}

string Audit::encrypt(string encpt) {
/*	char key = 'a';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}

*/	return encpt;
}

string Audit::decrypt(string decpt) {
/*	char key = 'a';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
*/	return decpt;
}
