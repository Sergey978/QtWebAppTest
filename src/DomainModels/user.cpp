#include "user.h"

User::User(int id, std::string userName ):
    id(id),userName(userName)
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
