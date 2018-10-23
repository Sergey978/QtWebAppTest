#ifndef ROLEREPO_H
#define ROLEREPO_H

#include<vector>
#include "../role.h"

#include "sqlite-test.h"
#include <sqlpp11/custom_query.h>
#include <sqlpp11/sqlpp11.h>

#include"dbconfig.h"
#include"dbcontext.h"

class RoleRepo
{
public:
    RoleRepo();
    std::vector<Role>  getRoles();
    std::vector<Role> getUserRoles(int userId);
    bool createRole(Role &instance);
    bool updateUser(Role &instance);
    bool removeUser(int rolerId);
private:
    std::vector<Role> roles_;
    sqlRepo::Role role_;
    sqlRepo::UserRoles userRoles_;
    sqlRepo::User user_;

};

#endif // ROLEREPO_H
