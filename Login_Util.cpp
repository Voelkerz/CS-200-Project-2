// Login_Util.cpp
#include "Login_Util.h"

//----------------------------------------------------------------------------------------------------------------------//
//												MAIN() FOR LOGIN SYSTEM													//
//----------------------------------------------------------------------------------------------------------------------//

void Login_Util::util_main(User* userList[], int userMax, int &userPos, Employee* empList[], int empMax, int &empPos, Admin* adminList,  int admMax, int &adminPos, Banker* bnkrList, int bnkrMax, int &bnkrPos, Customer* custList, int custMax, int &custPos) {
	
	bool loggedIn = false;
	int option, currentUser;
	
	Login_Util::initializeUsers(userList, userPos, empList, empPos, adminList, adminPos, bnkrList, bnkrPos, custList, custPos);
				
	do {
		option = Login_Util::menu();
		switch (option) {
			case 1: 	 
				loggedIn = Login_Util::login(userList, userPos, currentUser);
				
				if (loggedIn) {
					if (userList[currentUser]->getAccessRights() == "Admin") {
						loggedIn = Admin_Util::util_main(userList, adminList, userMax, userPos, adminPos, currentUser);
					}
					else if (userList[currentUser]->getAccessRights() == "Banker") {
						//loggedIn = Banker_Util::util_main();
					}
					else if (userList[currentUser]->getAccessRights() == "Customer") {
						//loggedIn = ATM_Util::util_main();
					}
					else {
						cout <<"\n**Error: Access Rights Not Set**"<<endl;
						loggedIn = false;
					}
				}
				else {
					cout <<"\n**Error: Incorrect Username or Password**"<<endl;
				}
				break;
			case 2:
				cout <<"**Exiting Application**"<<endl;
				break;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 2);
}

//----------------------------------------------------------------------------------------------------------------------//
//													MAIN MENU															//
//----------------------------------------------------------------------------------------------------------------------//

int Login_Util::menu() {
	
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

//----------------------------------------------------------------------------------------------------------------------//
//													LOGIN MENU															//
//----------------------------------------------------------------------------------------------------------------------//

bool Login_Util::login(User* list[], int max, int &user) {
	
	string data, username, password, u, p, id;
	bool logIn = false;
	user = -1;
	
	system("CLS");
	cout <<"Username: "<<endl;
	cin >>username;
	cout <<"Password: "<<endl;
	cin >>password;
	
	ifstream loginFile("login.txt");
	
	//Search login file for username and password
	if (loginFile.is_open()) {
		while (getline(loginFile, data)) {
			getline(loginFile, data, '\t');
			id = decrypt(data);
			getline(loginFile, data, '\t');
			u = decrypt(data);
			getline(loginFile, data, '\t');
			p = decrypt(data);
			
			if (username == u && password == p) {
				for (int i=0; i<max; i++) {
					if (list[i]->getID() == id) {
						user = i;
					}
				}
				logIn = true;
			}
		}
		loginFile.close();
	}
	else {
		cout <<"**Error: Cannot Open Login File**";
	}
	
	return logIn;
}

//----------------------------------------------------------------------------------------------------------------------//
//												UTILITY FUNCTIONS														//
//----------------------------------------------------------------------------------------------------------------------//

// Write to all loaded user passwords and usernames to "login.txt"
// Caution** Use only after fromLoginFile(), or you will wipe the "login.txt" file
void Login_Util::toLoginFile(User* list[], int userPos) {
	ofstream loginFile;
	loginFile.open("login.txt");
	
	for (int i=0; i<userPos; i++) {
		loginFile <<endl<<encrypt(list[i]->getID())<<"\t"<<encrypt(list[i]->loginInfo.getUsername())<<"\t"<<encrypt(list[i]->loginInfo.getPassword())<<"\t";
	}
}

// Write all users to "users.txt" for persistent data
void Login_Util::toUserFile(User* userList[], Employee* empList[], Customer* custList, int userPos, int empPos, int custPos) {
	ofstream userFile;
	userFile.open("users.txt");
	
	for (int i=0; i<userPos; i++) {
		// Cycle through entire user list and write to file
		userFile <<endl<<userList[i]->getAccessRights()<<"\t"<<userList[i]->getFirstName()<<"\t"<<userList[i]->getLastName()<<"\t"<<userList[i]->getID()<<"\t"<<userList[i]->getDOB()<<"\t";
		
		// If current user is an Admin, then write these specific attributes to file
		if (userList[i]->getAccessRights() == "Admin") {
			for (int j=0; j<empPos; j++) {
				if (userList[i]->getID() == empList[j]->getID()) {	// Match user ID in both arrays to make sure it is the correct user
					userFile <<empList[j]->getHireDate()<<"\t"<<empList[j]->getRank()<<"\t"<<empList[j]->getEmploymentType()<<"\t";
				}
			}
		}
		
		else if (userList[i]->getAccessRights() == "Banker") {
			for (int j=0; j<empPos; j++) {
				if (userList[i]->getID() == empList[j]->getID()) {
					userFile <<empList[j]->getHireDate()<<"\t"<<empList[j]->getRank()<<"\t"<<empList[j]->getEmploymentType()<<"\t";
				}
			}
		}
		
		else if (userList[i]->getAccessRights() == "Customer") {
			for (int j=0; j<custPos; j++) {
				if (userList[i]->getID() == custList[j].getID()) {
					userFile <<custList[j].getOccupation()<<"\t"<<custList[j].getAddress()<<"\t";
				}
			}
		}		 
	}
}

// Will load users with their password prior to saving to "login.txt"
void Login_Util::fromLoginFile(User* list[]) {
	
	string data, id, u, p;
	int i=0;
	
	ifstream loginFile("login.txt");
	
	if (loginFile.is_open()) {
		while (getline(loginFile, data)) {
			getline(loginFile, data, '\t');
			id = decrypt(data);
			getline(loginFile, data, '\t');
			u = decrypt(data);
			getline(loginFile, data, '\t');
			p = decrypt(data);
			if (list[i]->getID() == id) {
				list[i]->loginInfo.setUsername(u);
				list[i]->loginInfo.setPassword(p);
			}
			i++;
		}
		loginFile.close();
	}
	//Give error if file is not open
	else {
		cout <<"**Error: Cannot Open Login File**";
	}
}

// Loads all persistent user file data from "users.txt" and stores it into appropriate arrays on program startup
void Login_Util::initializeUsers(User* userList[], int &userPos, Employee* empList[], int &empPos, Admin* adminList, int &adminPos, Banker* bnkrList, int &bnkrPos, Customer* custList, int &custPos) {
	
	string data, access, fname, lname, id, dob, occupation, address, hiredate, rank, emptype;
	
	ifstream userFile("users.txt");
	
	if (userFile.is_open()) {
		while (getline(userFile, data)) {
			getline(userFile, data, '\t');
			access = data;
			getline(userFile, data, '\t');
			fname = data;
			getline(userFile, data, '\t');
			lname = data;
			getline(userFile, data, '\t');
			id = data;
			getline(userFile, data, '\t');
			dob = data;
			
			//if current user in file is admin:
			if (access == "Admin") {
				getline(userFile, data, '\t');
				hiredate = data;
				getline(userFile, data, '\t');
				rank = data;
				getline(userFile, data, '\t');
				emptype = data;
				
				Admin adm(access, fname, lname, id, dob, hiredate, rank, emptype);
				
				adminList[adminPos] = adm;
				userList[userPos] = &adminList[adminPos];
				empList[empPos] = &adminList[adminPos];
				
				empPos++;
				adminPos++;
			}
			
			
			//if banker:
			else if (access == "Banker") {
				getline(userFile, data, '\t');
				hiredate = data;
				getline(userFile, data, '\t');
				rank = data;
				getline(userFile, data, '\t');
				emptype = data;
				
				Banker bnkr(access, fname, lname, id, dob, hiredate, rank, emptype);
				
				bnkrList[bnkrPos] = bnkr;
				userList[userPos] = &bnkrList[bnkrPos];
				empList[empPos] = &bnkrList[bnkrPos];
				
				empPos++;
				bnkrPos++;
			}
			
			//if customer:
			else if (access == "Customer") {
				getline(userFile, data, '\t');
				occupation = data;
				getline(userFile, data, '\t');
				address = data;
				
				Customer cust(access, fname, lname, id, dob, occupation, address);
				
				custList[custPos] = cust;
				userList[userPos] = &custList[custPos];
				
				custPos++;
			}
			
			userPos++;
		}
		userFile.close();
	}
	else
		cout <<"**Error: Cannot Open User File**";
}

string Login_Util::encrypt(string encpt) {
	char key = '~';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}
	
	return encpt;
}

string Login_Util::decrypt(string decpt) {
	char key = '~';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
	return decpt;
}
