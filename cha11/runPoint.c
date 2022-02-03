#include <stdio.h>
#include <conio.h>
// #include "point.h"

int main()
{
    // CPoint2D cPoint2D= {s_pCPoint2DData,s_pCPoint2DFunc};
    // printf("Point2D x:%d\n",cPoint2D.pData->x);
    // printf("Point2D x:%d\n",e_getX(cPoint2D.pData));
    // printf("Point2D x:%d\n",cPoint2D.pFunc->getX(cPoint2D.pData));
    // initscr();
    // char c = getch();
    // endwin();
    
    char ch;
    while(ch != 27)
    {
    printf("Hello World\n");
        if(_kbhit()){
            ch = getch();
        }
        else
        {
        }
    }
    printf("End!\n");
    system("pause");
    return 0;
}