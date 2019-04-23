// Login_Util.cpp
#include "Login_Util.h"

//----------------------------------------------------------------------------------------------------------------------//
//												MAIN() FOR LOGIN SYSTEM													//
//----------------------------------------------------------------------------------------------------------------------//

void Login_Util::util_main(vector<User*> &userList, vector<Admin> &adminList, vector<Banker> &bnkrList, vector<Customer> &custList) {
	
	bool loggedIn = false;
	int option, currentUser;
	
	// Run login menu
	loggedIn = Login_Util::login(userList, currentUser);
	
	if (loggedIn) {
		if (userList[currentUser]->getAccessRights() == "Admin") {
			loggedIn = Admin_Util::util_main(currentUser, userList, adminList, bnkrList, custList);
			Admin_Util::toUserFile(userList, adminList, bnkrList, custList);
		}
		else if (userList[currentUser]->getAccessRights() == "Banker") {
			loggedIn = Banker_Util::util_main(currentUser, userList, custList);
			Admin_Util::toUserFile(userList, adminList, bnkrList, custList);
		}
		else if (userList[currentUser]->getAccessRights() == "Customer") {
			loggedIn = ATM_Util::util_main(userList, custList, currentUser);
			Admin_Util::toUserFile(userList, adminList, bnkrList, custList);
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

bool Login_Util::login(vector<User*> list, int &user) {
	
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
				for (int i=0; i<list.size(); i++) {
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
void Login_Util::initializeUsers(vector<User*> &userList, vector<Admin> &adminList, vector<Banker> &bnkrList, vector<Customer> &custList) {
	
	string data, access, fname, lname, id, dob, occupation, address, hiredate, rank, emptype, acc1Num, acc1Type, acc1Bal, acc2Num, acc2Type, acc2Bal;
	double convBal1, convBal2; //for post conversion of account balances
	
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
				
				adminList.push_back(Admin(access, fname, lname, id, dob, hiredate, rank, emptype));
				userList.push_back(&adminList.back());
			}
			
			//if banker:
			else if (access == "Banker") {
				getline(userFile, data, '\t');
				hiredate = decrypt(data);
				getline(userFile, data, '\t');
				rank = decrypt(data);
				getline(userFile, data, '\t');
				emptype = decrypt(data);
				
				bnkrList.push_back(Banker(access, fname, lname, id, dob, hiredate, rank, emptype));
				userList.push_back(&bnkrList.back());
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
				
				custList.push_back(Customer(access, fname, lname, id, dob, occupation, address, acc1Num, acc1Type, convBal1, acc2Num, acc2Type, convBal2));
				userList.push_back(&custList.back());
			}
		}
		userFile.close();
	}
	else
		cout <<"**Error: Cannot Open User File**";
}

string Login_Util::encrypt(string encpt) {
	
	char key = 'a';
	string output = encpt;
	
	for (int i=0; i<encpt.size(); i++)
	{
		output[i] = encpt[i] ^ key;
	}
	
	return output;
}

string Login_Util::decrypt(string decpt) {
	
	char code = 'a';
	string output = decpt;
	
	for (int i=0; i<decpt.size(); i++)
	{
		output[i] = decpt[i] ^ code;
	}
	
	
	
/*	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	*/
	return output;
}
