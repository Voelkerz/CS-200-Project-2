// Admin_Util.cpp
#include "Admin_Util.h"

//------------------------------//
// MAIN FOR ADMIN SYSTEM		//
//------------------------------//

bool Admin_Util::util_main(User* userList[], Admin* admListPTR, int max, int &userPos, int &admPos, int currentUser) {
	int option;
	
	do {
		option = Admin_Util::menu(userList, currentUser);
		switch (option) {
			case 1: 
				Admin_Util::createAdmin(admListPTR, max, admPos);
				break;
			case 2:
				Admin_Util::printAllUsers(admListPTR, admPos);
				break;
			case 5:
				cout <<"**Logging Off**"<<endl;
				return false;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 5);
}

//------------------------------//
// MENU							//
//------------------------------//

int Admin_Util::menu(User* userList[], int currentUser) {
	int option;
	
	system("CLS");
	cout <<"\t\tLogged In: "<<userList[currentUser]->getName()<<"\n\n"
		 <<"\t\tAdministrator Utility Menu"<<endl
		 <<"\t\t=========================="<<endl
		 <<"\t\t1. Create Administrator Account"<<endl
		 <<"\t\t2. View All Users"<<endl
		 <<"\t\t5. LOGOUT"<<endl
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}

//------------------------------//
// FUNCTIONS					//
//------------------------------//

void Admin_Util::createAdmin(Admin* admPTR, int max, int &admPos) {		// Creates Admin Accounts
	int num;
	string first, last, id, hireDate;
	
	if (admPos == max)
		cout <<"**Employee Not Added: List Full**"<<endl;
	else
	{
		do
		{
			cout <<"How many administrators do you want to add?: ";
			cin >>num;
		} while (num < 1 || num > (max - admPos));
		
		//set admin pointer to next memory location
		for (int i=0; i<admPos; i++)
			admPTR++;
			
		//fill in admin info
		for (int i=0; i<num; i++)
		{
			cout <<"\nEnter Name: ";
			cin >>first>>last;
			cout <<"Enter ID: ";
			cin >>id;
			cout <<"Enter Hire Date (YYYY/MM/DD): ";
			cin >>hireDate;
			admPTR->setName(first, last);
			admPTR->setID(id);
			admPTR->setHireDate(hireDate);
			admPTR++;
		}
		
		admPos += num;
	}
}

void Admin_Util::printAllUsers(Admin* admPTR, int max) {	//Prints a list of all users in system (only admins for now)
	for (int i=0; i<max; i++)
	{
		cout <<"\nName: "<<admPTR->getName()<<endl
			 <<"Hire Date: "<<admPTR->getHireDate()<<endl
			 <<"ID: "<<admPTR->getID()<<endl
			 <<"Access Rights: "<<admPTR->getAccessRights()<<"\n"<<endl;
		admPTR++;
	}
}
