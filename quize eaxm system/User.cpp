#include "User.h"
#include <string>
#include <iostream>

User::User():username(""),userpassword("")
{}

User::User(std::string u, std::string p)
{
    username = u;
    userpassword = p;
}

void User::setUsername(std::string u)
{
    username = u;
}

void User::setPassword(std::string p)
{
    userpassword = p;
}

std::string User::getUsername()
{
    return username;
}

std::string User::getPassword()
{
    return userpassword;
}
