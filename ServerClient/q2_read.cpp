#include<iostream>
#include<cstdio>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main()
{
    int fd1,fd2;
    char * myfifo = "myfifo";
    char * myfifo2 = "myfifo2";
    mkfifo(myfifo, 0666);
    mkfifo(myfifo2,0666);

    char str1[80], str2[80];
    while (1)
    {
        cout<<"waiting for writers...\n";
        fd1= open(myfifo,O_RDONLY);
        cout<<"got a writer\n";//checking that file opened
        read(fd1, str1, sizeof(str1));
        cout<<endl;
        cout<<"MESSAGE RECIEVED FROM  ANOTHER PROCESS VIA FIFO1 : "<<str1<<endl;
        cout<<endl;
        for(int i=0;i<(strlen(str1));i++)//encrypting
                   str1[i]=str1[i]+1;
        close(fd1);


        fd2 = open(myfifo2,O_WRONLY);
        write(fd2, str1, strlen(str1)+1);
        if(!strcmp(str1,"exit")||!strcmp(str1,"EXIT")||!strcmp(str1,"Exit"))
                                 {  exit(0);}
        close(fd2);

    }
    return 0;
}
