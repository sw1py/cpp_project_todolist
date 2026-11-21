#ifndef TO_DO_LIST_GRAPH
#define TO_DO_LIST_GRAPH
#include "calendar/date.h"
#include "screen.h"
#include "Graph_lib/Graph.h"

class MainScreen : public Screen
{
public:  

    void set_number_of_tasks(int new_number_of_tasks);
    void set_number_records(int new_number_of_records);

    int get_number_of_tasks();
    int get_number_of_records();
    Date get_date();

protected:


private:
    Date local_data;
    int number_of_tasks;
    int number_of_records;
};


#endif