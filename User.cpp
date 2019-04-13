//User.cpp
#include "User.h"

//------------------------------//
// CONSTRUCTORS					//
//------------------------------//

User::User() {
	
	setID("Null");
	setName("Null", "Null");
	setDOB("Null");
}

//------------------------------//
// MUTATOR FUNCTIONS			//
//------------------------------//
void User::print()
{
	
}

void User::setName(string f, string l)
{
	fname = f;
	lname = l;
}

void User::setAccessRights(string a)
{
	accessRights = a;
}

void User::setID(string i)
{
	id = i;
}

void User::setDOB(string d)
{
	dob = d;
}

//------------------------------//
// ACCESSOR FUNCTIONS			//
//------------------------------//

string User::getName()
{
	return fname + " " + lname;
}

string User::getFirstName() {
	return fname;
}

string User::getLastName() {
	return lname;
}

string User::getAccessRights()
{
	return accessRights;
}

string User::getID()
{
	return id;
}

string User::getDOB()
{
	return dob;
}
