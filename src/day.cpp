#include "day.h"
#include <iostream> //потом удалить

Day::Day(Graph_lib::Point xy, int w, int h, const std::string& s, Graph_lib::Callback cb, const int day_number):
Graph_lib::Widget(xy, w, h, s, cb), day_number(day_number) {}

void Day::on_click()
{
    std::cout << "Danila pidor";
}