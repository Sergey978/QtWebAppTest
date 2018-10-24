#include "role.h"

Role::Role(int id, std::string roleName)
{
    this->id = id;
    this->roleName = roleName;
}

int Role::getId()
{
    return id;
}

std::string Role::getRoleName() const
{
    return  roleName;
}
