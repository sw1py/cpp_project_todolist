#ifndef DESIGN
#define DESIGN
#include <string>
#include "Graph_lib/Graph.h"
//Может быть вместо кучи констант можно будет завести класс
extern Graph_lib::Point screen_place;

extern const std::string program_name;

extern int w_size_of_window;
extern int h_size_of_window;

struct Design_Main_Screen {

    Graph_lib::Line right_separator;
    Graph_lib::Line high_separator;
    Graph_lib::Line upper_board;
    Graph_lib::Line lower_board;
    Graph_lib::Line left_board;
    Graph_lib::Line right_board;

    Design_Main_Screen();
};

extern Graph_lib::Point highest_point_right_separator;
extern Graph_lib::Point low_point_right_separator;

extern Graph_lib::Point left_point_high_separator;
extern Graph_lib::Point right_point_high_separator;

extern Graph_lib::Point left_point_upper_board;
extern Graph_lib::Point right_point_upper_board;

extern Graph_lib::Point left_point_lower_board;
extern Graph_lib::Point right_point_lower_board;

void set_line_style(Graph_lib::Line& line, int count_of_pixel, Graph_lib::Line_style::Line_style_type any);

extern int separator_pixel_count;
extern int calendar_table_pixel_count;


#endif