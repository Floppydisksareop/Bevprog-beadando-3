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
    int _top, _nr, _chosen_option;
    bool open;
public:
    Text(int x, int y, int sx, int sy, std::string options, int _nr);
    virtual bool chosen(int mouse_x, int mouse_y);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual std::string return_value();
    virtual void focus_lost();
};

#endif // TEXT_HPP_INCLUDED
