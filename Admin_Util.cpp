// Admin_Util.cpp
#include "Admin_Util.h"

//----------------------------------------------------------------------------------------------------------------------//
//												MAIN() FOR ADMIN UTILITY												//
//----------------------------------------------------------------------------------------------------------------------//

bool Admin_Util::util_main(int currentUser, User* userList[], int userMax, int &userPos, Employee* empList[], int empMax, int &empPos, Admin* adminList,  int admMax, int &adminPos, Banker* bnkrList, int bnkrMax, int &bnkrPos, Customer* custList, int custMax, int &custPos) {
	int option;
	
	do {	
		option = Admin_Util::menu(userList, currentUser);
		switch (option) {
			case 1: 
				Admin_Util::createAdmin(userList, userMax, userPos, empList, empMax, empPos, adminList, admMax, adminPos);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				Admin_Util::printAllUsers(userList, userPos);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				cout <<"**Logging Off**"<<endl;
				Admin_Util::fromLoginFile(userList);
				Admin_Util::toLoginFile(userList, userPos);
				Admin_Util::toUserFile(userList, empList, custList, userPos, empPos, custPos);
				return false;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 7);
}

//----------------------------------------------------------------------------------------------------------------------//
//													MAIN MENU															//
//----------------------------------------------------------------------------------------------------------------------//

int Admin_Util::menu(User* userList[], int currentUser) {
	int option;
	
	system("CLS");
	cout <<"\t\tLogged In: "<<userList[currentUser]->getName()<<"\n\n"
		 <<"\t\tAdministrator Utility Menu"<<"\n"
		 <<"\t\t=========================="<<"\n"
		 <<"\t\t1. Create Administrator Account"<<"\n"
		 <<"\t\t2. Create Banker Account (Inactive)"<<"\n"
		 <<"\t\t3. Create Customer Account (Inactive)"<<"\n"
		 <<"\t\t4. View All Users"<<"\n"
		 <<"\t\t5. View User (Inactive)"<<"\n"
		 <<"\t\t6. Enter Audit Mode (Inactive)"<<"\n"
		 <<"\t\t7. LOGOUT"<<"\n"
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}

//----------------------------------------------------------------------------------------------------------------------//
//													FUNCTIONS															//
//----------------------------------------------------------------------------------------------------------------------//

void Admin_Util::createAdmin(User* userList[], int userMax, int &userPos, Employee* empList[], int empMax, int &empPos, Admin* adminList, int admMax, int &adminPos) {		// Creates Admin Accounts
	int num;
	string username, password, fname, lname, id, dob, hiredate, rank, emptype;
	
	if (adminPos == admMax || empPos == empMax)
		cout <<"**Employee Not Added: List Full**"<<endl;
	else
	{
		do
		{
			cout <<"How many administrators do you want to add?: ";
			cin >>num;
		} while (num < 1 || num > (admMax - adminPos));
			
		//fill in admin info
		for (int i=0; i<num; i++)
		{
			cout <<"\nEnter Username: ";
			cin >>username;
			cout <<"Enter Password: ";
			cin >>password;
			cout <<"Enter Name: ";
			cin >>fname>>lname;
			cout <<"Enter ID: ";
			cin >>id;
			cout <<"Enter Date of Birth (DD-Month-YYYY): ";
			cin >>dob;
			cout <<"Enter Hire Date (DD-Month-YYYY): ";
			cin >>hiredate;
			cout <<"Enter Rank: ";
			cin >>rank;
			cout <<"Enter Full/Part: ";
			cin >>emptype;
			
			Admin adm(fname, lname, id, dob, hiredate, rank, emptype);
			adm.loginInfo.setUsername(username);
			adm.loginInfo.setPassword(password);
				
			adminList[adminPos] = adm;
			userList[userPos] = &adminList[adminPos];
			empList[empPos] = &adminList[adminPos];
			
			adminPos++;
			userPos++;
			empPos++;
		}
	}
}

void Admin_Util::printAllUsers(User* userList[], int userPos) {	//Prints a list of all users in system (only admins for now)
	for (int i=0; i<userPos; i++)
	{
		//userList[i]->print();
		
		cout <<"\nName: "<<userList[i]->getName()<<"\n"
			 <<"ID: "<<userList[i]->getID()<<"\n"
			 <<"DOB: "<<userList[i]->getDOB()<<"\n"
			 <<"Access Rights: "<<userList[i]->getAccessRights()<<"\n"<<endl;
	}
}

// Write to all loaded user passwords and usernames to "login.txt"
// Caution** Use only after fromLoginFile(), or you will wipe the "login.txt" file
void Admin_Util::toLoginFile(User* list[], int userPos) {
	ofstream loginFile;
	loginFile.open("login.txt");
	
	for (int i=0; i<userPos; i++) {
		loginFile <<endl<<encrypt(list[i]->getID())<<"\t"<<encrypt(list[i]->loginInfo.getUsername())<<"\t"<<encrypt(list[i]->loginInfo.getPassword())<<"\t";
	}
}

// Write all users to "users.txt" for persistent data
void Admin_Util::toUserFile(User* userList[], Employee* empList[], Customer* custList, int userPos, int empPos, int custPos) {
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
void Admin_Util::fromLoginFile(User* list[]) {
	
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

string Admin_Util::encrypt(string encpt) {
	char key = '~';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}
	
	return encpt;
}

string Admin_Util::decrypt(string decpt) {
	char key = '~';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
	return decpt;
}
