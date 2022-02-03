#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
bool GetIntFormatInput(int* pInt,char*cStr,int n){
    if ('\0' == cStr[0])
    {
        return false;
    }
    else
    {
        for(int i = 0; i < n;++i){
            if(cStr[i] >= '0' && cStr[i] <= '9'){
                continue;
            }else if(cStr[i] == '\0'){
                *pInt = atoi(cStr);
                return true;
            }else{
                return false;
            }
        }
    }
}
int main(int argc, char **argv){
    printf_s("%d\n",sizeof(FILE));
    FILE * pFile = fopen("test.txt", "r");
    if(pFile==NULL){
        printf_s("Error opening test file\n");
    }else{
        printf_s("success\n");
    }
    FILE * pFileAgain = fopen("test.txt", "a");
    if(pFileAgain==NULL){
        printf_s("Error opening test file\n");
    }else{
        printf_s("success\n");
    }
    fclose(pFileAgain);
    fclose(pFile);
    int i;
    char * str[50];
    scanf("%s", str);
    if(GetIntFormatInput(&i,str,50)){
        printf_s("%d\n", i);
    }else{
        printf_s("err");
    }
    // int i = 0;
    // char inputCStr[50];
    // scanf("%s",inputCStr);
    // i = atoi(inputCStr);
    // float f = (float)atof(inputCStr);
    // printf_s("\n\n%d\n%f\n", i, f);
    return 0;
}