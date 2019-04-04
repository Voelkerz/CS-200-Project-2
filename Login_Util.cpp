//Login_Util.cpp
#include "Login_Util.h"

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
