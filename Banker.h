//Banker.h
#include"Employee.h"

#ifndef BANKER_H
#define BANKER_H
class Banker: public Employee
{
	public:
		Banker();
		Banker(string, string, string, string, string, string, string);
		Banker(string, string, string, string, string, string, string, string);
		void print();
		void setID(string i);
};
#endif
