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
    mkfifo(myfifo2, 0666);

    char arr1[80], arr2[80];
    while (1)
    {

        cout<<"waiting for readers...\n";//checking fie opened
        fd1 = open(myfifo, O_WRONLY);
        cout<<"got a reader--type some stuff\n";
        cin.getline(arr2,80);
        write(fd1, arr2, strlen(arr2)+1);
        close(fd1);



        fd2 = open(myfifo2, O_RDONLY);
        read(fd2, arr1, sizeof(arr1));
        cout<<endl;
        cout<<"ENCRYPTED MESSAGE RECIEVED FROM ANOTHER PROCESS VIA FIFO2 : "<<arr1<<endl;
        cout<<endl;
       if(!strcmp(arr1,"exit")||!strcmp(arr1,"EXIT")||!strcmp(arr1,"Exit"))
                                {  exit(0);}
//
        close(fd2);


    }
    return 0;
}
