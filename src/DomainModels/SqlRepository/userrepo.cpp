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
        //select roles for each user
        auto  sr =  dbc(select(role_.id,  role_.roleName)
                            .from(role_.join(userRoles_)
                            .on(role_.id == userRoles_.RoleId and userRoles_.userId == user.id))
                            .unconditionally());
        roles.clear();
         for (auto const &role : sr)
         {
             roles.push_back(Role(role.id, role.roleName));
         }

        users.push_back(User(user.id, user.name, roles));
    }
    return users;
}
