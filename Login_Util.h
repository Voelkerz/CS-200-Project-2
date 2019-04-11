// Login_Util.h
// This will be the controlling system for all Login functionality
#include <iostream>
#include <fstream>
using namespace std;
#include "Login.h"
#include "Admin_Util.h"
#include "Banker_Util.h"
#include "ATM_Util.h"

#ifndef LOGIN_UTIL_H
#define LOGIN_UTIL_H
class Login_Util {
	public:
		static void util_main(User* [], int, int&, Employee* [], int, int&, Admin*, int, int&, Banker*, int, int&, Customer*, int, int&);
		static int menu();
		static bool login(User* [], int, int&);
		static void initializeUsers(User* [], int&, Employee* [], int&,	Admin*, int&, Banker*, int&, Customer*, int&);
		static string encrypt(string);
		static string decrypt(string);
		virtual void foo()=0;
};
#endif
