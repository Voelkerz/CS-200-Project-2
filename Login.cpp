// Login.cpp
#include "Login.h"

/////////////////
// CONSTRUCTOR

Login::Login() {
	username = "";
	password = "";
}

Login::Login(string u, string p) {
	username = u;
	password = p;
}

/////////////////
// MUTATORS

void Login::setPassword(string p) {
	password = p;
}

void Login::setUsername(string u) {
	username = u;
}

/////////////////
// ACCESSORS

string Login::getPassword() {
	return password;
}

string Login::getUsername() {
	return username;
}
