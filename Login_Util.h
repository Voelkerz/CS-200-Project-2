// Login_Util.h
// This will be the controlling system for all Login functionality
#include "Login.h"
#include "Admin_Util.h"

#ifndef LOGIN_UTIL_H
#define LOGIN_UTIL_H
class Login_Util {
	public:
		static void util_main(User* userList[], Admin* adminList,  int max, int &userPos, int &adminPos);
		static bool menu(User* userList[], int, int &pos);
		static void toLoginFile(string);
		static void fromLoginFile(User* userList[], int max, int &pos);
		virtual void foo()=0;
};
#endif
