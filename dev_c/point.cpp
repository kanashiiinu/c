#include <iostream>
#include "point.h"
int getX(CPoint2DData *pData)
{
    return pData->x;
}

int getY(CPoint2DData *pData)
{
    return pData->x;
}

static int s_getX(CPoint2DData *pData)
{
    return pData->x;
}

static int s_getY(CPoint2DData *pData)
{
    return pData->y;
}

extern int e_getX(CPoint2DData *pData)
{
    return pData->x;
}

extern int e_getY(CPoint2DData *pData)
{
    return pData->y;
}

static void printHello(){
	std::cout << "Hello" << std::endl;
}
void printH(){
	std::cout << "Hello" << std::endl;
}
static void prints(){
	std::cout << "static" << std::endl;
}
extern void printE(){
	std::cout << "extern" << std::endl;
}
