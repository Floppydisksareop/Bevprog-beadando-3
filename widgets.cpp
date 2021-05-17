#ifndef WIDGETS_CPP_INCLUDED
#define WIDGETS_CPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

Widget::Widget(int x, int y, int sx, int sy): _x(x), _y(y), _size_x(sx), _size_y(sy)
{

}

bool Widget::chosen(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::focus_lost()
{

}

#endif // WIDGETS_CPP_INCLUDED
