//Login_Util.h
#include <iostream>
using namespace std;

#ifndef LOGIN_UTIL_H
#define LOGIN_UTIL_H
class Login_Util {
	public:
		static void util_main();
		static int menu();
		virtual void foo()=0;
};
#endif