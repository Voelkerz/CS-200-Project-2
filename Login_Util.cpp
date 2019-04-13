// Login_Util.cpp
#include "Login_Util.h"

//----------------------------------------------------------------------------------------------------------------------//
//												MAIN() FOR LOGIN SYSTEM													//
//----------------------------------------------------------------------------------------------------------------------//

void Login_Util::util_main(User* userList[], int userMax, int &userPos, Admin* adminList,  int admMax, int &adminPos, Banker* bnkrList, int bnkrMax, int &bnkrPos, Customer* custList, int custMax, int &custPos) {
	
	bool loggedIn = false;
	int option, currentUser;
	
	// Initialize user array from "user.txt"
	Login_Util::initializeUsers(userList, userPos, adminList, adminPos, bnkrList, bnkrPos, custList, custPos);
	
	// Run login menu
	loggedIn = Login_Util::login(userList, userPos, currentUser);
	
	if (loggedIn) {
		if (userList[currentUser]->getAccessRights() == "Admin") {
			loggedIn = Admin_Util::util_main(currentUser, userList, userMax, userPos, adminList, admMax, adminPos, bnkrList, bnkrMax, bnkrPos, custList, custMax, custPos);
			Admin_Util::toUserFile(userList, userPos, custList, custPos, adminList, adminPos, bnkrList, bnkrPos);
		}
		else if (userList[currentUser]->getAccessRights() == "Banker") {
			loggedIn = Banker_Util::menu(currentUser, userList, userMax, userPos, custList, custPos);
			Admin_Util::toUserFile(userList, userPos, custList, custPos, adminList, adminPos, bnkrList, bnkrPos);
		}
		else if (userList[currentUser]->getAccessRights() == "Customer") {
			loggedIn = ATM_Util::util_main(userList, userPos, custList, custPos, currentUser);
			Admin_Util::toUserFile(userList, userPos, custList, custPos, adminList, adminPos, bnkrList, bnkrPos);
		}
		else {
			cout <<"\n**Error: Access Rights Not Set**"<<endl;
			loggedIn = false;
		}
	}
	else {
		cout <<"\n**Error: Incorrect Username or Password**"<<endl;
	}	
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

// Loads all persistent user file data from "users.txt" and stores it into appropriate arrays on program startup
void Login_Util::initializeUsers(User* userList[], int &userPos, Admin* adminList, int &adminPos, Banker* bnkrList, int &bnkrPos, Customer* custList, int &custPos) {
	
	string data, access, fname, lname, id, dob, occupation, address, hiredate, rank, emptype, acc1Num, acc1Type, acc1Bal, acc2Num, acc2Type, acc2Bal;
	double convBal1, convBal2; //for post conversion of account balances

	userPos=0;
	adminPos=0;
	bnkrPos=0;
	custPos=0;
	
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
			id = decrypt(data);
			getline(userFile, data, '\t');
			dob = decrypt(data);
			
			//if current user in file is admin:
			if (access == "Admin") {
				getline(userFile, data, '\t');
				hiredate = decrypt(data);
				getline(userFile, data, '\t');
				rank = decrypt(data);
				getline(userFile, data, '\t');
				emptype = decrypt(data);
				
				Admin adm(access, fname, lname, id, dob, hiredate, rank, emptype);
				
				adminList[adminPos] = adm;
				userList[userPos] = &adminList[adminPos];
				
				adminPos++;
			}
			
			//if banker:
			else if (access == "Banker") {
				getline(userFile, data, '\t');
				hiredate = decrypt(data);
				getline(userFile, data, '\t');
				rank = decrypt(data);
				getline(userFile, data, '\t');
				emptype = decrypt(data);
				
				Banker bnkr(access, fname, lname, id, dob, hiredate, rank, emptype);
				
				bnkrList[bnkrPos] = bnkr;
				userList[userPos] = &bnkrList[bnkrPos];
				
				bnkrPos++;
			}
			
			//if customer:
			else if (access == "Customer") {
				getline(userFile, data, '\t');
				occupation = decrypt(data);
				getline(userFile, data, '\t');
				address = decrypt(data);
				getline(userFile, data, '\t');
				acc1Num = decrypt(data);
				getline(userFile, data, '\t');
				acc1Type = decrypt(data);
				getline(userFile, data, '\t');
				acc1Bal = decrypt(data);
				getline(userFile, data, '\t');
				acc2Num = decrypt(data);
				getline(userFile, data, '\t');
				acc2Type = decrypt(data);
				getline(userFile, data, '\t');
				acc2Bal = decrypt(data);
				
				//Converting string to double
				istringstream(acc1Bal) >> convBal1;
				istringstream(acc2Bal) >> convBal2;
				
				Customer cust(access, fname, lname, id, dob, occupation, address, acc1Num, acc1Type, convBal1, acc2Num, acc2Type, convBal2);
				
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
/*	char key = 'a';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}
	
*/	return encpt;
}

string Login_Util::decrypt(string decpt) {
/*	char key = 'a';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
*/	return decpt;
}
