// Admin_Util.h
// This will be the controlling system for all administrator user commands
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
#include "Admin.h"
#include "Audit.h"
#include "Banker.h"
#include "Customer.h"

#ifndef ADMIN_UTIL_H
#define ADMIN_UTIL_H
class Admin_Util {
	public:
		static bool util_main(int, vector<User*> &, vector<Admin> &, vector<Banker> &, vector<Customer> &);
		static int menu(vector<User*>, int);
		static void createAdmin(vector<User*> &, vector<Admin> &);
		static void createBanker(vector<User*> &, vector<Banker> &);
		static void createCustomer(vector<User*> &, vector<Customer> &);
		static void printAllUsers(vector<User*>);
		static void viewUser(vector<User*>);
		static void audit(vector<Customer>);
		static void toLoginFile(vector<User*> &);
		static void toUserFile(vector<User*>, vector<Admin>, vector<Banker>, vector<Customer>);
		static void fromLoginFile(vector<User*> &);
		static string encrypt(string);
		static string decrypt(string);
		virtual void foo()=0;
};
#endif
