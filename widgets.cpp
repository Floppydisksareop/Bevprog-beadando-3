#ifndef WIDGETS_CPP_INCLUDED
#define WIDGETS_CPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace std;

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

void Widget::get_value(string new_value)
{

}

string Widget::lose_value()
{
    return "";
}

#endif // WIDGETS_CPP_INCLUDED
