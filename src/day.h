#ifndef DAY
#define DAY

#include "Graph_lib/GUI.h"

class Day : public Graph_lib::Widget
{
public:
    
    Day(Graph_lib::Point xy, int w, int h, const std::string& s, Graph_lib::Callback cb,const int day_number);


protected:

    void day_callback(Graph_lib::Address pw, Graph_lib::Address ptr);

    void on_click();

private:
    
    int day_number;

};


#endif