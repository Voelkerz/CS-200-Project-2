//User.h
#include <iostream>
using namespace std;
#include "Login.h"

#ifndef USER_H
#define USER_H
class User
	{
		protected:
			string fname;
			string lname;
			string accessRights;
			string id;
			string dob;
		public:
			User();
			void setName(string, string);
			void setAccessRights(string);
			void setID(string);
			void setDOB(string);
			string getName();
			string getFirstName();
			string getLastName();
			string getAccessRights();
			string getID();
			string getDOB();
			Login loginInfo;
	};
#endif
