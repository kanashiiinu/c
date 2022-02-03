#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <stdarg.h>

#define CONTINUE_RUN true
#define DEFAULT_OPERATE_NUM 1
#define DEFAULT_INPUT_COMMAND_LEN 50
#define STUDENT_SCORE_DATA_FILE "StudentScoreData.txt"
#define WAITING_MSG "waiting ..."
#define OPEN_DATA_FILE_FAILED "can not openStudentScoreDate"
#define CONTINUE_OPERATE_MSG "press any key to continue ..."
#define NO_DATA "No Data!"

enum OperateReturn
{
    NO,
    YES,
    OTHERS,
    ILLEGAL
};

typedef struct Student
{
    int id;
    char name[20];
    float elective;
    float experiment;
    float required;
    float totalScore;
} Student;

typedef struct
{
    struct Student *pStudent;
    bool inMemory;
    int totalStudentNum;
} ProgmaInstance;

Student stu[10000];
ProgmaInstance progmaInstance;
ProgmaInstance *pProgmaInstance = &progmaInstance;

float l_elective = 0.50f;
float l_experiment = 0.25f;
float l_required = 0.25f;

void ReSetProgmaInstance(ProgmaInstance *l_pProgmaInstance, Student *pStudent, bool inMemory, int totalStudentNum);
bool ReadAllInToMemory(ProgmaInstance *l_pProgmaInstance);
FILE *GetFileStream(char *filename, char *mode);
void PrintTotalNum();
bool PrepareProgramInstance();
typedef bool (*ControlCondition)(char *);
typedef bool (*InnerHander)(ProgmaInstance *, char *, int);
bool TemplateProcess(
    InnerHander inlineHander,
    char *refMsg,
    ControlCondition doCondition,
    ControlCondition endCondition);
bool TemplateOperateByYesOrNo(InnerHander innerHander, char *refMsg);
bool ShowOneStudentScore(Student *pStudent);
void StudentPrintInfo(Student *pStudent);

