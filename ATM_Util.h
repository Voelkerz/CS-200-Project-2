//ATM_Util.h
//This will be the controlling system for all cystomer user commands
#include<iostream>
using namespace std;
#include "User.h"
#include "Admin_Util.h"
#include "Transactions.h"

#ifndef ATM_UTIL_H
#define ATM_UTIL_H
class ATM_Util
{
	public:
		ATM_Util();
		static bool util_main(User* [], int, Customer*, int, int);
		static int menu(User* [], int);
		static void transfer();
		static void createAccount(Customer*, int, int);
		static void viewAccountInfo(Customer*, int);
		static void customerTransHistory();
		static void changePassword(User* [], int, int);
		virtual void foo() = 0;
};
#endif
