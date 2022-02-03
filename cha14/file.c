#include <stdio.h>
#include <process.h>
int main(int argc, char **argv)
{
    // 直接使用文件指针的方式已被弃用
    // FILE * pFile = NULL;
    // pFile = fopen("test.txt","r+");
    // if(pFile != NULL){
    //     printf_s("file was opened\n");
    //     fclose(pFile);
    // }
    // else{
    //     printf_s("file was not opened\n");
    // }

    // 现在使用如下方法
    FILE * fileStream = NULL;
    errno_t err = fopen_s(&fileStream,"test.txt","w+");
    if(err == NULL){
        printf_s("file was opened\n");
        fputc('c',fileStream);
        fclose(fileStream);
    }
    else{
        printf_s("file was not opened\n");
    }
    return 0;
}