#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>

class DbStorage
{
public:
    DbStorage();
public:
   static  auto initStorage(const std::string &path);


};

#endif // STORAGE_H
