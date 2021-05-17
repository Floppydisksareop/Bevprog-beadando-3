#include "sudoku_text.hpp"
#include <sstream>

using namespace genv;

Sudoku::Sudoku(int x, int y, int sx, int sy, int pos_x, int pos_y, bool edit,std::function<void()> action):Number(x,y,sx,sy,9,0), _pos_x(pos_x), _pos_y(pos_y), _can_edit(edit), _action(action)
{
    _false = false;
}

void Sudoku::draw()
{
    if(!_false)
    {
        if(!_can_edit)
        {
            gout << color(255,255,255) << move_to(_x,_y) << box(_size_x, _size_y) << color(125,125,125) << move_to(_x+2,_y+2) << box(_size_x-4, _size_y-4);
            std::stringstream ss;
            ss << _value;
            gout << color(255,255,255) << move_to(_x+_size_x/2,_y+_size_y/2)<<text(ss.str());
        }
        else
        {
            gout << color(255,255,255) << move_to(_x,_y) << box(_size_x, _size_y) << color(125,125,125) << move_to(_x+2,_y+2) << box(_size_x-4, _size_y-4) << color(255,255,255) << move_to(_x+_size_x/3, _y) << line(0,_size_y) << move_to(_x+2*_size_x/3,_y) << line(0,_size_y);
            gout << move_to(_x+4, _y+_size_y/2) << color(0,255,0) << text("-");
            move_to(_x+_size_x/4+2, _y+_size_y/2);
            if(_value != 0)
            {
                std::stringstream ss;
                ss << _value;
                gout << move_to(_x+_size_x/2,_y+_size_y/2) << text(ss.str()) <<move_to(_x+3*_size_x/4+4, _y+_size_y/2) << text("+");
            }
            else
            {
                gout <<move_to(_x+3*_size_x/4+4, _y+_size_y/2) << text("+");
            }
        }
    }
    if(_false)
    {
        if(!_can_edit)
        {
            gout << color(255,255,255) << move_to(_x,_y) << box(_size_x, _size_y) << color(255,0,0) << move_to(_x+2,_y+2) << box(_size_x-4, _size_y-4);
            std::stringstream ss;
            ss << _value;
            gout << color(255,255,255) << move_to(_x+_size_x/2,_y+_size_y/2)<<text(ss.str());
        }
        else
        {
            gout << color(255,255,255) << move_to(_x,_y) << box(_size_x, _size_y) << color(255,0,0) << move_to(_x+2,_y+2) << box(_size_x-4, _size_y-4) << color(255,255,255) << move_to(_x+_size_x/3, _y) << line(0,_size_y) << move_to(_x+2*_size_x/3,_y) << line(0,_size_y);
            gout << move_to(_x+4, _y+_size_y/2) << color(0,255,0) << text("-");
            move_to(_x+_size_x/4+2, _y+_size_y/2);
            if(_value != 0)
            {
                std::stringstream ss;
                ss << _value;
                gout << move_to(_x+_size_x/2,_y+_size_y/2) << text(ss.str()) <<move_to(_x+3*_size_x/4+4, _y+_size_y/2) << text("+");
            }
            else
            {
                gout <<move_to(_x+3*_size_x/4+4, _y+_size_y/2) << text("+");
            }
        }
    }
}

void Sudoku::handle(genv::event ev)
{
    if(_can_edit)
    {
        if(ev.type == genv::ev_key && ev.keycode == genv::key_pgdn)
        {
            if(_value>=_int_bottom+10)
            {
                _value = _value-10;
                _action();
            }
            else
            {
                _value = _int_bottom;
                _action();
            }
        }
        if(ev.type == genv::ev_key && ev.keycode == genv::key_pgup)
        {
            if(_value<=_int_top-10)
            {
                _value = _value+10;
                _action();
            }
            else
            {
                _value = _int_top;
                _action();
            }
        }
        if((ev.type == genv::ev_key && ev.keycode == genv::key_up) ||\
        (ev.type == genv::ev_mouse && ev.button == genv::btn_left &&\
        ev.pos_x >= _x+((3*_size_x)/4) && ev.pos_x <= _x+_size_x && ev.pos_y >= _y && ev.pos_y <= _y+_size_y))
        {
            if(_value < _int_top)
            {
                _value++;
                _action();
            }
        }
        if((ev.type == genv::ev_key && ev.keycode == genv::key_down) ||\
        (ev.type == genv::ev_mouse && ev.button == genv::btn_left &&\
        ev.pos_x <= _x+_size_x/4 && ev.pos_x >= _x && ev.pos_y >= _y && ev.pos_y <= _y+_size_y))
        {
            if(_value > _int_bottom)
            {
                _value--;
                _action();
            }
        }

    }
}

void Sudoku::set_value(int value)
{
    _value = value;
}

void Sudoku::False()
{
    _false = true;
}

void Sudoku::NotFalse()
{
    _false = false;
}

std::string Sudoku::return_value()
{
    std::stringstream ss;
    ss<<_value;
    return ss.str();
}
