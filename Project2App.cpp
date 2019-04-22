#include <iostream>
#include <vector>
using namespace std;
#include "User.h"
#include "Login_Util.h"

int menu();

int main(int argc, char** argv) {
	
	int option;
	vector<User*> userList;		//vector to hold all users
	vector<Admin> adminList;
	vector<Banker> bnkrList;
	vector<Customer> custList;
	
	// Expanding capacity to accomodate up to n elements before reallocation
	// Reallocation moves the memory location of objects and breaks functions
	userList.reserve(30);
	adminList.reserve(30);
	bnkrList.reserve(30);
	custList.reserve(30);
	
	// Initialize users from "user.txt" on startup
	Login_Util::initializeUsers(userList, adminList, bnkrList, custList);
	
	// Run main menu
	do {
		option = menu();
		switch (option) {
			case 1:
				// Start program using login system
				Login_Util::util_main(userList, adminList, bnkrList, custList);
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
	cout <<"\t\tCS-200 Project 2 Banking Application"<<endl
		 <<"\t\t===================================="<<endl
		 <<"\t\t1. Login"<<endl
		 <<"\t\t2. Exit Application"<<endl
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}
