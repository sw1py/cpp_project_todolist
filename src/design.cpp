
#include "design.h"

//Константы, вся хуйня
Graph_lib::Point screen_place {100, 100};

const std::string program_name {"ToDoList"};

int w_size_of_window {650};
int h_size_of_window {500};

//Инициализация точек

Graph_lib::Point highest_point_right_separator {500, 0};
Graph_lib::Point low_point_right_separator {500, 500};
Graph_lib::Point left_point_high_separator {0, 350};
Graph_lib::Point right_point_high_separator {500, 350};
Graph_lib::Point left_point_upper_board {0, 0};
Graph_lib::Point right_point_upper_board {650, 0};
Graph_lib::Point left_point_lower_board {0, 500};
Graph_lib::Point right_point_lower_board {650, 500};

//Инициализация разделителей и фигур

Design_Shapes::Design_Shapes()
    : right_separator {highest_point_right_separator, low_point_right_separator}
    , high_separator  {left_point_high_separator, right_point_high_separator}
    , upper_board {left_point_upper_board, right_point_upper_board}
    , lower_board {left_point_lower_board, right_point_lower_board}
{}

//Установка размеров линий (реализация функции для этого)

void set_line_style(Graph_lib::Line& line, int count_of_pixel, Graph_lib::Line_style::Line_style_type any)
{
    line.set_style(Graph_lib::Line_style(any, count_of_pixel));
}

int separator_pixel_count {2};

