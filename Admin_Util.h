//Admin_Util.h
#include "Login_Util.h"
#include "User.h"
#include "Employee.h"
#include "Customer.h"
#include "Admin.h"

#ifndef ADMIN_UTIL_H
#define ADMIN_UTIL_H
class Admin_Util: public Login_Util {
	public:
		static void util_main(Admin*, int, int&);
		static int menu();
		static void createAdmin(Admin*, int, int&);
		static void printAllUsers(Admin*, int);
		virtual void foo()=0;
};
#endif
