// Login.h
#include <iostream>
using namespace std;

#ifndef LOGIN_H
#define LOGIN_H
class Login {
	public:
		Login();
		Login(string, string);
		void setUsername(string);
		void setPassword(string);
		string getUsername();
		string getPassword();
	private:
		string username;
		string password;
};
#endif
