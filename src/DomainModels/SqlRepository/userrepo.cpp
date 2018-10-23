#include "userrepo.h"


UserRepo::UserRepo()
{

}

std::vector<User> UserRepo::getUsers()
{
    DbContext dbc(DbConfig::conf);
    auto sj = dbc(select(user_.id,user_.name).from(user_).unconditionally());
    users.clear();
    for (auto const &user : sj)
    {
        users.push_back(User(user.id, user.name));
    }
    return users;
}
