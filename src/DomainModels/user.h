#ifndef USER_H
#define USER_H
#include<iostream>

class User
{
   int id;
   std::string userName;
public:
    User(int id, std::string userName );
    int getId() const;
    std::string getUserName() const;


};

#endif // USER_H
