#ifndef SUDOKU_TEXT_HPP_INCLUDED
#define SUDOKU_TEXT_HPP_INCLUDED

#include "number.hpp"
#include <functional>

class Sudoku:public Number
{
private:
    int _pos_x,_pos_y;
    bool _can_edit;
    bool _false;
    std::function<void()> _action;
public:
    Sudoku(int x, int y, int sx, int sy, int pos_x, int pos_y, bool edit, std::function<void()> action);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void set_value(int value);
    std::string return_value();
    virtual void False();
};

#endif // SUDOKU_TEXT_HPP_INCLUDED
