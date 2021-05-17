#include "button_lambda.hpp"

using namespace std;
using namespace genv;

Button_L::Button_L(int x, int y, int size_x, int size_y, std::string t, function<void()>action):Button(x,y,size_x,size_y,t),_action(action)
{

}

void Button_L::handle(genv::event ev)
{
    if (!_pressed && ev.type == genv::ev_mouse && chosen(ev.pos_x, ev.pos_y) && ev.button==genv::btn_left)
    {
        _pressed = true;
    }
    if(_pressed && ev.type == genv::ev_mouse && chosen(ev.pos_x, ev.pos_y) && ev.button==-genv::btn_left)
    {
        _action();
        _pressed = false;
    }
    if(_pressed && !chosen(ev.pos_x, ev.pos_y) && ev.button==-genv::btn_left)
    {
        _pressed = false;
    }
}

