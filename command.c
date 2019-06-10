#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
int pipe1[2];
int pipe2[2];

void exec1()
{
  dup2(pipe1[1], 1);
  close(pipe1[0]);
  close(pipe1[1]);
  execlp("cat", "cat","cmd.c", NULL);
  //  execlp("ls", "ls", NULL);
}

void exec2()
{
  dup2(pipe1[0], 0);
  dup2(pipe2[1], 1);
  close(pipe1[0]);
  close(pipe1[1]);
  close(pipe2[0]);
  close(pipe2[1]);
  execlp("grep", "grep", "include", NULL);
    //execlp("grep", "grep","e", NULL);
}

void exec3()
{
  dup2(pipe2[0], 0);
  close(pipe2[0]);
  close(pipe2[1]);
  execlp("grep", "grep", "std",  NULL);

}

void main() {
  pipe(pipe1);
  if (fork() == 0)
  {
    exec1();
  }
  pipe(pipe2);
  if (fork() == 0)
  {
    exec2();
  }
  close(pipe1[0]);
  close(pipe1[1]);

  if (fork() == 0)
  {
    exec3();
  }
}
