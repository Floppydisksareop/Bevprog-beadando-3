#ifndef SUDOKU_TEXT_HPP_INCLUDED
#define SUDOKU_TEXT_HPP_INCLUDED

#include "number.hpp"

class Sudoku:public Number
{
private:
    bool _can_edit;
public:
    Sudoku(int x, int y, int sx, int sy,bool edit);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void get_value(int value);
};

#endif // SUDOKU_TEXT_HPP_INCLUDED
