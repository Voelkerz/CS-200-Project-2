//Audit.cpp
#include "Audit.h"

//----------------------------------------------------------------------------------------------------------------------//
//													AUDIT FUNCTIONS														//
//----------------------------------------------------------------------------------------------------------------------//

void Audit::printCustomerAccount(vector<Customer> custList, string id) {
	
	for (int i=0; i<custList.size(); i++) {
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
		else
			cout <<"**Error: Customer ID Not Found**"<<endl;
	}
}

void Audit::printCustomerList(vector<Customer> custList) {
	
	for (int i=0; i<custList.size(); i++) {
		cout <<"ID: "<<custList[i].getID()<<"\tName: "<<custList[i].getName()<<endl;
	}
}

void Audit::fullTransactionHistory(vector<Customer> custList) {
	
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
			
			for (int i=0; i<custList.size(); i++) {
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
char key = 'a';
	string output = encpt;
	
	for (int i=0; i<encpt.size(); i++)
	{
		output[i] = encpt[i] ^ key;
	}
	
	return output;

}

string Audit::decrypt(string decpt) {
char key = 'a';
	string output = decpt;
	
	for (int i=0; i<decpt.size(); i++)
	{
		output[i] = decpt[i] ^ key;
	}
	
	
	return output;
}
