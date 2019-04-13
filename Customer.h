//Customer.h
#include "User.h"
#include "Accounts.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer: public User
{
	private:
		string occupation;
		string address;
	public:
		Customer();
		Customer(string, string, string, string, string, string);
		Customer(string, string, string, string, string, string, string, string, string, double, string, string, double);
		void print();
		void setID(string);
		void setOccupation(string);
		void setAddress(string);
		string getOccupation();
		string getAddress();
		Accounts acc[2];
		
};
#endif
