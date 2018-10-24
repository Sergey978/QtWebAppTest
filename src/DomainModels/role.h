#ifndef ROLE_H
#define ROLE_H

#include<iostream>
#include <vector>

class User;

class Role
{
    int id;
    std::string roleName;

public:
    Role(int id, std::string roleName);
    int getId();
    std::string getRoleName() const;
    std::vector<User> getUsers() ;
};

#endif // ROLE_H
