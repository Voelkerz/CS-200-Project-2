//Employee.cpp
#include"Employee.h"

//------------------------------//
// MUTATOR FUNCTIONS			//
//------------------------------//

void Employee::setHireDate(string h)
{
	hireDate = h;
}

void Employee::setRank(string r)
{
	rank = r;
}

void Employee::setEmploymentType(string e)
{
	employmentType = e;
}

//------------------------------//
// ACCESSOR FUNCTIONS			//
//------------------------------//

string Employee::getHireDate()
{
	return hireDate;
}

string Employee::getRank()
{
	return rank;
}

string Employee::getEmploymentType()
{
	return employmentType;
}
