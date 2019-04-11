//ATM_Util.h
//This will be the controlling system for all cystomer user commands
#include<iostream>
#include "Customer.h"
using namespace std;

#ifndef ATM_UTIL_H
#define ATM_UTIL_H

class ATM_Util
{
	public:
		ATM_Util();
		static bool util_main();
		static int menu();
		int transfer();
		int printBalance();
		int printAccountInfo();
		string customerTransHistory();
		string changePassword();
		virtual void foo() = 0;
	private:
		
};

#endif
