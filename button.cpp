#include "graphics.hpp"
#include "button.hpp"
#include <string>

Button::Button(int x, int y, int size_x, int size_y, std::string t) : Widget(x,y,size_x, size_y), _btext(t)
{
    _pressed = false;
};

void Button::draw()
{
    if(!_pressed)
        genv::gout << genv::color(255,255,255) << genv::move_to(_x,_y) << genv::box(_size_x, _size_y) << genv::color(125,125,125) << genv::move_to(_x+2,_y+2) << genv::box(_size_x-4, _size_y-4) << genv::move_to(_x+_size_x/15,_y+(_size_y/2)) << genv::color(255,255,255) << genv::text(_btext);
    if(_pressed)
        genv::gout << genv::color(255,255,255) << genv::move_to(_x-1,_y-1) << genv::box(_size_x-1, _size_y-1) << genv::color(100,100,100) << genv::move_to(_x+1,_y+1) << genv::box(_size_x-5,_size_y-5) << genv::move_to(_x+_size_x/15-1,_y+(_size_y)/2-1) << genv::color(255,255,255) << genv::text(_btext);
}

void Button::handle(genv::event ev)
{
    if (!_pressed && ev.type == genv::ev_mouse && chosen(ev.pos_x, ev.pos_y) && ev.button==genv::btn_left)
    {
        _pressed = true;
    }
    if(_pressed && ev.type == genv::ev_mouse && chosen(ev.pos_x, ev.pos_y) && ev.button==-genv::btn_left)
    {
        _pressed = false;
    }
    if(_pressed && !chosen(ev.pos_x, ev.pos_y) && ev.button==-genv::btn_left)
    {
        _pressed = false;
    }
}

void Button::focus_lost()
{
    _pressed = false;
}

bool Button::is_pressed()
{
    return _pressed;
}

std::string Button::return_value()
{
    return "";
}
