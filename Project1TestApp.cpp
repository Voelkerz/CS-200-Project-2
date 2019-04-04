#include <iostream>
using namespace std;
#include "User.h"
#include "Customer.h"
#include "Employee.h"
#include "Admin.h"
#include "Login_Util.h"
#include "Admin_Utility.h"
#include "Accounts.h"

int main(int argc, char** argv) {
	int option;
	int maxEmp = 5;
	int empPos = 0;
	Admin adminList[maxEmp];

	do {
		option = Login_Util::menu();
		switch (option) {
			case 1: 
				Admin_Utility::util_main(adminList, maxEmp, empPos);
				break;
			case 5:
				cout <<"**Exiting Main Program**"<<endl;
				break;
			default:
				cout <<"**Invalid Option**"<<endl;	
		}
		
		system("PAUSE");
	} while (option != 5);
	
	return 0;
}
