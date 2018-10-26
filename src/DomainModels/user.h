#ifndef USER_H
#define USER_H
#include<iostream>
#include<vector>
#include "role.h"

#include"SqlRepository/sqlrepository.h"




class User
{
   int id;
   std::string userName;
   std::vector<Role> roles;

public:   
    User(int id, std::string userName);
    User(int id, std::string userNamr, std::vector<Role> &roles);
    int getId() const;
    void setRoles(std::vector<Role> roles);
    std::string getUserName() const ;
    std::vector<Role> getRoles( );
};

#endif // USER_H
