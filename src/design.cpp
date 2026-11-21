
#include "design.h"

//Константы, вся хуйня
Graph_lib::Point screen_place {100, 100};

const std::string program_name {"ToDoList"};

int w_size_of_window {650};
int h_size_of_window {500};

//Инициализация точек -
//Правый разделитель
Graph_lib::Point highest_point_right_separator {500, 0};
Graph_lib::Point low_point_right_separator {500, 500};
//Верхний разделитель
Graph_lib::Point left_point_high_separator {0, 350};
Graph_lib::Point right_point_high_separator {500, 350};
//Верхняя граница 
Graph_lib::Point left_point_upper_board {0, 0};
Graph_lib::Point right_point_upper_board {650, 0};
//Нижняя граница
Graph_lib::Point left_point_lower_board {0, 500};
Graph_lib::Point right_point_lower_board {650, 500};
//Левая граница
Graph_lib::Point high_point_left_board {0, 0};
Graph_lib::Point low_point_left_board {0, 500};
//Правая граница
Graph_lib::Point high_point_right_board {650, 0};
Graph_lib::Point low_point_right_board {650, 500};

//Инициализация разделителей и фигур

Design_Main_Screen::Design_Main_Screen()
    : right_separator {highest_point_right_separator, low_point_right_separator}
    , high_separator  {left_point_high_separator, right_point_high_separator}
    , upper_board {left_point_upper_board, right_point_upper_board}
    , lower_board {left_point_lower_board, right_point_lower_board}
    , left_board {high_point_left_board, low_point_left_board}
    , right_board {high_point_right_board, low_point_right_board}
{}

//Установка размеров линий (реализация функции для этого)

void set_line_style(Graph_lib::Line& line, int count_of_pixel, Graph_lib::Line_style::Line_style_type any)
{
    line.set_style(Graph_lib::Line_style(any, count_of_pixel));
}

int separator_pixel_count {2};



