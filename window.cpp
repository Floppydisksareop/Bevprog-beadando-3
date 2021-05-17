#include "widgets.hpp"
#include "graphics.hpp"
#include "window.hpp"
#include <vector>
#include <fstream>

using namespace genv;

Window::Window (int X, int Y, std::vector<Widget*>& w) : _X(X), _Y(Y),widgets(w)
{
    gout.open(X,Y);
    focus = -1;
}


void Window::NewWidget(Widget* x)
{
    widgets.push_back(x);
}

void Window::DrawWidgets()
{
    for (Widget * w : widgets)
    {
        w->draw();
    }
    if(focus != -1)
    {
        widgets[focus]->draw();
    }
    gout << refresh;

}

void Window::ChangeFocus(event ev)
{
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->chosen(ev.pos_x, ev.pos_y))
                {
                    if(i!=focus && focus != -1)
                    {
                        widgets[focus]->focus_lost();
                    }
                    focus = i;
                }

            }
        }
        if(ev.keycode == key_tab && focus!=-1)
        {
            widgets[focus]->focus_lost();
            if(focus < widgets.size())
                focus++;
            if(focus == widgets.size())
                focus = 0;
        }
        if(ev.keycode == 's')
        {
            Write();
        }
}

void Window::ClearScreen()
{
    gout << color(0,0,0) << move_to(0,0) << box(_X,_Y);
}

void Window::Handler(event ev)
{
    if (focus!=-1)
    {
        widgets[focus]->handle(ev);
    }
}

void Window::Write()
{
    std::ofstream f;
    f.open("log.txt");
    for (Widget * w : widgets)
    {
        f << w->return_value() << " ";
    }
    f.close();
}

void Window::EventLoop()
{
    event ev;
    DrawWidgets();
    while(gin >> ev && ev.keycode != key_escape)
    {
        ChangeFocus(ev);
        Handler(ev);
        ClearScreen();
        DrawWidgets();
        gout << refresh;
    }
}

