//User.h
#include <iostream>
#include "Login.h"

#ifndef USER_H
#define USER_H
using namespace std;
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
			string getAccessRights();
			string getID();
			string getDOB();
			Login loginInfo;
	
	};

#endif
