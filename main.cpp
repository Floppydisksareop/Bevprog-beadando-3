#include "graphics.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "number.hpp"
#include "window.hpp"
#include "text.hpp"
#include "sudoku_text.hpp"
#include "button.hpp"
#include "button_lambda.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace genv;
using namespace std;

const int X = 1000;
const int Y = 900;

class MyWindow:public Window
{
private:
    vector<Widget*> w;
    vector<Sudoku*> su;
    Sudoku * field;
    int StatusMatrix[9][9];
    Button_L * Check;
    Text * Menu;
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
                    field = new Sudoku(10+j*X/15+10*(j/3),10+i*Y/15+10*(i/3),X/15,Y/15,j,i,true,[this, i,j](){SetMatrix(i,j);});
                else
                {
                    field = new Sudoku(10+j*X/15+10*(j/3),10+i*Y/15+10*(i/3),X/15,Y/15,j,i,false,[this, i, j](){SetMatrix(i,j);});
                    field->set_value(StatusMatrix[i][j]);
                }
                su.push_back(field);
                NewWidget(field);
            }
        }
        Check = new Button_L(10,10*Y/11,X/11,Y/11,"Submit",[&](){Check_field();});
        NewWidget(Check);
    }
    void SetMatrix(int x, int y)
    {
        stringstream ss;
        ss << su.at(x*9+y)->return_value();
        int value;
        ss >> value;
        cout << value;
        StatusMatrix[x][y] = value;
    }
    void Check_field()
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                su.at(i*9+j)->NotFalse();
            }
        }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                for(int k = j+1; k < 9; k++)
                {
                    if(StatusMatrix[i][j] == StatusMatrix[i][k])
                    {
                        su.at(i*9+j)->False();
                        su.at(i*9+k)->False();
                    }
                }
            }
        }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                for(int k = j+1; k < 9; k++)
                {
                    if(StatusMatrix[j][i] == StatusMatrix[k][i])
                    {
                        su.at(j*9+i)->False();
                        su.at(k*9+i)->False();
                    }
                }
            }
        }
        for(int ii = 0; ii < 3; ii++)
        {
            for(int jj = 0; jj < 3; jj++)
            {
                for(int i = 0; i < 8; i++)
                {
                    for(int j = i+1; j < 9; j++)
                    {
                        if(StatusMatrix[ii*3+(i/3)][jj*3+(i%3)] == StatusMatrix[ii*3+(j/3)][jj*3+(j%3)])
                        {
                            su.at((ii*3+(i/3))*9+jj*3+(i%3))->False();
                            su.at((ii*3+(j/3))*9+jj*3+(j%3))->False();
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(StatusMatrix[i][j]==0)
                    su.at(i*9+j)->False();
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
