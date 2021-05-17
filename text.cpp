#include "graphics.hpp"
#include "text.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>

using namespace std;
using namespace genv;

Text::Text(int x, int y, int sx, int sy, string options, int nr) : Widget(x,y,sx,sy), _nr(nr)
{
    size_t i = 0;
    while (i < options.length())
    {
        if(options[i] == '/')
        {
            _options.push_back(options.substr(0,i));
            options.erase(options.begin(), options.begin()+i+1);
            i = 0;
        }
        else
            i++;
    }
    if(_nr > _options.size())
    {
        _nr = _options.size();
    }
    open = false;
    _top = 0;
    _chosen_option = 0;

}

bool Text::chosen(int mouse_x, int mouse_y)
{
    if(!open)
    {
        return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
    }
    else
    {
        return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y*(_nr+1);
    }
}

void Text::draw()
{
    gout << color(255,255,255) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(125,125,125) << move_to(_x+2,_y+2) << box(_size_x-4, _size_y-4);
    gout << color(255,255,255) << move_to(_x+3*_size_x/4, _y) << line(0,_size_y);
    gout << color(255,0,0) << move_to(_x+3*_size_x/4+4, _y+_size_y/2) << line_to(_x+7*_size_x/8, _y+3*_size_y/4);
    gout << color(255,0,0) << move_to(_x+_size_x-4,_y+_size_y/2) << line_to(_x+7*_size_x/8, _y+3*_size_y/4);
    gout << color(255,0,0) << move_to(_x+4, _y+_size_y/2) << text(_options[_chosen_option]);
    if(open)
    {
        for (int i = 1; i <= _nr; i++)
        {
            gout << color(255, 255, 255) << move_to(_x, _y+i*_size_y) << box(7*_size_x/8,_size_y);
            gout << color(125,125,125) << move_to(_x+2,_y+i*_size_y+2) << box(7*_size_x/8-4, _size_y-4);
            gout << color(255,0,0) << move_to(_x+4, _y+_size_y*i+_size_y/2) << text(_options[_top+i-1]);
        }
    }
}

void Text::handle(event ev)
{
    if(open)
    {
        if(ev.type == ev_mouse)
        {
            if(ev.button == btn_wheelup && _top > 0)
            {
                _top--;
            }
            if(ev.button == btn_wheeldown && _top+_nr < _options.size())
            {
                _top++;
            }
            if(ev.button == btn_left)
            {
                for(int i = 1; i <= _nr; i++)
                {
                    if(ev.pos_x >= _x && ev.pos_x <= _x+7*_size_x/8 && ev.pos_y >= _y+_size_y*i && ev.pos_y <= _y+_size_y*(i+1))
                    {
                        _chosen_option = _top+i-1;
                        break;
                    }
                }
                open = false;
            }
        }
    }
    else
    {
        if(ev.type == ev_mouse && ev.button == btn_left && ev.pos_x >= _x && ev.pos_x <= _x+_size_x && ev.pos_y >= _y && ev.pos_y <= _y+_size_y)
        {
            open = true;
        }

    }

}

string Text::return_value()
{
    return _options[_chosen_option];
}

void Text::focus_lost()
{
    open=false;
}
