//Banker_Util.cpp
#include "Banker_Util.h"

bool Banker_Util::util_main(int currentUser, vector<User*> &userList, vector<Customer> &custList) {
	int option, currentCust=-1;
	double amount;
	string password, id, id2, accNum, accType;
	
	do {
		option = Banker_Util::menu(userList, custList, currentUser, currentCust);
		switch (option)
		{
			case 1:
				Banker_Util::changeCust(custList, currentCust);
		    	break;
			case 2:
				if (currentCust != -1)
					ATM_Util::depositFunds(custList, currentCust);
				else
					cout <<"**Error: Need To Specify Customer**"<<endl;
				break;
			case 3:
				if (currentCust != -1)
					ATM_Util::withdrawFunds(custList, currentCust);
				else
					cout <<"**Error: Need To Specify Customer**"<<endl;
				break;
			case 4:
				if (currentCust != -1)
					ATM_Util::createAccount(custList, currentCust);
				else
					cout <<"**Error: Need To Specify Customer**"<<endl;
				break;
			case 5:
				Admin_Util::audit(custList);
				break;
			case 6:
				cout <<"**Logging Off**"<<endl;
					return false;
			default:
				cout <<"**Invalid Option**"<<endl;				
		}
		system("PAUSE");
		
	} while (option != 6);
}

int Banker_Util::menu(vector<User*> userList, vector<Customer> custList, int currentUser, int currentCust) {
	
	int option;
	
	system("CLS");
	cout <<"Logged In: "<<userList[currentUser]->getName()<<"\n\n";
	
	cout <<"\t\tBanker Utility Menu\n";
	if (currentCust != -1) {
		cout <<"\t\tAffected Customer: "<<custList[currentCust].getName()<<" ID#:"<<custList[currentCust].getID()<<"\n";
	} 
	else{
		cout <<"\t\tAffected Customer: Null"<<"\n";
	}
	cout <<"\t\t=========================="<<"\n"
		 <<"\t\t1. Change Affected Customer\n"
		 <<"\t\t2. Deposit Funds to Customer\n"
		 <<"\t\t3. Withdraw Funds from Customer\n"
		 <<"\t\t4. Add Account to Customer\n"
		 <<"\t\t5. Audit Mode\n"
		 <<"\t\t6. LOGOUT"<<"\n"
		 <<"\tChoose an option"<<endl;
	cin >> option;
	
	return option;
}

void Banker_Util::changeCust(vector<Customer> custList, int &currentCust) {
	
	string id;
	
	cout <<"Please Enter Customer ID#: ";
	cin >>id;
	
	for (int i=0; i<custList.size(); i++) {
		if (id == custList[i].getID()) {
			currentCust = i;
		}
	}
}
