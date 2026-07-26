#ifndef USER_H
#define USER_H

#include <string>

class User
{
    protected:
        std::string username;
        std::string userpassword;
    public:
        User();
        User(std::string u,std::string p);
        void setUsername(std::string u);
        void setPassword(std::string p);
        std::string getUsername();
        std::string getPassword();
        virtual bool login()=0;
};
#endif