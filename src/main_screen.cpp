#include "main_screen.h"
#include "Graph_lib/Graph.h"


void MainScreen::set_number_of_tasks(int new_number_of_tasks)
{
    number_of_tasks = new_number_of_tasks;
}

void MainScreen::set_number_records(int new_number_records)
{
    number_of_records = new_number_records;
}

int MainScreen::get_number_of_tasks()
{
    return number_of_tasks;
}

int MainScreen::get_number_of_records()
{
    return number_of_records;
}