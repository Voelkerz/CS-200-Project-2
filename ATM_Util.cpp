//ATM_Util.cpp
#include "ATM_Util.h"

bool ATM_Util::util_main(User* userList[], int userPos, Customer* custList, int custPos, int currentUser) {
	int option, currentCust;
	double amount;
	
	for (int i=0; i<custPos; i++) {
		if (userList[currentUser]->getID() == custList[i].getID()) {
			currentCust = i;
		}
	}
	
	do {	
		option = ATM_Util::menu(userList, currentUser);
		switch (option) {
			case 1:
				ATM_Util::createAccount(custList, custPos, currentCust);
				break;
			case 2:
				ATM_Util::viewAccountInfo(custList, currentCust);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				ATM_Util::changePassword(userList, userPos, currentUser);
				break;
			case 7:
				cout <<"**Logging Off**"<<endl;
				return false;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 7);
}

int ATM_Util::menu(User* userList[], int currentUser) {
	int option;
	
	system("CLS");
	cout <<"\t\tLogged In: "<<userList[currentUser]->getName()<<"\n\n"
		 <<"\t\t\tATM Menu"<<"\n"
		 <<"\t\t=========================="<<"\n"
		 <<"\t\t1. Create New Account"<<"\n"
		 <<"\t\t2. View Account Info"<<"\n"
		 <<"\t\t3. Deposit Funds"<<"\n"
		 <<"\t\t4. Withdraw Funds"<<"\n"
		 <<"\t\t5. View Transaction History (inactive)"<<"\n"
		 <<"\t\t6. Change Password"<<"\n"
		 <<"\t\t7. LOGOUT"<<"\n"
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}

void ATM_Util::transfer() {
	
}

void ATM_Util::createAccount(Customer* custList, int custPos, int currentCust) {
	
	int option;
	double amount;
	string num;
	string id = custList[currentCust].getID();
	
	
	do {	
		system("CLS");
		cout <<"\t\tNew Account Creation"<<"\n"
			 <<"\t\t===================="<<"\n"
			 <<"\t\t1. Create Checking Account (Limit 1)"<<"\n"
			 <<"\t\t2. Create Savings Account (Limit 1)"<<"\n"
			 <<"\t\t3. RETURN"<<"\n"
			 <<"\tChoose an option"<<endl;
		cin >>option;
	
		switch (option) {
			case 1: 
				for (int i=0; i<2; i++) {
					if (custList[currentCust].acc[i].getAccountType() == "Checking") {
						cout <<"**Error: A Checking Account Already Exists**"<<endl;
						break;
					}
					else if (custList[currentCust].acc[i].getAccountType() == "Null") {
						cout <<"Enter Account Number (5 digit #): "<<endl;
						cin >>num;
						cout <<"Enter Initial Balance to Deposit: "<<endl;
						cin >>amount;
						
						custList[currentCust].acc[i].setAccountType("Checking");
						custList[currentCust].acc[i].setAccountNumber(num);
						Transactions::deposit(custList, custPos, id, num, amount);
						break;
					}
				}
				break;
			case 2:
				for (int i=0; i<2; i++) {
					if (custList[currentCust].acc[i].getAccountType() == "Savings") {
						cout <<"**Error: A Savings Account Already Exists**"<<endl;
						break;
					}
					else if (custList[currentCust].acc[i].getAccountType() == "Null") {
						cout <<"Enter Account Number (5 digit #): "<<endl;
						cin >>num;
						cout <<"Enter Initial Balance to Deposit: "<<endl;
						cin >>amount;
						
						custList[currentCust].acc[i].setAccountType("Savings");
						custList[currentCust].acc[i].setAccountNumber(num);
						Transactions::deposit(custList, custPos, id, num, amount);
						break;
					}
				}
				break;
			case 3:
				cout <<"**Returning to Main Menu**"<<endl;
				break;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 3);
}

void ATM_Util::viewAccountInfo(Customer* custList, int currentCust) {
	
	custList[currentCust].print();
	cout <<endl;
		 
	for (int i=0; i<2; i++) {
		if (custList[currentCust].acc[i].getAccountType() != "Null") {
			cout <<"\t\t====================="<<"\n"
				 <<"\t\t[Account "<<i+1<<"]"<<"\n"
				 <<"\t\tAccount Number: "<<custList[currentCust].acc[i].getAccountNumber()<<"\n"
				 <<"\t\tAccount Type: "<<custList[currentCust].acc[i].getAccountType()<<"\n"
				 <<"\t\tAccount Balance: $"<<custList[currentCust].acc[i].getBalance()<<endl;
		}
	}
	cout <<"\t\t====================="<<endl;
}

void ATM_Util::customerTransHistory() {
	
}

void ATM_Util::changePassword(User* userList[], int userPos, int currentUser) {
	
    string pass;

    Admin_Util::fromLoginFile(userList, userPos);
    cout <<"Enter new password: ";
    cin >>pass;
    userList[currentUser]->loginInfo.setPassword(pass);
    Admin_Util::toLoginFile(userList, userPos);

}
