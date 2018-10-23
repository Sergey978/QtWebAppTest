#include "rolerepo.h"

RoleRepo::RoleRepo()
{

}

std::vector<Role> RoleRepo::getRoles()
{
    DbContext dbc(DbConfig::conf);
    auto sj = dbc(select(role_.id,role_.roleName).from(role_).unconditionally());
    roles_.clear();
    for (auto const &role : sj)
    {
        roles_.push_back(Role(role.id, role.roleName));
    }
    return roles_;

}

std::vector<Role> RoleRepo::getUserRoles(int userId)
{
    DbContext dbc(DbConfig::conf);
 //   auto sj = dbc(select(role_.id,role_.roleName).from(role_));
    auto sj =  dbc(select(role_.id,  role_.roleName)
                  .from(role_.join(userRoles_).on(role_.id == userRoles_.RoleId).unconditionally());

    roles_.clear();
    for (auto const &role : sj)
    {
        roles_.push_back(Role(role.id, role.roleName));
    }
    return roles_;
}
