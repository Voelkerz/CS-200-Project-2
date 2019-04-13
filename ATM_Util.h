//ATM_Util.h
//This will be the controlling system for all cystomer user commands
#include<iostream>
using namespace std;
#include "User.h"
#include "Admin_Util.h"

#ifndef ATM_UTIL_H
#define ATM_UTIL_H
class ATM_Util
{
	public:
		ATM_Util();
		static bool util_main(User* [], int, Customer*, int, int);
		static int menu(User* [], int);
		static int transfer();
		static int viewBalance();
		static int viewAccountInfo(User* [], Customer*, int, int);
		static string customerTransHistory();
		static void changePassword(User* [], int, int);
		virtual void foo() = 0;
};
#endif
