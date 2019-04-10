//Customer.h
#include"Customer.h"

//------------------------------//
// CONSTRUCTORS					//
//------------------------------//

Customer::Customer() {
	setAccessRights("Customer");
}

Customer::Customer(string a, string f, string l, string i, string d, string o, string ad) {
	setAccessRights(a);
	setName(f, l);
	id = i;
	setDOB(d);
	setOccupation(o);
	setAddress(ad);
}

//------------------------------//
// MUTATOR FUNCTIONS			//
//------------------------------//

void Customer::setID(string i)
{
	id = i + "C";
}

void Customer::setOccupation(string o)
{
	occupation = o;
}

void Customer::setAddress(string a)
{
	address = a;
}

//------------------------------//
// ACCESSOR FUNCTIONS			//
//------------------------------//

string Customer::getOccupation()
{
	return occupation;
}

string Customer::getAddress()
{
	return address;
}
