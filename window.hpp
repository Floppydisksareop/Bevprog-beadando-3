#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <vector>
#include "graphics.hpp"

class Window
{
public:
    int _X, _Y, focus;
    std::vector<Widget*>& widgets;
    Window(int X, int Y, std::vector<Widget*>& w);
    void NewWidget(Widget* x);
    void DrawWidgets();
    void ChangeFocus(genv::event ev);
    void ClearScreen();
    void Handler(genv::event ev);
    void EventLoop();
    void Write();

};

#endif // WINDOW_HPP_INCLUDED
