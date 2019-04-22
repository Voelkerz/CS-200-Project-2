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
		static bool util_main(vector<User*> &, vector<Customer> &, int);
		static int menu(vector<User*>, int);
		static void createAccount(vector<Customer> &, int);
		static void viewAccountInfo(vector<Customer>, int);
		static void customerTransHistory(vector<Customer>, int);
		static void changePassword(vector<User*> &, int);
		static void depositFunds(vector<Customer> &, int);
		static void withdrawFunds(vector<Customer> &, int);
		static void transferFunds();
		static string encrypt(string);
		static string decrypt(string);
		virtual void foo() = 0;
};
#endif
