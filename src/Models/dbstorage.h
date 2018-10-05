#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>

class DbStorage
{
public:
    DbStorage();
public:
   static  auto initStorage(const std::string &path);
    static const auto storage = initStorage("") ;

};

#endif // STORAGE_H
