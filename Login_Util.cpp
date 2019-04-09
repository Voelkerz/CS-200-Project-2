// Login_Util.cpp
#include "Login_Util.h"

// MAIN for Login Screen
void Login_Util::util_main(User* userList[], Admin* adminList,  int max, int &userPos, int &adminPos) {
	
	bool loggedIn = false;
	//Login_Util::fromLoginFile(userList, max);
	
	do {
		loggedIn = Login_Util::menu(userList, max, userPos);
		
		if (loggedIn) {
			loggedIn = Admin_Util::util_main(userList, adminList, max, userPos, adminPos);
		}
		else {
			cout <<"\n**Error: Incorrect Username or Password**"<<endl;
		}
		
		system("PAUSE");
	} while(!loggedIn);
}

// Login Menu Function
bool Login_Util::menu(User* list[], int max, int &pos) {
	
	string username, password, u, p;
	bool logIn;
	
	system("CLS");
	cout <<"Username: "<<endl;
	cin >>username;
	cout <<"Password: "<<endl;
	cin >>password;
	
	for (int i=0; i<pos; i++) {
		u = list[i]->loginInfo.getUsername();
		p = list[i]->loginInfo.getPassword();
		if (username == u && password == p) {
			return logIn = true;
		}
		else
			return logIn = false;
	}
	
	
}

/////////////////
// ACCESSORS

void Login_Util::fromLoginFile(User* list[], int max, int &pos) {
	
	list[0]->loginInfo.setUsername("voelkerz");
	list[0]->loginInfo.setPassword("pass123");
	list[1]->loginInfo.setUsername("test");
	list[1]->loginInfo.setPassword("pass");
	list[2]->loginInfo.setUsername("root");
	list[2]->loginInfo.setPassword("toor");
}