bool IsY(char *input)
{
    if ((strcmp(input, "y") == 0) || (strcmp(input, "Y") == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsN(char *input)
{
    if ((strcmp(input, "n") == 0) || (strcmp(input, "N") == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsInt(char *input, int n)
{
    if ('\0' == input[0])
    {
        return false;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                continue;
            }
            else if (input[i] == '\0')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool IsId(char *input)
{
    return IsInt(input, DEFAULT_INPUT_COMMAND_LEN);
}

bool IsExit(char *input)
{
    if ((strcmp(input, "exit") == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ShowMenu()
{
    system("cls");
    printf_s("\n\n\n\n\n");
    printf_s("\t|--------STUDENT--------|\n");
    printf_s("\t|\t0: exit         |\n");
    printf_s("\t|\t1: intput record|\n");
    printf_s("\t|\t2: search record|\n");
    printf_s("\t|\t3: delete record|\n");
    printf_s("\t|\t4: modify record|\n");
    printf_s("\t|\t5: insert record|\n");
    printf_s("\t|\t6: Order        |\n");
    printf_s("\t|\t7: number       |\n");
    printf_s("\t|-----------------------|\n\n");
    printf_s("\tchoose(0-7):");
}

FILE *GetFileStream(char *filename, char *mode)
{
    FILE *fileStream = NULL;
    errno_t err = fopen_s(&fileStream, filename, mode);
    if (err == 0)
    {
        return fileStream;
    }
    else
    {
        return NULL;
    }
}

int GetCurrentTotalRecords()
{
    int totalStuNum = -1;
    if (pProgmaInstance->inMemory)
    {
        totalStuNum = pProgmaInstance->totalStudentNum;
    }
    else
    {
        ReadAllInToMemory(pProgmaInstance);
        totalStuNum = pProgmaInstance->totalStudentNum;
    }
    return totalStuNum;
}

void ShowRecords()
{
    PrintTotalNum();
    int totalStudentNum = GetCurrentTotalRecords();
    Student * pStudent = pProgmaInstance->pStudent;
    for (int i = 0; i < totalStudentNum; ++i, ++pStudent){
        StudentPrintInfo(pStudent);
    }
    getch();
}

int InputYesOrNo(char *refMsg)
{
    char*intput[DEFAULT_INPUT_COMMAND_LEN];
    return ProcessControl(refMsg,intput,DEFAULT_INPUT_COMMAND_LEN,IsY,IsN);
}

void UpdateLByStd()
{
    printf_s("please intput per centnum:");
    printf_s("\nelective:");
    scanf("%f", &l_elective);
    printf_s("\nexperiment:");
    scanf("%f", &l_experiment);
    printf_s("\nrequired course:");
    scanf("%f", &l_required);
}

bool TemplateInnerUpdateL(ProgmaInstance *l_pProgmaInstance,char *input, int n)
{
    UpdateLByStd();
    return true;
}

#define IF_UPDATE_L_MSG "if need update l, please input (y/n): "
bool UpdateL()
{
    TemplateOperateByYesOrNo(TemplateInnerUpdateL, IF_UPDATE_L_MSG);
    return true;
}

float StudentComputeSum(Student *pStudent)
{
    pStudent->totalScore = pStudent->elective * l_elective + pStudent->experiment * l_experiment + pStudent->required * l_required;
    return pStudent->totalScore;
}

Student *InputStudentByStd(Student *pStudent)
{
    printf_s("name:");
    scanf("%s", pStudent->name);
    printf_s("elective:");
    scanf("%f", &(pStudent->elective));
    printf_s("experiment:");
    scanf("%f", &(pStudent->experiment));
    printf_s("required:");
    scanf("%f", &(pStudent->required));
    StudentComputeSum(pStudent);
    return pStudent;
}

bool WriteOneStudentToFile(Student *pStudent)
{
    PrepareProgramInstance();
    bool fileWriteSuccess = false;
    FILE *fileStream = GetFileStream(STUDENT_SCORE_DATA_FILE, "a");
    if(fileStream != NULL){
        fileWriteSuccess = fwrite(pStudent, sizeof(Student), DEFAULT_OPERATE_NUM, fileStream) == DEFAULT_OPERATE_NUM;
        fclose(fileStream);
        pProgmaInstance->totalStudentNum += 1;
        fileWriteSuccess = true;
    }else{
        fileWriteSuccess = false;
    }
    return fileWriteSuccess;
}

bool IsStudentNoSame(int studentNo)
{
    int totalStuNum = GetCurrentTotalRecords();
    for (int i = 0; i < totalStuNum; i++)
    {
        if (stu[i].id == studentNo)
        {
            return true;
        }
        else
        {
        }
    }
    return false;
}

bool GetStudentAllInfoByStd(){
    printf_s("number:");
    int studentNo = -1;
    scanf("%d", &studentNo);
    bool isNoSame = false;
    if (IsStudentNoSame(studentNo))
    {
        isNoSame = false;
    }
    else
    {
        isNoSame = true;
    }
    if(isNoSame){
        Student *pStudent = pProgmaInstance->pStudent + pProgmaInstance->totalStudentNum;
        InputStudentByStd(pStudent);
    }
}

void WriteStudentInFile()
{
    printf_s("number:");
    int studentNo = -1;
    scanf("%d", &studentNo);
    if (IsStudentNoSame(studentNo))
    {
        printf_s("student.NO is existing\n");
        getch();
    }
    else
    {
        Student *pStudent = pProgmaInstance->pStudent + pProgmaInstance->totalStudentNum;
        InputStudentByStd(pStudent);
        if (WriteOneStudentToFile(pStudent))
        {
            printf_s("%s saved successfully\n", pStudent->name);
        }
        else
        {
            printf_s("save failed!");
        }
        getch();
    }
}

bool TemplateInnerContinueAddStudent(ProgmaInstance *l_pProgmaInstance, char* input, int n)
{
    WriteStudentInFile();
    return true;
}

#define IF_CONTINUE_OPERATE_MSG "continue?(y/n):"
bool ContinueAddStudent()
{
    TemplateOperateByYesOrNo(TemplateInnerContinueAddStudent, IF_CONTINUE_OPERATE_MSG);
    return true;
}

bool TemplateInnerAddStudent(ProgmaInstance *l_pProgmaInstance, char * input, int n){
    WriteStudentInFile();
    ContinueAddStudent();
    return true;
}

#define IF_ADD_STUDENT "add student, please input (y/n): "
bool AddStudent()
{
    TemplateOperateByYesOrNo(TemplateInnerAddStudent,IF_ADD_STUDENT);
    return true;
}

bool TemplateOperateByYesOrNo(InnerHander innerHander, char *refMsg)
{
    return TemplateProcess(innerHander, refMsg, IsY, IsN);
}

bool TemplateInnerSeeAllStudentScore(ProgmaInstance *l_pProgmaInstance, char* input, int n)
{
    system("cls");
    ShowRecords();
    return true;
}

bool SeeAllStudentScore()
{
    TemplateOperateByYesOrNo(TemplateInnerSeeAllStudentScore, "do you want to see current students score (y/n)? ");
}

bool InputStudent()
{
    PrepareProgramInstance();
    SeeAllStudentScore();
    UpdateL();
    AddStudent();
    printf_s("OK!\n");
    return CONTINUE_RUN;
}

void StudentPrintInfo(Student *pStudent){
    printf_s("%6d %20s %6.2f %6.2f %6.2f %6.2f\n",
                pStudent->id,
                pStudent->name,
                pStudent->elective,
                pStudent->experiment,
                pStudent->required,
                pStudent->totalScore);
}

bool ShowOneStudentScore(Student *pStudent)
{
    while (true)
    {
        int operateReturn = InputYesOrNo("see the student score (y/n) :");
        if (operateReturn == YES)
        {
            StudentPrintInfo(pStudent);
        }
        else if (operateReturn == NO)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return true;
}

int GetStudentIndexById(int studentNo)
{
    if (!pProgmaInstance->inMemory)
    {
        ReadAllInToMemory(pProgmaInstance);
    }
    else
    {
    }
    Student *pStudent = pProgmaInstance->pStudent;
    int totalStudentNum = GetCurrentTotalRecords();
    for (int i = 0; i < totalStudentNum; ++i, ++pStudent)
    {
        if (studentNo == pStudent->id)
        {
            return i;
        }
        else
        {
        }
    }
    return -1;
}

Student *SelectOneStudentById(int studentNo)
{
    int totalStudentNum = GetCurrentTotalRecords();
    int studentIndex = GetStudentIndexById(studentNo);
    if (studentIndex >= 0 && studentIndex < totalStudentNum)
    {
        return pProgmaInstance->pStudent + studentIndex;
    }
    else
    {
        return NULL;
    }
}


bool GetIntFormatInput(int *pInt, char *cStr, int n)
{
    bool beInt = IsInt(cStr, n);
    if (beInt)
    {
        *pInt = atoi(cStr);
    }
    else
    {
    }
    return beInt;
}

bool TemplateInnerSearchStudent(ProgmaInstance *l_pProgmaInstance, char *inputCStr, int n)
{
    int studentNo = atoi(inputCStr);
    int studentIndex = GetStudentIndexById(studentNo);
    if (studentIndex != -1)
    {
        Student *pStudent = pProgmaInstance->pStudent + studentIndex;
        ShowOneStudentScore(pStudent);
    }
    else
    {
        printf_s("there is no record with id %d\n", studentNo);
    }
    return true;
}


int ProcessControl(char *refMsg, char *inputCStr, int n, ControlCondition doCondition, ControlCondition endCondition)
{
    // 提示功能
    printf_s(refMsg);
    // 接收控制台输入
    scanf("%s", inputCStr);
    // 流程分支 YES执行 NO结束 OTHERS不合标准的输入 ILL非法
    if (doCondition(inputCStr))
    {
        // 执行条件
        return YES;
    }
    else if (endCondition(inputCStr))
    {
        // 结束条件
        return NO;
    }
    else
    {
        // 不符合要求的输入
        return OTHERS;
    }
}

bool TemplateProcess(
    InnerHander inlineHander,
    char *refMsg,
    ControlCondition doCondition,
    ControlCondition endCondition)
{
    while (true)
    {
        char inputCStr[DEFAULT_INPUT_COMMAND_LEN];
        int operateReturn = ProcessControl(
            refMsg,
            inputCStr,
            DEFAULT_INPUT_COMMAND_LEN,
            doCondition,
            endCondition);
        if (YES == operateReturn)
        {
            inlineHander(pProgmaInstance, inputCStr, DEFAULT_INPUT_COMMAND_LEN);
            break;
        }
        else if (NO == operateReturn)
        {
            break;
        }
        else
        {
            printf_s("check your input '%s', please\n", inputCStr);
            continue;
        }
    }
    return true;
}
#define SEARCH_BY_ID "search: input student.NO to find he/she\n"
bool SearchStudent()
{
    TemplateProcess(TemplateInnerSearchStudent, SEARCH_BY_ID, IsId, IsExit);
    return true;
}

bool DeleteStudentInMemory(Student *pStudent)
{
    *pStudent = (pProgmaInstance->pStudent[pProgmaInstance->totalStudentNum - 1]);
    pProgmaInstance->totalStudentNum -= 1;
    return true;
}

bool PrepareProgramInstance()
{
    if (!pProgmaInstance->inMemory)
    {
        ReadAllInToMemory(pProgmaInstance);
    }
    else
    {
    }
    return true;
}

bool InlineSaveAllStudentToFile()
{
    Student *pStudent = pProgmaInstance->pStudent;
    int totalStudentNum = GetCurrentTotalRecords();
    FILE *fileStream = GetFileStream(STUDENT_SCORE_DATA_FILE, "w+");
    if(fileStream != NULL){
        for (int i = 0; i < totalStudentNum; ++i, ++pStudent)
        {
            fwrite(pStudent, sizeof(Student), DEFAULT_OPERATE_NUM, fileStream);
        }
        fclose(fileStream);
        return true;
    }else{
        return false;
    }
}

/*举个例子
bool Pre(OperationFunc opF,...){
    va_list arg_ptr;
    va_start(arg_ptr, opF);
    ProgmaInstance * l_pProgmaInstance = va_arg(arg_ptr,ProgmaInstance *);
    if(!pProgmaInstance->inMemory){
        ReadAllInToMemory(pProgmaInstance);
    }else{
        opF(l_pProgmaInstance);
    }
    va_end(arg_ptr);
};
*/

bool SaveAllStudentsToFile()
{
    PrepareProgramInstance();
    return InlineSaveAllStudentToFile();
}

bool TemplateInnerDeleteStudent(ProgmaInstance *l_pProgmaInstance, char * input, int n){
    int studentNo = atoi(input);
    int studentIndex = GetStudentIndexById(studentNo);
    if (studentIndex != -1)
    {
        Student *pStudent = pProgmaInstance->pStudent + studentIndex;
        DeleteStudentInMemory(pStudent);
        if(SaveAllStudentsToFile()){
            printf_s("delete %s successfully\n", pStudent->name);
        }else{
            printf_s("delete %s failed!\n",pStudent->name);
        }
    }
    else
    {
        printf_s("there is no record with id %d\n", studentNo);
    }
    getch();
    return true;
}

#define DELETE_STUDENT_MSG "delete: input student.NO to delete he/she\n"
bool DeleteStudent()
{
    TemplateProcess(TemplateInnerDeleteStudent, DELETE_STUDENT_MSG, IsId, IsExit);
    return true;
}

bool TemplateInnerModifyStudent(ProgmaInstance *l_pProgmaInstance, char * input, int n){
    return true;
}
#define MODIFY_STUDENT_MSG "modify: input student.NO to modify he/she\n"
bool TemplateInnerUpdateStudentByStd(ProgmaInstance *l_pProgmaInstance, char * input, int n){
    int studentNo = atoi(input);
    int studentIndex = GetStudentIndexById(studentNo);
    if( studentIndex != -1){
        // 被修改的学生
        Student *pStudent = pProgmaInstance->pStudent + studentIndex;
        InputStudentByStd(pStudent);
        if(SaveAllStudentsToFile()){ 
            printf_s("modify %s successfully\n",pStudent->name);
        }
        else
        {
            printf_s("modify %s failed!\n",pStudent->name);
        }
    }else{
        printf_s("there is no record with id %d\n", studentNo);
    }
    getch();
    return true;
}

bool UpdateStudentByStd(){
    TemplateProcess(TemplateInnerUpdateStudentByStd,MODIFY_STUDENT_MSG, IsId, IsExit);
    return true;
}

bool ModifiedStudent()
{
    PrepareProgramInstance();
    SeeAllStudentScore();
    UpdateL();
    UpdateStudentByStd();
    return true;
}

bool InsertStudentByStd(Student *pStudent){
    GetStudentAllInfoByStd();
    Student* pLastStudent = pProgmaInstance->pStudent + pProgmaInstance->totalStudentNum;
    Student oldStudent = *pLastStudent;
    *pLastStudent = *pStudent;
    *pStudent = oldStudent;
    pProgmaInstance->totalStudentNum += 1;
    return true;
}

bool TemplateInnerInsertStudentByStd(ProgmaInstance *l_pProgmaInstance, char * input, int n){
    int studentNo = atoi(input);
    int studentIndex = GetStudentIndexById(studentNo);
    if(studentIndex != -1){
        Student *pStudent = pProgmaInstance->pStudent + studentIndex;
        InsertStudentByStd(pStudent);
        if(SaveAllStudentsToFile()){
            printf_s("success");
        }else{
            printf_s("failed");
        }
    }else{
        printf_s("no record");
    }
    return true;
}
#define INSERT_STUDENT_MSG "insert: input student.NO to add he/she\n" 
bool InsertStudentByStdSysFunc(){
    TemplateProcess(TemplateInnerInsertStudentByStd,INSERT_STUDENT_MSG, IsId, IsExit);
    return true;
}

bool InsertStudent()
{
    PrepareProgramInstance();
    SeeAllStudentScore();
    UpdateL();
    InsertStudentByStdSysFunc();
    return true;
}

bool OrderStudent()
{
    return true;
}

void PrintTotalNum()
{
    int totalStudentNum = GetCurrentTotalRecords();
    if (totalStudentNum == 0)
    {
        printf_s("%s\n", NO_DATA);
    }
    else if (totalStudentNum == 1)
    {
        printf_s("There is only %d student in class\n", totalStudentNum);
    }
    else
    {
        printf_s("There are %d students in class\n", totalStudentNum);
    }
}

bool GetTotalStudentsNum()
{
    PrepareProgramInstance();
    PrintTotalNum();
    SeeAllStudentScore();
    return true;
}

bool Exit()
{
    return false;
}
bool ReInputOperator()
{
    printf_s("\nerror input : input operator ID again, please\n");
    return true;
}

bool ReadAllInToMemory(ProgmaInstance *l_pProgmaInstance)
{
    int totalStuNum = 0;
    FILE *fileStream = GetFileStream(STUDENT_SCORE_DATA_FILE, "r");
    if (fileStream != NULL)
    {
        while (!feof(fileStream))
        {
            int count = fread(&stu[totalStuNum], sizeof(Student), DEFAULT_OPERATE_NUM, fileStream);
            if (count == DEFAULT_OPERATE_NUM)
            {
                ++totalStuNum;
            }
            else
            {
            }
        }
        fclose(fileStream);
        ReSetProgmaInstance(l_pProgmaInstance, stu, true, totalStuNum);
        return true;
    }
    else
    {
        printf_s("%s\n", OPEN_DATA_FILE_FAILED);
        return false;
    }
}

void ProgmaInstanceInit()
{
    pProgmaInstance->totalStudentNum = 0;
    pProgmaInstance->pStudent = NULL;
    pProgmaInstance->inMemory = false;
}

void ReSetProgmaInstance(ProgmaInstance *l_pProgmaInstance, Student *pStudent, bool inMemory, int totalStudentNum)
{
    l_pProgmaInstance->pStudent = pStudent;
    l_pProgmaInstance->inMemory = inMemory;
    l_pProgmaInstance->totalStudentNum = totalStudentNum;
}

void InitAll()
{
    FILE *fileStream = GetFileStream(STUDENT_SCORE_DATA_FILE, "r+");
    if (fileStream == NULL)
    {
        fileStream = GetFileStream(STUDENT_SCORE_DATA_FILE, "w+");
        if (fileStream == NULL)
        {
            printf_s("%s\n", OPEN_DATA_FILE_FAILED);
        }
        else
        {
            ProgmaInstanceInit();
        }
    }
    else
    {
        fclose(fileStream);
        ProgmaInstanceInit();
        ReadAllInToMemory(pProgmaInstance);
    }
}

void Run(bool (*Main)())
{
    bool continueRun = true;
    while (continueRun)
    {
        continueRun = Main();
    }
}

typedef bool (*OperationFunc)(void);
OperationFunc OperateFactoryMethod(int n)
{
    switch (n)
    {
    case 0:
        return Exit;
    case 1:
        return InputStudent;
    case 2:
        return SearchStudent;
    case 3:
        return DeleteStudent;
    case 4:
        return ModifiedStudent;
    case 5:
        return InsertStudent;
    case 6:
        return OrderStudent;
    case 7:
        return GetTotalStudentsNum;
    default:
        return ReInputOperator;
    }
}

bool MainFunc()
{
    ShowMenu();
    char cStr[DEFAULT_INPUT_COMMAND_LEN];
    scanf("%s", cStr);
    int funcNo = -1;
    if (GetIntFormatInput(&funcNo, cStr, DEFAULT_INPUT_COMMAND_LEN))
    {
        PrepareProgramInstance();
        OperationFunc CurrentOperator = OperateFactoryMethod(funcNo);
        bool continueRun = CurrentOperator();
        printf_s("%s\n", CONTINUE_OPERATE_MSG);
        getch();
        return continueRun;
    }
    else
    {
        printf_s("check your input, please\n");
        getch();
        return CONTINUE_RUN;
    }
}

int main(int argc, char **argv)
{
    InitAll();
    Run(MainFunc);
    return 0;
}