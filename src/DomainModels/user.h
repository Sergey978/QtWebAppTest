#ifndef USER_H
#define USER_H
#include<iostream>
#include<vector>
#include "role.h"


class User
{
   int id;
   std::string userName;
   std::vector<Role> roles;  

public:
    User(int id, std::string userName);
    int getId() const;
    std::string getUserName() const;
    std::vector<Role> getRoles() const;   
};

#endif // USER_H
