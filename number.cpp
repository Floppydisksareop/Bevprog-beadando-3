#include "graphics.hpp"
#include "widgets.hpp"
#include "number.hpp"
#include <sstream>
#include <string>

using namespace genv;

Number::Number(int x, int y, int sx, int sy, int top, int bottom):Widget(x,y,sx,sy), _int_top(top), _int_bottom(bottom)
{
    _value = bottom;
}

std::string Number::return_value()
{
    std::stringstream ss;
    ss << _value;
    return ss.str();
}

void Number::draw()
{
    gout << color(255,255,255) << move_to(_x,_y) << box(_size_x, _size_y) << color(125,125,125) << move_to(_x+2,_y+2) << box(_size_x-4, _size_y-4) << color(255,255,255) << move_to(_x+_size_x/4, _y) << line(0,_size_y) << move_to(_x+3*_size_x/4,_y) << line(0,_size_y);
    gout << move_to(_x+4, _y+_size_y/2) << color(255,0,0) << text("-");
    move_to(_x+_size_x/4+2, _y+_size_y/2);
    std::stringstream ss;
    ss << _value;
    gout << move_to(_x+_size_x/4+4,_y+_size_y/2) << text(ss.str()) <<move_to(_x+3*_size_x/4+4, _y+_size_y/2) << text("+");
}

void Number::handle(genv::event ev)
{
    if(ev.type == genv::ev_key && ev.keycode == genv::key_pgdn)
    {
        if(_value>=_int_bottom+10)
            _value = _value-10;
        else
            _value = _int_bottom;
    }
    if(ev.type == genv::ev_key && ev.keycode == genv::key_pgup)
    {
        if(_value<=_int_top-10)
            _value = _value+10;
        else
            _value = _int_top;
    }
    if((ev.type == genv::ev_key && ev.keycode == genv::key_up) ||\
    (ev.type == genv::ev_mouse && ev.button == genv::btn_left &&\
    ev.pos_x >= _x+((3*_size_x)/4) && ev.pos_x <= _x+_size_x && ev.pos_y >= _y && ev.pos_y <= _y+_size_y))
    {
        if(_value < _int_top)
        {
            _value++;
        }
    }
    if((ev.type == genv::ev_key && ev.keycode == genv::key_down) ||\
    (ev.type == genv::ev_mouse && ev.button == genv::btn_left &&\
    ev.pos_x <= _x+_size_x/4 && ev.pos_x >= _x && ev.pos_y >= _y && ev.pos_y <= _y+_size_y))
    {
        if(_value > _int_bottom)
        {
            _value--;
        }
    }
}
