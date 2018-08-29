#include "startup.h"

using namespace stefanfrings;



int main(int argc, char *argv[])
{
    Startup startup(argc, argv);
    return startup.exec();

}
