//Admin_Utility.h
#include "Login_Util.h"
#include "User.h"
#include "Employee.h"
#include "Customer.h"
#include "Admin.h"

#ifndef ADMIN_UTILITY_H
#define ADMIN_UTILITY_H
class Admin_Utility: public Login_Util {
	public:
		static void util_main(Admin*, int, int&);
		static int menu();
		static void createAdmin(Admin*, int, int&);
		static void printAllUsers(Admin*, int);
		virtual void foo()=0;
};
#endif
