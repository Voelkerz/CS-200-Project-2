//ATM_Util.cpp
#include "ATM_Util.h"

bool ATM_Util::util_main(User* userList[], int userPos, Customer* custList, int custPos, int currentUser) {
	int option;
	
	do {	
		option = ATM_Util::menu(userList, currentUser);
		switch (option) {
			case 1:
				ATM_Util::viewAccountInfo(userList, custList, custPos, currentUser);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				ATM_Util::changePassword(userList, userPos, currentUser);
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

int ATM_Util::menu(User* userList[], int currentUser) {
	int option;
	
	system("CLS");
	cout <<"\t\tLogged In: "<<userList[currentUser]->getName()<<"\n\n"
		 <<"\t\t\tATM Menu"<<"\n"
		 <<"\t\t=========================="<<"\n"
		 <<"\t\t1. View Account Info"<<"\n"
		 <<"\t\t2. Deposit Funds"<<"\n"
		 <<"\t\t3. Withdraw Funds"<<"\n"
		 <<"\t\t4. View Transaction History (inactive)"<<"\n"
		 <<"\t\t5. Change Password"<<"\n"
		 <<"\t\t6. LOGOUT"<<"\n"
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}

int ATM_Util::transfer() {
	
}

int ATM_Util::viewBalance() {
	
}

int ATM_Util::viewAccountInfo(User* userList[], Customer* custList, int custPos, int currentUser) {
	
	int id;
	
	for (int i=0; i<custPos; i++) {
		if (userList[currentUser]->getID() == custList[i].getID()) {
			id = i;
		}
	}
	
	cout <<"\tName: "<<custList[id].getName()<<"\n"
		 <<"\tID: "<<custList[id].getID()<<endl;
		 
	for (int i=0; i<2; i++) {
		if (custList[id].acc[i].getAccountType() != "Null") {
			cout <<"\t\t====================="<<"\n"
				 <<"\t\tAccount "<<i+1<<":"<<"\n"
				 <<"\t\tAccount Number: "<<custList[id].acc[i].getAccountNumber()<<"\n"
				 <<"\t\tAccount Type: "<<custList[id].acc[i].getAccountType()<<"\n"
				 <<"\t\tAccount Balance: "<<custList[id].acc[i].getBalance()<<endl;
		}
	}
}

string ATM_Util::customerTransHistory() {
	
}

void ATM_Util::changePassword(User* userList[], int userPos, int currentUser) {
	
    string pass;

    Admin_Util::fromLoginFile(userList, userPos);
    cout <<"Enter new password: ";
    cin >>pass;
    userList[currentUser]->loginInfo.setPassword(pass);
    Admin_Util::toLoginFile(userList, userPos);

}
