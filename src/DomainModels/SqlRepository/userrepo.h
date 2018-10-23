#ifndef USERREPO_H
#define USERREPO_H

#include<vector>
#include "../user.h"

#include "sqlite-test.h"
#include <sqlpp11/custom_query.h>
#include <sqlpp11/sqlpp11.h>

#include"dbconfig.h"
#include"dbcontext.h"

class UserRepo
{
public:
    UserRepo();
    std::vector<User>  getUsers();
    bool createUser(User &instance);
    bool updateUser(User &instance);
    bool removeUser(int userId);
private:
    std::vector<User> users;    
    sqlRepo::User user_;

};

#endif // USERREPO_H
