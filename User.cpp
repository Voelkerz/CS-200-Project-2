//User.cpp
using namespace std;
#include "User.h"
#include<iostream>
void User::setName(string f, string l)
{
	fname = f;
	lname = l;
};
void User::setAccessRights(string a)
{
	accessRights = a;
};
void User::setID(string i)
{
	id = i;
};
void User::setDOB(string d)
{
	dob = d;
};
string User::getName()
{
	return fname + " " + lname;
};
string User::getAccessRights()
{
	return accessRights;
};
string User::getID()
{
	return id;
};
string User::getDOB()
{
	return dob;
};
