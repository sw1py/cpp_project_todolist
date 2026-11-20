#ifndef SCREEN
#define SCREEN

//Базовый класс для наших будущих экранов

#include "Graph_lib/Window.h"

class Screen
{
public:
    
    virtual ~Screen() = default;

    virtual void attach_to(Graph_lib::Window& win) = 0;
    virtual void detach_from(Graph_lib::Window& win) = 0;
    
    virtual void refresh();

protected:

    Graph_lib::Window* win = nullptr;
};


#endif