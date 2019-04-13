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
				cout <<"\t====================="<<"\n"
					 <<"\tAccount "<<j+1<<":"<<"\n"
					 <<"\tAccount Number: "<<custList[i].acc[j].getAccountNumber()<<"\n"
					 <<"\tAccount Type: "<<custList[i].acc[j].getAccountType()<<"\n"
					 <<"\tAccount Balance: $"<<custList[i].acc[j].getBalance()<<endl;
			}
			cout <<"======================="<<endl;
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

void Audit::fullTransactionHistory() {
	cout <<"Prints the Full Transaction History"<<endl;
}
