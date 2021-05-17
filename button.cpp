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
        genv::gout << genv::color(200,200,200) << genv::move_to(_x,_y) << genv::box(_size_x, _size_y) << genv::move_to(_x+2/2,_y+(_size_y/2)) << genv::color(0,0,0) << genv::text(_btext);
    if(_pressed)
        genv::gout << genv::color(150,150,150) << genv::move_to(_x-1,_y-1) << genv::box(_size_x-1,_size_y-1) << genv::move_to(_x+2/2,_y+(_size_y/2)-1) << genv::color(0,0,0) << genv::text(_btext);
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
}

bool Button::is_pressed()
{
    return _pressed;
}

std::string Button::return_value()
{

}
