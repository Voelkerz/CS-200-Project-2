//Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include "User.h"
using namespace std;

class Customer: public User
{
	private:
		string occupation;
		string address;
	public:
		void setID(string);
		void setOccupation(string);
		void setAddress(string);
		string getOccupation();
		string getAddress();
		
};


#endif
