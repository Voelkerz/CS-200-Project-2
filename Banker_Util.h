// Banker_Util.h
// This will be the controlling system for all banker user commands
#include <iostream>
using namespace std;
#include "ATM_Util.h"
#include "Admin_Util.h"

#ifndef BANKER_UTIL_H
#define BANKER_UTIL_H
class Banker_Util {
	public:
		static bool util_main(int, vector<User*> &, vector<Customer> &);
		static int menu(vector<User*>, vector<Customer>, int, int);
		static void changeCust(vector<Customer>, int&);
		virtual void foo()=0;
};
#endif
