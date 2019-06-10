#include<iostream>
#include<pthread.h>
using namespace std;
int key;
int keypos;
int findk;
int a[100];
int maxe;
int inpsize;
int currenth=0;

void* ls(void* arg){
  int bg=currenth++;
  for(int i=bg*(inpsize/maxe);i<(bg+1)*(inpsize/maxe);i++)
  {
    if (a[i]==key){
          findk=1;
          keypos=i;
        }}}

int main()
{
  cin>> inpsize;
  for(int i=0;i<inpsize;i++)
          cin>>a[i];
  cin>>maxe;
  cin>>key;

  pthread_t thread[maxe];
  for(int i=0;i<maxe;i++)
          pthread_create(&thread[i],NULL, ls,(void*)NULL);

  for(int i=0;i<maxe;i++)
          pthread_join(thread[i],NULL);
    if(findk)
          cout<<"found"<<keypos;
    else
          cout<<"keydoesnt exixts";
}
