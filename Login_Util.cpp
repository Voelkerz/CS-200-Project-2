// Login_Util.cpp
#include "Login_Util.h"

//------------------------------//
// MAIN FOR LOGIN SYSTEM		//
//------------------------------//

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

//------------------------------//
// LOGIN MENU					//
//------------------------------//

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

//------------------------------//
// FUNCTIONS					//
//------------------------------//

void Login_Util::toLoginFile(User* list[], int max) {
	
	ofstream loginFile;
	loginFile.open("login.txt", ios_base::app);
	
	for (int i=0; i<max; i++) {
		loginFile <<endl<<encrypt(list[i]->loginInfo.getUsername())<<"\t"<<encrypt(list[i]->loginInfo.getPassword())<<"\t";
	}
}

void Login_Util::fromLoginFile(User* list[]) {
	
	string data, u, p;
	int i=0;
	
	ifstream loginFile("login.txt");
	
	//Give error if file is not open
	if (loginFile.is_open()) {
		while (getline(loginFile, data)) {
			getline(loginFile, data, '\t');
			u = decrypt(data);
			getline(loginFile, data, '\t');
			p = decrypt(data);
			list[i]->loginInfo.setUsername(u);
			list[i]->loginInfo.setPassword(p);
			i++;
		}
		loginFile.close();
	}
	else
		cout <<"**Error: Cannot Open Login File**";
}

string Login_Util::encrypt(string encpt)
{
	char key = '~';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}
	
	return encpt;
}

string Login_Util::decrypt(string decpt)
{
	char key = '~';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
	return decpt;
}
