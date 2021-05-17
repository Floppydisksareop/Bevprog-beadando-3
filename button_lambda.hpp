#ifndef BUTTON_LAMBDA_HPP_INCLUDED
#define BUTTON_LAMBDA_HPP_INCLUDED

#include "widgets.hpp"
#include "button.hpp"
#include <functional>

class Button_L:public Button
{
private:
    std::function<void()> _action;
public:
    Button_L(int x, int y, int size_x, int size_y, std::string t, std::function<void()> action);

    virtual void handle(genv::event ev);
};

#endif // BUTTON_LAMBDA_HPP_INCLUDED
