// Login_Util.cpp
#include "Login_Util.h"

// MAIN for Login Screen
void Login_Util::util_main(User* userList[], int userMax, int &userPos, 
						   Employee* empList[], int empMax, int &empPos, 
						   Admin* adminList,  int admMax, int &adminPos, 
						   Banker* bnkrList, int bnkrMax, int &bnkrPos, 
						   Customer* custList, int custMax, int &custPos) {
	
	bool loggedIn = false;
	int currentUser=-1;
	
	do {
		loggedIn = Login_Util::menu(userList, userPos, currentUser);
		
		if (loggedIn) {
			if (userList[currentUser]->getAccessRights() == "Admin") {
				loggedIn = Admin_Util::util_main(userList, adminList, userMax, userPos, adminPos);
			}
			else {
				cout <<"\n**Error: Access Rights Not Set**"<<endl;
				loggedIn = false;
			}
		}
		else {
			cout <<"\n**Error: Incorrect Username or Password**"<<endl;
		}
		
		system("PAUSE");
	} while(!loggedIn);
}

// Login Menu Function
bool Login_Util::menu(User* list[], int max, int &user) {
	
	string username, password, u, p;
	bool logIn;
	
	system("CLS");
	cout <<"Username: "<<endl;
	cin >>username;
	cout <<"Password: "<<endl;
	cin >>password;
	
	for (int i=0; i<max; i++) {
		
		u = list[i]->loginInfo.getUsername();
		p = list[i]->loginInfo.getPassword();
		
		if (username == u && password == p) {
			user = i;
			return logIn = true;
		}
	}
	
	user = -1;
	return logIn = false;
}

/////////////////
// ACCESSORS

void Login_Util::fromLoginFile(User* list[], int max, int &pos) {
	
}
