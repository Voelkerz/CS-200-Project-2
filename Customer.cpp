//Customer.h
using namespace std;
#include"Customer.h"
void Customer::setID(string i)
{
	id = i + "C";
};
void Customer::setOccupation(string o)
{
	occupation = o;
};
void Customer::setAddress(string a)
{
	address = a;
};
string Customer::getOccupation()
{
	return occupation;
};
string Customer::getAddress()
{
	return address;
};
