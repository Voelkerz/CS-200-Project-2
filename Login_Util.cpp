//Login_Util.cpp
#include "Login_Util.h"

// MAIN for Login Screen
void Login_Util::util_main() {
	
}

// Login Menu Function
int Login_Util::menu() {
	
	int option;
	
	system("CLS");
	cout <<"\t\tMain Menu"<<endl
		 <<"\t\t========="<<endl
		 <<"\t\t1. Administrator Utility"<<endl
		 <<"\t\t5. EXIT PROGRAM"<<endl
		 <<"\tChoose an option"<<endl;
	cin >>option;
		
	return option;
}
