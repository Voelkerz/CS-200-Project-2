//Banker.cpp
#include"Banker.h"

//------------------------------//
// CONSTRUCTORS					//
//------------------------------//

Banker::Banker() {
	setAccessRights("Banker");
}

Banker::Banker(string f, string l, string i, string d, string h, string r, string e) {
	setAccessRights("Banker");
	setName(f, l);
	setID(i);
	setDOB(d);
	setHireDate(h);
	setRank(r);
	setEmploymentType(e);
}

Banker::Banker(string a, string f, string l, string i, string d, string h, string r, string e) {
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

void Banker::setID(string i)
{
	id = i + "B";
}
