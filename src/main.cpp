#include <iostream>
#include <list>
#include <sstream>
#include <cmath>
#include <vector>
#include "Graph_lib/Simple_window.h"
#include "Graph_lib/Graph.h"
#include "design.h"

using namespace Graph_lib;

int main() 
try
{

Graph_lib::Window main_tab {screen_place, w_size_of_window, h_size_of_window,  program_name};

main_tab.resizable(nullptr);

//Сепараторы
Design_Main_Screen main_design;

set_line_style(main_design.high_separator, separator_pixel_count, Line_style::solid);
set_line_style(main_design.right_separator, separator_pixel_count, Line_style::solid);
set_line_style(main_design.upper_board, separator_pixel_count, Line_style::solid);
set_line_style(main_design.lower_board, separator_pixel_count, Line_style::solid);
set_line_style(main_design.left_board, separator_pixel_count, Line_style::solid);
set_line_style(main_design.right_board, separator_pixel_count, Line_style::solid);

main_tab.attach(main_design.high_separator);
main_tab.attach(main_design.right_separator);
main_tab.attach(main_design.upper_board);
main_tab.attach(main_design.lower_board);
main_tab.attach(main_design.left_board);
main_tab.attach(main_design.right_board);


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