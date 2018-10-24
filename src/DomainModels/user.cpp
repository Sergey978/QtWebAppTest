#include "user.h"
#include "SqlRepository/rolerepo.h"



User::User(int id, std::string userName):id(id),userName(userName)
{

}

User::User(int id, std::string userName, std::vector<Role> &roles)
    :id(id), userName(userName),roles(roles)
{

}

int User::getId() const
{
    return id;
}

std::string User::getUserName() const
{
    return userName;
}

std::vector<Role> User::getRoles() const
{

    return roles;

}

