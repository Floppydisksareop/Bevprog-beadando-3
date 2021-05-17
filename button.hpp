#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Button: public Widget
{
protected:
    bool _pressed;
    std::string _btext;
public:
    Button(int x, int y, int size_x, int size_y, std::string t);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual bool is_pressed();
    virtual std::string return_value();
};


#endif // BUTTON_HPP_INCLUDED
