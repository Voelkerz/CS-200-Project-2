//Admin.cpp
#include"Admin.h"

//------------------------------//
// CONSTRUCTORS					//
//------------------------------//

Admin::Admin() {
	setAccessRights("Admin");
}

Admin::Admin(string f, string l, string i, string d, string h, string r, string e) {
	setAccessRights("Admin");
	setName(f, l);
	setID(i);
	setDOB(d);
	setHireDate(h);
	setRank(r);
	setEmploymentType(e);
}

Admin::Admin(string a, string f, string l, string i, string d, string h, string r, string e) {
	setAccessRights(a);
	setName(f, l);
	id = i;
	setDOB(d);
	setHireDate(h);
	setRank(r);
	setEmploymentType(e);
}	

//------------------------------//
// MUTATOR FUNCTIONS			//
//------------------------------//

void Admin::setID(string i)
{
	id = i + "A";
}
