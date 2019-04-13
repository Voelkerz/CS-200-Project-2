// Admin_Util.h
// This will be the controlling system for all administrator user commands
#include <iostream>
#include <fstream>
using namespace std;
#include "Admin.h"
#include "Audit.h"
#include "Banker.h"
#include "Customer.h"

#ifndef ADMIN_UTIL_H
#define ADMIN_UTIL_H
class Admin_Util {
	public:
		static bool util_main(int, User* [], int, int&, Admin*, int, int&, Banker*, int, int&, Customer*, int, int&);
		static int menu(User* [], int);
		static void createAdmin(User* [], int,  int&, Admin*, int, int&);
		static void createBanker(User* [], int,  int&, Banker*, int, int&);
		static void createCustomer(User* [], int,  int&, Customer*, int, int&);
		static void printAllUsers(User* [], int);
		static void viewUser(User* [], int);
		static void audit(Customer*, int);
		static void toLoginFile(User* [], int);
		static void toUserFile(User* [], int, Customer*, int, Admin*, int, Banker*, int);
		static void fromLoginFile(User* [], int);
		static string encrypt(string);
		static string decrypt(string);
		virtual void foo()=0;
};
#endif
