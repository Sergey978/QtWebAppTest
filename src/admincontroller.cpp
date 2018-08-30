#include "admincontroller.h"
#include "sqlite_orm/sqlite_orm.h"
#include <iostream>

struct Employee {
    int id;
    std::string name;
    int age;
    std::shared_ptr<std::string> address;   //  optional
    std::shared_ptr<double> salary; //  optional
};

using namespace sqlite_orm;
using std::cout;
using std::endl;

AdminController::AdminController(QObject *parent)
    : HttpRequestHandler(parent)
{


}

void AdminController::service(HttpRequest &request, HttpResponse &response)
{

   auto storage = make_storage("select.sqlite",
                                  make_table("COMPANY",
                                             make_column("ID",
                                                         &Employee::id,
                                                         primary_key()),
                                             make_column("NAME",
                                                         &Employee::name),
                                             make_column("AGE",
                                                         &Employee::age),
                                             make_column("ADDRESS",
                                                         &Employee::address),
                                             make_column("SALARY",
                                                         &Employee::salary)));

   //  now let's select id, name and salary..
       auto idsNamesSalarys = storage.select(columns(&Employee::id,
                                                     &Employee::name,
                                                     &Employee::salary));
       //  decltype(idsNamesSalarys) = std::vector<std::tuple<int, std::string, std::shared_ptr<double>>>
       for(auto &tpl : idsNamesSalarys) {
           cout << "id = " << std::get<0>(tpl) << ", name = " << std::get<1>(tpl) << ", salary = ";
           if(std::get<2>(tpl)){
               cout << *std::get<2>(tpl);
           }else{
               cout << "null";
           }
           cout << endl;
       }


    response.write("Hello1 This is Admin Area",true);
}
