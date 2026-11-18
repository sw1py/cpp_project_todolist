#include <iostream>
#include <list>
#include <sstream>
#include <cmath>
#include <vector>
#include "Graph_lib/Simple_window.h"
#include "Graph_lib/Graph.h"


using namespace Graph_lib;

int main() 
try
{

Point  t1{100, 100};
Window win {t1, 600, 500, "Canvas"};


gui_main();

return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}
catch(...)
{
    std::cerr << "gavno" << std::endl;
    return 2;
}