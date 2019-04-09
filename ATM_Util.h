// ATM_Util.h
// This will be the controlling system for all customer user commands
#include <iostream>
using namespace std;
#include "Customer.h"

#ifndef ATM_UTIL_H
#define ATM_UTIL_H
class ATM_Util {
	public:
		static void util_main();
		static int menu();
		virtual void foo()=0;
};
#endif
