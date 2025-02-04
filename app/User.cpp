#include "User.h"

User::User(const string& login, const string& password, const string& name, double& time) :_login(login), _password(password), _name(name) {}

const string& User::GetUserLogin()const
{

	return _login;
}

const string& User::GetUserPassword()const 
{
	return _password;
}

void User::SetUserPassword(const string& password)
{
	_password = password;
}

const string& User::GetUserName()const
{
	return _name;
}

void User::SetUserName(const string& name)
{
	_name = name;
}