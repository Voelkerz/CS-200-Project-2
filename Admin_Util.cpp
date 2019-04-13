// Admin_Util.cpp
#include "Admin_Util.h"

//----------------------------------------------------------------------------------------------------------------------//
//												MAIN() FOR ADMIN UTILITY												//
//----------------------------------------------------------------------------------------------------------------------//

bool Admin_Util::util_main(int currentUser, User* userList[], int userMax, int &userPos, Admin* adminList,  int admMax, int &adminPos, Banker* bnkrList, int bnkrMax, int &bnkrPos, Customer* custList, int custMax, int &custPos) {
	int option;
	
	do {	
		option = Admin_Util::menu(userList, currentUser);
		switch (option) {
			case 1: 
				Admin_Util::createAdmin(userList, userMax, userPos, adminList, admMax, adminPos);
				break;
			case 2:
				Admin_Util::createBanker(userList, userMax, userPos, bnkrList, bnkrMax, bnkrPos);
				break;
			case 3:
				Admin_Util::createCustomer(userList, userMax, userPos, custList, custMax, custPos);
				break;
			case 4:
				Admin_Util::printAllUsers(userList, userPos);
				break;
			case 5:
				Admin_Util::viewUser(userList, userPos);
				break;
			case 6:
				Admin_Util::audit(custList, custPos);
				break;
			case 7:
				cout <<"**Logging Off**"<<endl;
				Admin_Util::fromLoginFile(userList, userPos);
				Admin_Util::toLoginFile(userList, userPos);
				Admin_Util::toUserFile(userList, userPos, custList, custPos, adminList, adminPos, bnkrList, bnkrPos);
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
		 <<"\t\t2. Create Banker Account"<<"\n"
		 <<"\t\t3. Create Customer Account"<<"\n"
		 <<"\t\t4. View All Users"<<"\n"
		 <<"\t\t5. View User"<<"\n"
		 <<"\t\t6. Enter Audit Mode"<<"\n"
		 <<"\t\t7. LOGOUT"<<"\n"
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}

//----------------------------------------------------------------------------------------------------------------------//
//													FUNCTIONS															//
//----------------------------------------------------------------------------------------------------------------------//

void Admin_Util::createAdmin(User* userList[], int userMax, int &userPos, Admin* adminList, int admMax, int &adminPos) {		// Creates Admin Accounts
	int num;
	string username, password, fname, lname, id, dob, hiredate, rank, emptype;
	
	if (adminPos == admMax)
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
			
			adminPos++;
			userPos++;
		}
	}
}

void Admin_Util::createBanker(User* userList[], int userMax, int &userPos, Banker* bnkrList, int bnkrMax, int &bnkrPos) {
	int num;
	string username, password, fname, lname, id, dob, hiredate, rank, emptype;
	
	if (bnkrPos == bnkrMax)
		cout <<"**Employee Not Added: List Full**"<<endl;
	else
	{
		do
		{
			cout <<"How many bankers do you want to add?: ";
			cin >>num;
		} while (num < 1 || num > (bnkrMax - bnkrPos));
			
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
			
			Banker bnkr(fname, lname, id, dob, hiredate, rank, emptype);
			bnkr.loginInfo.setUsername(username);
			bnkr.loginInfo.setPassword(password);
				
			bnkrList[bnkrPos] = bnkr;
			userList[userPos] = &bnkrList[bnkrPos];
			
			bnkrPos++;
			userPos++;
		}
	}
}

void Admin_Util::createCustomer(User* userList[], int userMax, int &userPos, Customer* custList, int custMax, int &custPos) {
	int num;
	string username, password, fname, lname, id, dob, occupation, address;
	
	if (custPos == custMax)
		cout <<"**Customer Not Added: List Full**"<<endl;
	else
	{
		do
		{
			cout <<"How many customers do you want to add?: ";
			cin >>num;
		} while (num < 1 || num > (custMax - custPos));
			
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
			cout <<"Enter Occupation: ";
			cin >>occupation;
			cout <<"Enter Address: ";
			cin >>address;
			
			Customer cust(fname, lname, id, dob, occupation, address);
			cust.loginInfo.setUsername(username);
			cust.loginInfo.setPassword(password);
				
			custList[custPos] = cust;
			userList[userPos] = &custList[custPos];
			
			custPos++;
			userPos++;
		}
	}
}

void Admin_Util::printAllUsers(User* userList[], int userPos) {
	for (int i=0; i<userPos; i++)
	{
		userList[i]->print();
	}
}

void Admin_Util::viewUser(User* userList[], int userPos) {
	string id;
	
	cout <<"Enter the ID# of the user to view: "<<endl;
	cin >>id;
	
	for (int i=0; i<userPos; i++)
		if (userList[i]->getID() == id) {
			userList[i]->print();
		}
}

