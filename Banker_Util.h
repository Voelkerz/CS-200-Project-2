// Banker_Util.h
// This will be the controlling system for all banker user commands
#include <iostream>
using namespace std;
#include "Banker.h"
#include "Login.h"
#include "Admin_Util.h"
#include "Transactions.h"

#ifndef BANKER_UTIL_H
#define BANKER_UTIL_H
class Banker_Util {
	public:
		Banker_Util();
		static bool util_main(int, User* [], int, int&, Employee* [], int, int&, Admin*, int, int&, Banker*, int, int&, Customer*, int, int&);
		static bool menu(int, User* [], int, int, Customer*, int);
		virtual void foo()=0;
		void changePassword();
};
#endif
