#ifndef TO_DO_LIST_GRAPH
#define TO_DO_LIST_GRAPH

#include "screen.h"
#include "Graph_lib/Graph.h"
#
class MainScreen : public Screen
{
public:
    MainScreen   

    void set_number_of_tasks(int new_number_of_tasks);
    void set_number_records(int new_number_of_records);

    int get_number_of_tasks();
    int get_number_of_records();

protected:


private:
    
    int number_of_tasks;
    int number_of_records;
};


#endif