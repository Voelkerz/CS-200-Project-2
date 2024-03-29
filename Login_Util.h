// Login_Util.h
// This will be the controlling system for all Login functionality
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Login.h"
#include "Admin_Util.h"
#include "Banker_Util.h"
#include "ATM_Util.h"

#ifndef LOGIN_UTIL_H
#define LOGIN_UTIL_H
class Login_Util {
	public:
		static void util_main(vector<User*> &, vector<Admin> &, vector<Banker> &, vector<Customer> &);
		static bool login(vector<User*>, int&);
		static void initializeUsers(vector<User*> &, vector<Admin> &, vector<Banker> &, vector<Customer> &);
		static string encrypt(string);
		static string decrypt(string);
		virtual void foo()=0;
};
#endif