void Admin_Util::audit(Customer* custList, int custPos) {
	int option;
	string id;
	
	do {	
		system("CLS");
		cout <<"\t\tAudit Utility Menu"<<"\n"
			 <<"\t\t=================="<<"\n"
			 <<"\t\t1. View Customer Account Info"<<"\n"
			 <<"\t\t2. List Customers"<<"\n"
			 <<"\t\t3. View Transaction Log (inactive)"<<"\n"
			 <<"\t\t4. Return to Admin Menu"<<"\n"
			 <<"\tChoose an option"<<endl;
		cin >>option;
	
		switch (option) {
			case 1: 
				cout <<"Enter Customer ID#: ";
				cin >>id;
				cout <<endl;
				Audit::printCustomerAccount(custList, custPos, id);
				break;
			case 2:
				Audit::printCustomerList(custList, custPos);
				break;
			case 3:
				break;
			case 4:
				cout <<"**Returning to Admin Menu**"<<endl;
				break;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 4);
}

// Write to all loaded user passwords and usernames to "login.txt"
// Caution** Use only after fromLoginFile(), or you will wipe the "login.txt" file
void Admin_Util::toLoginFile(User* list[], int userPos) {
	ofstream loginFile;
	loginFile.open("login.txt");
	
	for (int i=0; i<userPos; i++) {
		loginFile <<endl<<encrypt(list[i]->getID())<<"\t"<<encrypt(list[i]->loginInfo.getUsername())<<"\t"<<encrypt(list[i]->loginInfo.getPassword())<<"\t";
	}
	loginFile.close();
}

// Will load users with their password prior to saving to "login.txt"
void Admin_Util::fromLoginFile(User* list[], int userPos) {
	
	string data, id, u, p;
	
	ifstream loginFile("login.txt");
	
	if (loginFile.is_open()) {
		while (getline(loginFile, data)) {
			getline(loginFile, data, '\t');
			id = decrypt(data);
			getline(loginFile, data, '\t');
			u = decrypt(data);
			getline(loginFile, data, '\t');
			p = decrypt(data);
			
			for (int i=0; i<userPos; i++) {
				if (list[i]->getID() == id) {
					list[i]->loginInfo.setUsername(u);
					list[i]->loginInfo.setPassword(p);
				}	
			}
		}
		loginFile.close();
	}
	//Give error if file is not open
	else {
		cout <<"**Error: Cannot Open Login File**";
	}
}

// Write all users to "users.txt" for persistent data
void Admin_Util::toUserFile(User* userList[], int userPos, Customer* custList, int custPos, Admin* adminList, int adminPos, Banker* bnkrList, int bnkrPos) {
	ofstream userFile;
	userFile.open("users.txt");
	
	for (int i=0; i<userPos; i++) {
		// Cycle through entire user list and write to file
		userFile <<endl<<userList[i]->getAccessRights()<<"\t"<<userList[i]->getFirstName()<<"\t"<<userList[i]->getLastName()<<"\t"<<encrypt(userList[i]->getID())<<"\t"<<encrypt(userList[i]->getDOB())<<"\t";
		
		// If current user is an Admin, then write these specific attributes to file
		if (userList[i]->getAccessRights() == "Admin") {
			for (int j=0; j<adminPos; j++) {
				if (userList[i]->getID() == adminList[j].getID()) {	// Match user ID in both arrays to make sure it is the correct user
					userFile <<encrypt(adminList[j].getHireDate())<<"\t"<<encrypt(adminList[j].getRank())<<"\t"<<encrypt(adminList[j].getEmploymentType())<<"\t";
				}
			}
		}
		
		else if (userList[i]->getAccessRights() == "Banker") {
			for (int j=0; j<bnkrPos; j++) {
				if (userList[i]->getID() == bnkrList[j].getID()) {
					userFile <<encrypt(bnkrList[j].getHireDate())<<"\t"<<encrypt(bnkrList[j].getRank())<<"\t"<<encrypt(bnkrList[j].getEmploymentType())<<"\t";
				}
			}
		}
		
		else if (userList[i]->getAccessRights() == "Customer") {
			for (int j=0; j<custPos; j++) {
				if (userList[i]->getID() == custList[j].getID()) {
					userFile <<encrypt(custList[j].getOccupation())<<"\t"<<encrypt(custList[j].getAddress())<<"\t";
				}
			}
		}		 
	}
	userFile.close();
}

string Admin_Util::encrypt(string encpt) {
/*	char key = 'a';
	
	for (int i=0; i<encpt.size(); i++)
	{
		encpt[i] ^= key;
	}

*/	return encpt;
}

string Admin_Util::decrypt(string decpt) {
/*	char key = 'a';
	
	for (int i=0; i<decpt.size(); i++)
	{
		decpt[i] ^= key;
	}
	
*/	return decpt;
}
