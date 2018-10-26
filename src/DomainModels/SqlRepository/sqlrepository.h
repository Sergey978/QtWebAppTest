#ifndef SQLREPOSITORY_H
#define SQLREPOSITORY_H

#include <vector>
#include "../user.h"
#include"../role.h"


#include "sqlite-test.h"
#include <sqlpp11/custom_query.h>
#include <sqlpp11/sqlpp11.h>

#include"dbconfig.h"
#include"dbcontext.h"

class SqlRepository
{
public:
    SqlRepository( );
    //User repository
    std::vector<User>  getUsers();
    std::vector<User>  getUsersWithRoles();
    bool createUser(User &instance);
    bool updateUser(User &instance);
    bool removeUser(int userId);

    // Role Repository
    std::vector<Role>  getRoles();
    std::vector<Role> getUserRoles(int id);
    bool createRole(Role &instance);
    bool updateRole(Role &instance);
    bool removeRole(int RoleId);

private:

    sqlRepo::Role roleTab_;
    sqlRepo::User userTab_;
    sqlRepo::UserRoles userRolesTab_;
    std::vector<Role> roles_;
    std::vector<User> users;

};

#endif // SQLREPOSITORY_H
