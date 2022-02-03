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

// extern int e_getX(CPoint2DData *pData)
// {
//     return pData->x;
// }

// extern int e_getY(CPoint2DData *pData)
// {
//     return pData->y;
// }

void printH(){
    puts("H\n");
    return;
}
static void printS(){
    puts("S\n");
}
void printSs(){
    printS();
}