#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Number : public Widget
{
protected:
    int _int_top, _int_bottom, _value;
public:
    Number(int x, int y, int sx, int sy, int top, int bottom);
    virtual std::string return_value();
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // NUMBER_HPP_INCLUDED
