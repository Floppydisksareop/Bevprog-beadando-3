#include "graphics.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "number.hpp"
#include "window.hpp"
#include "text.hpp"
#include "sudoku_text.hpp"
#include <vector>
#include <fstream>
using namespace genv;
using namespace std;

const int X = 1000;
const int Y = 900;

class MyWindow:public Window
{
private:
    vector<Widget*> w;
    Sudoku * field;
    int StatusMatrix[9][9];
public:
    MyWindow():Window(X,Y,w)
    {
        ifstream f;
        f.open("board1.txt");
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                f >> StatusMatrix[i][j];
            }
        }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(StatusMatrix[i][j] == 0)
                    field = new Sudoku(10+j*X/11,10+i*Y/11,X/11,Y/11,true);
                else
                {
                    field = new Sudoku(10+j*X/11,10+i*Y/11,X/11,Y/11,false);
                    field->get_value(StatusMatrix[i][j]);
                }
                NewWidget(field);
            }
        }
    }
};

int main()
{
    vector<Widget*> w;
    MyWindow * First = new MyWindow();
    First->EventLoop();

    return 0;
}
