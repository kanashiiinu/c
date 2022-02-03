#include <iostream>
#include <stdio.h>
#include "point.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

extern void pH();
extern void pSs();
int main(int argc, char** argv) {
//	system("pause");
//	CPoint2D cPoint2D= {s_pCPoint2DData,s_pCPoint2DFunc};
//    printf("Point2D x:%d\n",cPoint2D.pData->x);
//    printf("Point2D x:%d\n",getX(cPoint2D.pData));
//    printf("Point2D x:%d\n",cPoint2D.pFunc->getX(cPoint2D.pData));
    printH();
//    printStatic();
    printE();
    printf("%d,%d\n",DAY,MONTH);
    pH(); 
    pSs();
	return 0;
}
