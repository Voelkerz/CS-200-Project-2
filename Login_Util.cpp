// Login_Util.cpp
#include "Login_Util.h"

// MAIN for Login Screen
void Login_Util::util_main(User* userList[], int max) {
	
	//Login_Util::fromLoginFile(userList, max);
	
	do {
		Login_Util::menu(userList, max);
	} while(1);
}

// Login Menu Function
void Login_Util::menu(User* list[], int max) {
	
	string username, password, u, p;
	bool loggedIn = false;
	
	system("CLS");
	cout <<"Username: "<<endl;
	cin >>username;
	cout <<"Password: "<<endl;
	cin >>password;
	
	for (int i=0; i<max; i++) {
		u = list[i]->loginInfo.getUsername();
		p = list[i]->loginInfo.getPassword();
		if (username == u && password == p) {
			loggedIn = true;
		}
	}
	
	if (loggedIn) {
		Admin_Util::menu();
	}
	else {
		cout <<"\n**Error: Incorrect Username or Password**"<<endl;
	}
}

/////////////////
// ACCESSORS

void Login_Util::fromLoginFile(User* list[], int max) {
	
	list[0]->loginInfo.setUsername("voelkerz");
	list[0]->loginInfo.setPassword("pass123");
	list[1]->loginInfo.setUsername("test");
	list[1]->loginInfo.setPassword("pass");
	list[2]->loginInfo.setUsername("root");
	list[2]->loginInfo.setPassword("toor");
}
