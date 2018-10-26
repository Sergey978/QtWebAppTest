#include "sqlrepository.h"
#include"dbcontext.h"
SqlRepository::SqlRepository( )
{

}

std::vector<User> SqlRepository::getUsers()
{
    DbContext   &dbc= DbContext::Instance();
    auto sj = dbc(select(userTab_.id,userTab_.name).from(userTab_).unconditionally());
    users.clear();
    for (auto const &user : sj)
    {
        users.push_back(User(user.id, user.name));
    }
    return users;

}

std::vector<User> SqlRepository::getUsersWithRoles()
{
     DbContext   &dbc= DbContext::Instance();
    auto sj = dbc(select(userTab_.id,userTab_.name).from(userTab_).unconditionally());
        users.clear();
        for (auto const &user : sj)
        {
            //select roles for each user
            auto  sr =  dbc(select(roleTab_.id,  roleTab_.roleName)
                                .from(roleTab_.join(userRolesTab_)
                                .on(roleTab_.id == userRolesTab_.RoleId and userRolesTab_.userId == user.id))
                                .unconditionally());
            roles_.clear();
             for (auto const &role : sr)
             {
                 roles_.push_back(Role(role.id, role.roleName));
             }

            users.push_back(User(user.id, user.name, roles_));
        }
    return users;
}

std::vector<Role> SqlRepository::getRoles()
{
    DbContext   &dbc= DbContext::Instance();
    auto sj = dbc(select(roleTab_.id,roleTab_.roleName).from(roleTab_).unconditionally());
    roles_.clear();
    for (auto const &role : sj)
    {
        roles_.push_back(Role(role.id, role.roleName));
    }
    return roles_;
}

std::vector<Role> SqlRepository::getUserRoles(int id)
{
    DbContext   &dbc= DbContext::Instance();
     auto sj =  dbc.run(select(roleTab_.id,  roleTab_.roleName)
                    .from(roleTab_.join(userRolesTab_)
                          .on(roleTab_.id == userRolesTab_.RoleId and userRolesTab_.userId == id))
                    .unconditionally());


     roles_.clear();
     for (auto const &role : sj)
     {
         roles_.push_back(Role(role.id, role.roleName));
     }
     return roles_;
}
