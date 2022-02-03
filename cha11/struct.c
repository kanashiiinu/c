#include<stdio.h>
typedef struct {
    int m_day;
    int m_month;
    int m_year;
    struct MyDateFunc * m_func;
}MyDate;



typedef struct MyDateFunc 
{
    int (*getMonth)(MyDate * pThis);
}MyDateFunc;

int getMonth(MyDate * pThis){
    return pThis->m_month;
}

static MyDateFunc s_myDateFunc = {&getMonth};
static MyDateFunc * s_pMyDateFunc = &s_myDateFunc;

typedef struct {
    int m_day;
    int m_month;
    int m_year; 
}MyDateData;

static MyDateData s_myDate = {0,0,0};
static MyDateData * s_pMyDate = &s_myDate;
typedef struct MyDateFuncC
{
    int (*getMonth)(MyDateData * pThis);
}MyDateFuncC;

int getMonthC(MyDateData * pThis){
    return pThis->m_month;
}
static MyDateFuncC s_myDateFuncC = {&getMonthC};
static MyDateFuncC * s_pMyDateFuncC = &s_myDateFuncC;
typedef struct {
    MyDateData * m_data;
    MyDateFuncC * m_func;
}MyDateClass;
typedef struct{
    char m_name[30];
    int m_num;
    MyDate m_birthday;
}MyStudent;

int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < argc; ++i)
    {
        puts(argv[i]);
    }
    MyDate myDate = {2, 6, 1999, &s_myDateFunc};
    printf("%d\n",myDate.m_func->getMonth(&myDate));

    MyDateClass myDateClass = {s_pMyDate, s_pMyDateFuncC};
    printf("%d\n",myDateClass.m_data->m_month);
    printf("%d\n",myDateClass.m_func->getMonth(myDateClass.m_data));
    MyStudent myStudent = {"ig", 8, {2, 6, 1999}};
    printf("Student %d\n", myStudent.m_num);
    printf("%.2f",23.5*240);
    return 0;
}