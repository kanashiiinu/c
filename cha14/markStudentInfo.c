#include <stdio.h>
#include <process.h>
#include <stdbool.h>

#define OPEN_FILE_STREAM_SECCESS 0
#define WRITE_FILE_SECCESS 0
#define DEFAULT_OPERATION_NUM 1
#define READ_ERROR "read file failed"
#define WRITE_ERROR "write one information in file failed"
#define SAVE_ALL_ERROR "save all students information failed"
#define OPEN_FILE_ERROR "open file failed"
#define WRITING_MSG "writing ..."
#define WAITING_MSG "waiting ..."
// const static char * WAITING_MSG = "waiting ...";

struct StudentInfo{
    char name[20];
    char address[30];
    char telNumber[15];
}info[100];

FILE * GetFileStream(char* fileName, char* method){
    FILE * fileStream;
    errno_t err = fopen_s(&fileStream,fileName,method);
    if(err == OPEN_FILE_STREAM_SECCESS){
        return fileStream;
    }else{
        return NULL;
    }
}

void OpenFileFailedExit(char* msg){
    printf_s("%s\n",msg);
    exit(0);
}

bool WriteOneInfo(FILE * pFile,struct StudentInfo * pInfo){
    bool success;
    if (fwrite(pInfo, sizeof(struct StudentInfo), DEFAULT_OPERATION_NUM, pFile) == DEFAULT_OPERATION_NUM)
    {
        success = true;
    }
    else
    {
        success = false;
    }
    return success;
}

void PrintStudentInfo(struct StudentInfo * pInfo){
    printf_s("%20s%30s%15s\n", pInfo->name, pInfo->address, pInfo->telNumber);
}

void SaveAllStudentsInfo(char *fileName, struct StudentInfo * pInfo, int n){
    FILE *fileStream = GetFileStream(fileName,"wb");
    if(fileStream != NULL){
        while(n){
            if (WriteOneInfo(fileStream, pInfo)){
                printf_s("%s\n",WRITING_MSG);
                PrintStudentInfo(pInfo);
                printf_s("%s\n",WAITING_MSG);
            }else{
                printf_s("%s\n",WRITE_ERROR);
                break;
            }
            --n;
            ++pInfo;
        }
        fclose(fileStream);
    }else{
        OpenFileFailedExit(SAVE_ALL_ERROR);
    }
}

void GetStudentsInfoFromFile(FILE *fileStream,struct StudentInfo * pInfo,int totalNum){
    struct StudentInfo * pGetInfo = pInfo;
    for (int i = 0; i < totalNum; ++i,++pGetInfo)
    {
        fread(pGetInfo, sizeof(struct StudentInfo), DEFAULT_OPERATION_NUM, fileStream);
    }
}

void PrintStudentsInfo(struct StudentInfo * pInfo,int totalNum){
    struct StudentInfo * pPrintInfo = pInfo;
    for (int i = 0; i < totalNum; ++i,++pPrintInfo)
    {
        printf_s("%4d :",i+1);
        PrintStudentInfo(pPrintInfo);
    }
}

void ShowAllStudentsInfo(char *fileName, int totalNum){
    FILE *fileStream = GetFileStream(fileName, "rb");
    if( fileStream != NULL){
        struct StudentInfo * pInfo = (struct StudentInfo*)malloc(totalNum * sizeof(struct StudentInfo));
        GetStudentsInfoFromFile(fileStream, pInfo, totalNum);
        fclose(fileStream);
        printf_s("all students information :\n%6s%20s%30s%15s\n","NO","name","address","tel-number");
        PrintStudentsInfo(pInfo, totalNum);
        free(pInfo);
    }else{
        OpenFileFailedExit(READ_ERROR);
    }
}

void GetStudentsInfo(struct StudentInfo * pInfo,int n){
    for (size_t i = 0; i < n; ++i,++pInfo)
    {
        printf_s("NO%d\n",i+1);
        scanf("%s%s%s", pInfo->name, pInfo->address, pInfo->telNumber);
    }
}

int main(int argc, char **argv){
    int totalNum;
    char filename[50];
    printf_s("how many students ?\n");
    scanf("%d",&totalNum);
    printf_s("input filename, please\n");
    scanf("%s",&filename);
    printf_s("input name, address, telephone number, please\n");
    struct StudentInfo * pInfo = (struct StudentInfo*)malloc(totalNum * sizeof(struct StudentInfo));
    GetStudentsInfo(pInfo, totalNum);
    SaveAllStudentsInfo(filename, pInfo, totalNum);
    ShowAllStudentsInfo(filename, totalNum);
    free(pInfo);
    return 0;
}