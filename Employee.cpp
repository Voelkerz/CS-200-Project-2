//Employee.cpp
#include"Employee.h"
using namespace std;

void Employee::setHireDate(string h)
{
	hireDate = h;
};
void Employee::setRank(string r)
{
	rank = r;
};
void Employee::setEmploymentType(string e)
{
	employmentType = e;
};
string Employee::getHireDate()
{
	return hireDate;
};
string Employee::getRank()
{
	return rank;
};
string Employee::getEmploymentType()
{
	return employmentType;
};
