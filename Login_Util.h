// Login_Util.h
// This will be the controlling system for all Login functionality
#include "Login.h"
#include "Admin_Util.h"
#include "Banker_Util.h"
#include "ATM_Util.h"

#ifndef LOGIN_UTIL_H
#define LOGIN_UTIL_H
class Login_Util {
	public:
		static void util_main(User* [], int, int&,
							  Employee* [], int, int&,
							  Admin*, int, int&, 
							  Banker*, int, int&,
							  Customer*, int, int&);
		static bool menu(User* [], int, int&);
		static void toLoginFile(string);
		static void fromLoginFile(User* [], int max, int &pos);
		virtual void foo()=0;
};
#endif
