#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>


class Text:public Widget
{
private:
    std::vector <std::string> _options;
    int _top, _chosen_option;
    size_t _nr, _nr_og;
    bool open;
public:
    Text(int x, int y, int sx, int sy, std::string options, size_t _nr);
    virtual bool chosen(int mouse_x, int mouse_y);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual std::string return_value();
    virtual void focus_lost();
    virtual void get_value(std::string new_value);
    virtual std::string lose_value();
};

#endif // TEXT_HPP_INCLUDED
