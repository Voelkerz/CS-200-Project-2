//Utility.h
#include <iostream>
using namespace std;

#ifndef UTILITY_H
#define UTILITY_H
class Utility {
	public:
		static void util_main();
		static int menu();
		virtual void foo()=0;
};
#endif
