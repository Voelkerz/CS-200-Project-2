// Banker_Util.h
// This will be the controlling system for all banker user commands
#include <iostream>
using namespace std;

#ifndef BANKER_UTIL_H
#define BANKER_UTIL_H
class Banker_Util {
	public:
		static void util_main();
		static int menu();
		virtual void foo()=0;
};
#endif
