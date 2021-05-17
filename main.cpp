#include "graphics.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "number.hpp"
#include "window.hpp"
#include "text.hpp"
#include "button_lambda.hpp"
#include "button.hpp"
#include <vector>
using namespace genv;
using namespace std;

const int X = 600;
const int Y = 600;

class SmallWindow:public Window
{
private:
    Number * b2;
    Number * b1;
    Text * b3;
    Text * b4;
    Button_L * b5;
    Button_L * b6;
    Button * b7;
public:
    SmallWindow(int x, int y, vector<Widget*> w):Window(x,y,w)
    {
        b2 = new Number(220,10,100,30,30,-6);
        b1 = new Number(100,10,100,30,30,15);
        b3 = new Text(80,120,100,40,"one/two/three/four/five/six/seven/eight/",4);
        b4 = new Text(240,120,100,40,"egy/ketto/harom/negy/ot/hat/het/nyolc/",3);
        b5 = new Button_L(190,120,40,40,">",[&](){bal();});
        b6 = new Button_L(190,170,40,40,"<",[&](){jobb();});
        b7 = new Button(300,300,20,20,"asdf");

        NewWidget(b2);
        NewWidget(b3);
        NewWidget(b1);
        NewWidget(b4);
        NewWidget(b5);
        NewWidget(b6);
        NewWidget(b7);
    }
    void bal()
    {
        string temp;
        temp=b3->lose_value();
        b4->get_value(temp);
    }
    void jobb()
    {
        string temp;
        temp=b4->lose_value();
        b3->get_value(temp);
    }
};

int main()
{
    vector<Widget*> w;
    gout.open(X,Y);
    //Window * First = new Window (X,Y,w);
    SmallWindow * First = new SmallWindow(X,Y,w);
    First->EventLoop();

    return 0;
}
