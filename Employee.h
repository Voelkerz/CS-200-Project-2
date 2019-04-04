//Employee.h
using namespace std;
#include "User.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee: public User
{
	protected:
		string hireDate;
		string rank;
		string employmentType;
	public:
		void setHireDate(string);
		void setRank(string);
		void setEmploymentType(string);
		string getHireDate();
		string getRank();
		string getEmploymentType();
		
};

#endif
