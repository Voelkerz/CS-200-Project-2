// Login.cpp
#include "Login.h"

//------------------------------//
// CONSTRUCTORS					//
//------------------------------//

Login::Login() {
	setUsername("");
	setPassword("");
}

Login::Login(string u, string p) {
	setUsername(u);
	setPassword(p);
}

//------------------------------//
// MUTATOR FUNCTIONS			//
//------------------------------//

void Login::setPassword(string p) {
	password = p;
}

void Login::setUsername(string u) {
	username = u;
}

//------------------------------//
// ACCESSOR FUNCTIONS			//
//------------------------------//

string Login::getPassword() {
	return password;
}

string Login::getUsername() {
	return username;
}
