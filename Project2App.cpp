#include <iostream>
using namespace std;
#include "User.h"
#include "Login_Util.h"

int menu();

int main(int argc, char** argv) {
	
	int option;
	
	// Create all array to hold all users in system
	int maxUser=30, maxAdm=5, maxBnkr=5, maxCust=20;
	int userPos=0, adminPos=0, bnkrPos=0, custPos=0;
	User* userList[maxUser];
	Admin adminList[maxAdm];
	Banker bnkrList[maxBnkr];
	Customer custList[maxCust];
	
	// Run main menu
	do {
		option = menu();
		switch (option) {
			case 1:
				// Start program using login system
				Login_Util::util_main(userList, maxUser, userPos, adminList, maxAdm, adminPos, bnkrList, maxBnkr, bnkrPos, custList, maxCust, custPos);
				break;
			case 2:
				cout <<"**Exiting Application**"<<endl;
				break;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		system("PAUSE");
	} while (option != 2);
	
	return 0;
}

int menu() {
	
	int option;
	
	system("CLS");
	cout <<"\t\tCS-200 Project 1 Banking Application"<<endl
		 <<"\t\t===================================="<<endl
		 <<"\t\t1. Login"<<endl
		 <<"\t\t2. Exit Application"<<endl
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}
