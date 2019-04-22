// Admin_Util.cpp
#include "Admin_Util.h"

//----------------------------------------------------------------------------------------------------------------------//
//												MAIN() FOR ADMIN UTILITY												//
//----------------------------------------------------------------------------------------------------------------------//

bool Admin_Util::util_main(int currentUser, vector<User*> &userList, vector<Admin> &adminList, vector<Banker> &bnkrList, vector<Customer> &custList) {
	int option;
	
	do {		
		option = Admin_Util::menu(userList, currentUser);
		switch (option) {
			case 1: 
				Admin_Util::createAdmin(userList, adminList);
				break;
			case 2:
				Admin_Util::createBanker(userList, bnkrList);
				break;
			case 3:
				Admin_Util::createCustomer(userList, custList);
				break;
			case 4:
				Admin_Util::printAllUsers(userList);
				break;
			case 5:
				Admin_Util::viewUser(userList);
				break;
			case 6:
				Admin_Util::audit(custList);
				break;
			case 7:
				cout <<"**Logging Off**"<<endl;
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

int Admin_Util::menu(vector<User*> userList, int currentUser) {
	int option;
	
	system("CLS");
	cout <<"Logged In: "<<userList[currentUser]->getName()<<"\n\n"
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

void Admin_Util::createAdmin(vector<User*> &userList, vector<Admin> &adminList) {		// Creates Admin Accounts

	string username, password, fname, lname, id, dob, hiredate, rank, emptype;
	int num;
	
	if (adminList.size() == adminList.max_size())
		cout <<"**Employee Not Added: List Full**"<<endl;
	else
	{
		do
		{
			cout <<"How many administrators do you want to add?: ";
			cin >>num;
		} while (num < 1 || num > (adminList.max_size() - adminList.size()));
			
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
				
			adminList.push_back(Admin(fname, lname, id, dob, hiredate, rank, emptype));
			userList.push_back(&adminList.back());
			
			// Set username and password
			adminList.back().loginInfo.setUsername(username);
			adminList.back().loginInfo.setPassword(password);
			
			// Write username and password into file
			Admin_Util::fromLoginFile(userList);
			Admin_Util::toLoginFile(userList);
		}
	}
}

void Admin_Util::createBanker(vector<User*> &userList, vector<Banker> &bnkrList) {
	
	string username, password, fname, lname, id, dob, hiredate, rank, emptype;
	int num;
	
	if (bnkrList.size() == bnkrList.max_size())
		cout <<"**Employee Not Added: List Full**"<<endl;
	else
	{
		do
		{
			cout <<"How many bankers do you want to add?: ";
			cin >>num;
		} while (num < 1 || num > (bnkrList.max_size() - bnkrList.size()));
			
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
			
			bnkrList.push_back(Banker(fname, lname, id, dob, hiredate, rank, emptype));
			userList.push_back(&bnkrList.back());
			
			// Set username and password
			bnkrList.back().loginInfo.setUsername(username);
			bnkrList.back().loginInfo.setPassword(password);
			
			// Write username and password into file
			Admin_Util::fromLoginFile(userList);
			Admin_Util::toLoginFile(userList);
		}
	}
}

void Admin_Util::createCustomer(vector<User*> &userList, vector<Customer> &custList) {
	
	string username, password, fname, lname, id, dob, occupation, address;
	int num;
	
	if (custList.size() == custList.max_size())
		cout <<"**Customer Not Added: List Full**"<<endl;
	else
	{
		do {
			cout <<"How many customers do you want to add?: ";
			cin >>num;
		} while (num < 1 || num > (custList.max_size() - custList.size()));
			
		for (int i=0; i<num; i++) {
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
			
			custList.push_back(Customer(fname, lname, id, dob, occupation, address));
			userList.push_back(&custList.back());
			
			// Set username and password
			custList.back().loginInfo.setUsername(username);
			custList.back().loginInfo.setPassword(password);
			
			// Write username and password into file
			Admin_Util::fromLoginFile(userList);
			Admin_Util::toLoginFile(userList);
		}
	}
}

void Admin_Util::printAllUsers(vector<User*> userList) {
	for (int i=0; i<userList.size(); i++)
	{
		userList[i]->print();
	}
	cout <<"======================="<<endl;
}

void Admin_Util::viewUser(vector<User*> userList) {
	string id;
	
	cout <<"Enter the ID# of the user to view: "<<endl;
	cin >>id;
	
	for (int i=0; i<userList.size(); i++)
		if (userList[i]->getID() == id) {
			userList[i]->print();
		}
}

void Admin_Util::audit(vector<Customer> custList) {
	int option;
	string id;
	
	do {	
		system("CLS");
		cout <<"\t\tAudit Utility Menu"<<"\n"
			 <<"\t\t=================="<<"\n"
			 <<"\t\t1. View Customer Account Info"<<"\n"
			 <<"\t\t2. List Customers"<<"\n"
			 <<"\t\t3. View Transaction Log"<<"\n"
			 <<"\t\t4. Return"<<"\n"
			 <<"\tChoose an option"<<endl;
		cin >>option;
	
		switch (option) {
			case 1: 
				cout <<"Enter Customer ID#: ";
				cin >>id;
				cout <<endl;
				Audit::printCustomerAccount(custList, id);
				break;
			case 2:
				Audit::printCustomerList(custList);
				break;
			case 3:
				Audit::fullTransactionHistory(custList);
				break;
			case 4:
				cout <<"**Returning**"<<endl;
				return;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 4);
}

// Write to all loaded user passwords and usernames to "login.txt"
// Caution** Use only after fromLoginFile(), or you will wipe the "login.txt" file
void Admin_Util::toLoginFile(vector<User*> &list) {
	ofstream loginFile;
	loginFile.open("login.txt");
	
	for (int i=0; i<list.size(); i++) {
		loginFile <<endl<<encrypt(list[i]->getID())<<"\t"<<encrypt(list[i]->loginInfo.getUsername())<<"\t"<<encrypt(list[i]->loginInfo.getPassword())<<"\t";
	}
	loginFile.close();
}

// Will load users with their password prior to saving to "login.txt"
void Admin_Util::fromLoginFile(vector<User*> &list) {
	
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
			
			for (int i=0; i<list.size(); i++) {
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
void Admin_Util::toUserFile(vector<User*> userList, vector<Admin> adminList, vector<Banker> bnkrList, vector<Customer> custList) {
	
	ostringstream convert; //for string conversion
	string converted; //for string conversion
	ofstream userFile;
	userFile.open("users.txt");
	
	for (int i=0; i<userList.size(); i++) {
		// Cycle through entire user list and write to file
		userFile <<endl<<userList[i]->getAccessRights()<<"\t"<<userList[i]->getFirstName()<<"\t"<<userList[i]->getLastName()<<"\t"<<encrypt(userList[i]->getID())<<"\t"<<encrypt(userList[i]->getDOB())<<"\t";
		
		// If current user is an Admin, then write these specific attributes to file
		if (userList[i]->getAccessRights() == "Admin") {
			for (int j=0; j<adminList.size(); j++) {
				if (userList[i]->getID() == adminList[j].getID()) {	// Match user ID in both arrays to make sure it is the correct user
					userFile <<encrypt(adminList[j].getHireDate())<<"\t"<<encrypt(adminList[j].getRank())<<"\t"<<encrypt(adminList[j].getEmploymentType())<<"\t";
				}
			}
		}
		
		else if (userList[i]->getAccessRights() == "Banker") {
			for (int j=0; j<bnkrList.size(); j++) {
				if (userList[i]->getID() == bnkrList[j].getID()) {
					userFile <<encrypt(bnkrList[j].getHireDate())<<"\t"<<encrypt(bnkrList[j].getRank())<<"\t"<<encrypt(bnkrList[j].getEmploymentType())<<"\t";
				}
			}
		}
		
		else if (userList[i]->getAccessRights() == "Customer") {
			for (int j=0; j<custList.size(); j++) {
				if (userList[i]->getID() == custList[j].getID()) {
					userFile <<encrypt(custList[j].getOccupation())<<"\t"<<encrypt(custList[j].getAddress())<<"\t";
					for (int h=0; h<2; h++) {
						userFile <<encrypt(custList[j].acc[h].getAccountNumber())<<"\t"<<encrypt(custList[j].acc[h].getAccountType())<<"\t";
						
						//Converting double to a string and encrypting into file
						convert << custList[j].acc[h].getBalance();
						converted = convert.str();
						userFile <<encrypt(converted)<<"\t";
						convert.str("");
					}
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
