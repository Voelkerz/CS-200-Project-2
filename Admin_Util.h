// Admin_Util.h
// This will be the controlling system for all administrator user commands
#include <iostream>
using namespace std;
#include "Admin.h"

#ifndef ADMIN_UTIL_H
#define ADMIN_UTIL_H
class Admin_Util {
	public:
		static bool util_main(User* [], Admin*, int, int&, int&, int);
		static int menu(User* [], int);
		static void createAdmin(Admin*, int, int&);
		static void printAllUsers(Admin*, int);
		virtual void foo()=0;
};
#endif
