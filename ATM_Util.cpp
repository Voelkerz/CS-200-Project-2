//ATM_Util.cpp
#include "ATM_Util.h"

bool ATM_Util::util_main(vector<User*> &userList, vector<Customer> &custList, int currentUser) {
	int option, currentCust;
	double amount;
	
	for (int i=0; i<custList.size(); i++) {
		if (userList[currentUser]->getID() == custList[i].getID()) {
			currentCust = i;
		}
	}
	
	do {	
		option = ATM_Util::menu(userList, currentUser);
		switch (option) {
			case 1:
				ATM_Util::createAccount(custList, currentCust);
				break;
			case 2:
				ATM_Util::viewAccountInfo(custList, currentCust);
				break;
			case 3:
				ATM_Util::depositFunds(custList, currentCust);
				break;
			case 4:
				ATM_Util::withdrawFunds(custList, currentCust);
				break;
			case 5:
				ATM_Util::customerTransHistory(custList, currentCust);
				break;
			case 6:
				ATM_Util::changePassword(userList, currentUser);
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

int ATM_Util::menu(vector<User*> userList, int currentUser) {
	int option;
	
	system("CLS");
	cout <<"Logged In: "<<userList[currentUser]->getName()<<"\n\n"
		 <<"\t\t\tATM Menu"<<"\n"
		 <<"\t\t=========================="<<"\n"
		 <<"\t\t1. Create New Account"<<"\n"
		 <<"\t\t2. View Account Info"<<"\n"
		 <<"\t\t3. Deposit Funds"<<"\n"
		 <<"\t\t4. Withdraw Funds"<<"\n"
		 <<"\t\t5. View Transaction History"<<"\n"
		 <<"\t\t6. Change Password"<<"\n"
		 <<"\t\t7. LOGOUT"<<"\n"
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}

void ATM_Util::transferFunds() {
	
}

void ATM_Util::createAccount(vector<Customer> &custList, int currentCust) {
	
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
						Transactions::deposit(custList, id, num, amount);
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
						Transactions::deposit(custList, id, num, amount);
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

void ATM_Util::viewAccountInfo(vector<Customer> custList, int currentCust) {
	
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

void ATM_Util::customerTransHistory(vector<Customer> custList, int currentCust) {
	
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
			
			if (custList[currentCust].getID() == custID) {
				cout <<"Transaction #"<<n<<": Customer "<<custList[currentCust].getID()<<" // ";
				for (int j=0; j<2; j++) {
					if (custList[currentCust].acc[j].getAccountNumber() == accNum) {
						cout <<custList[currentCust].acc[j].getAccountType()<<" // "<<" Account#: "<<accNum;
					}
				}
				cout <<" // "<<amount<<endl;
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

void ATM_Util::changePassword(vector<User*> &userList, int currentUser) {
	/*
    string pass;

    Admin_Util::fromLoginFile(userList);
    cout <<"Enter new password: ";
    cin >>pass;
    userList[currentUser]->loginInfo.setPassword(pass);
    Admin_Util::toLoginFile(userList, userPos);
*/
}

void ATM_Util::depositFunds(vector<Customer> &custList, int currentCust) {
	
	int option, acc1, acc2;
	double amount;
	string accNum;
	
	do {	
		system("CLS");
		cout <<"\t\tDeposit Funds to Account:"<<"\n"
			 <<"\t\t========================="<<endl;
			 
			for (int i=0; i<2; i++) {
				if (custList[currentCust].acc[i].getAccountType() == "Checking") {
					cout <<"\t\t1. Checking Account# "<<custList[currentCust].acc[i].getAccountNumber()<<endl;
					accNum = custList[currentCust].acc[i].getAccountNumber();
					acc1 = i;
					break;
				}
				else if (custList[currentCust].acc[i].getAccountType() == "Null") {
					cout <<"\t\t1. <<No Checking Account>>"<<endl;
					acc1 = i;
					break;
				}
			}
			
			for (int i=0; i<2; i++) {
				if (custList[currentCust].acc[i].getAccountType() == "Savings") {
					cout <<"\t\t2. Savings Account# "<<custList[currentCust].acc[i].getAccountNumber()<<endl;
					accNum = custList[currentCust].acc[i].getAccountNumber();
					acc2 = i;
					break;
				}
				else if (custList[currentCust].acc[i].getAccountType() == "Null") {
					cout <<"\t\t2. <<No Savings Account>>"<<endl;
					acc2 = i;
					break;
				}
			}
			
		cout <<"\t\t3. CANCEL"<<"\n"
			 <<"\tChoose an option"<<endl;
		cin >>option;
	
		switch (option) {
			case 1: 
				if (custList[currentCust].acc[acc1].getAccountType() != "Null") {
					cout <<"Current Balance: $"<<custList[currentCust].acc[acc1].getBalance()<<"\n"
					 	 <<"Enter amount to deposit: ";
					cin >>amount;
					Transactions::deposit(custList, custList[currentCust].getID(), accNum, amount);
					cout <<"**Transaction Successful**"<<"\n"
						 <<"New Balance: $"<<custList[currentCust].acc[acc1].getBalance()<<endl;
					return;
				}
				else {
					cout <<"**Error: Account Does Not Exist**"<<endl;
					break;
				}
			case 2:
				if (custList[currentCust].acc[acc2].getAccountType() != "Null") {
					cout <<"Current Balance: $"<<custList[currentCust].acc[acc2].getBalance()<<"\n"
					 	 <<"Enter amount to deposit: ";
					cin >>amount;
					Transactions::deposit(custList, custList[currentCust].getID(), accNum, amount);
					cout <<"**Transaction Successful**"<<"\n"
						 <<"New Balance: $"<<custList[currentCust].acc[acc2].getBalance()<<endl;
					return;
				}
				else {
					cout <<"**Error: Account Does Not Exist**"<<endl;
					break;
				}
			case 3:
				cout <<"**Deposit Cancelled**"<<endl;
				return;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 3);
}

void ATM_Util::withdrawFunds(vector<Customer> &custList, int currentCust) {
	
	int option, acc1, acc2;
	double amount;
	string accNum;
	
	do {	
		system("CLS");
		cout <<"\t\tWithdraw Funds from Account:"<<"\n"
			 <<"\t\t============================"<<endl;
			 
			for (int i=0; i<2; i++) {
				if (custList[currentCust].acc[i].getAccountType() == "Checking") {
					cout <<"\t\t1. Checking Account# "<<custList[currentCust].acc[i].getAccountNumber()<<endl;
					accNum = custList[currentCust].acc[i].getAccountNumber();
					acc1 = i;
					break;
				}
				else if (custList[currentCust].acc[i].getAccountType() == "Null") {
					cout <<"\t\t1. <<No Checking Account>>"<<endl;
					acc1 = i;
					break;
				}
			}
			
			for (int i=0; i<2; i++) {
				if (custList[currentCust].acc[i].getAccountType() == "Savings") {
					cout <<"\t\t2. Savings Account# "<<custList[currentCust].acc[i].getAccountNumber()<<endl;
					accNum = custList[currentCust].acc[i].getAccountNumber();
					acc2 = i;
					break;
				}
				else if (custList[currentCust].acc[i].getAccountType() == "Null") {
					cout <<"\t\t2. <<No Savings Account>>"<<endl;
					acc2 = i;
					break;
				}
			}
			
		cout <<"\t\t3. CANCEL"<<"\n"
			 <<"\tChoose an option"<<endl;
		cin >>option;
	
		switch (option) {
			case 1: 
				if (custList[currentCust].acc[acc1].getAccountType() != "Null") {
					cout <<"Current Balance: $"<<custList[currentCust].acc[acc1].getBalance()<<"\n"
					 	 <<"Enter amount to withdraw: ";
					cin >>amount;
					Transactions::withdraw(custList, custList[currentCust].getID(), accNum, amount);
					cout <<"**Transaction Successful**"<<"\n"
						 <<"New Balance: $"<<custList[currentCust].acc[acc1].getBalance()<<endl;
					return;
				}
				else {
					cout <<"**Error: Account Does Not Exist**"<<endl;
					break;
				}
			case 2:
				if (custList[currentCust].acc[acc2].getAccountType() != "Null") {
					cout <<"Current Balance: $"<<custList[currentCust].acc[acc2].getBalance()<<"\n"
					 	 <<"Enter amount to withdraw: ";
					cin >>amount;
					Transactions::withdraw(custList, custList[currentCust].getID(), accNum, amount);
					cout <<"**Transaction Successful**"<<"\n"
						 <<"New Balance: $"<<custList[currentCust].acc[acc2].getBalance()<<endl;
					return;
				}
				else {
					cout <<"**Error: Account Does Not Exist**"<<endl;
					break;
				}
			case 3:
				cout <<"**Withdraw Cancelled**"<<endl;
				return;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 3);
}

string ATM_Util::encrypt(string encpt) {
/*	char key = 'a';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}

*/	return encpt;
}

string ATM_Util::decrypt(string decpt) {
/*	char key = 'a';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
*/	return decpt;
}
