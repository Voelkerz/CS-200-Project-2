//Admin.h
#include"Employee.h"

#ifndef ADMIN_H
#define ADMIN_H
class Admin: public Employee
{
	public:
		Admin();
		Admin(string, string, string, string, string, string, string, string);
		void setID(string i);
};
#endif
