#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>

sem_t mutex,writeblock,p;
int data = 0,rcount = 0,wcount = 0;

void *reader(void *arg)
{
  sem_wait(&mutex);
  rcount = rcount + 1;
  if(rcount==1){
   sem_wait(&writeblock);
   //sem_wait(&z);
	}
  //else
//	sem_post(&z);
  sem_post(&mutex);
  printf("Data read by the reader%d is %d\n",arg,data);
  //sleep(1);
  //sem_post(&z);
  sem_wait(&mutex);
  //printf("dec\n");
  rcount = rcount - 1;
  if(rcount==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  //sem_wait(&z);
  sem_wait(&p);
  wcount++;
  if(wcount == 1)
    sem_wait(&mutex);
  sem_post(&p);
  //sem_post(&z);
  sem_wait(&writeblock);
  printf("Write something :");
 // scanf("%d",&data);
  data++;
  printf("Data writen by the writer%d is %d\n",arg,data);
  //sleep(1);
  sem_post(&writeblock);
  sem_wait(&p);
  wcount--;
  if(wcount == 0)
    sem_post(&mutex);
  sem_post(&p);

}

int main()
{
  int i,b;
  pthread_t rtid[10],wtid[10];
  sem_init(&p,0,1);
  sem_init(&mutex,0,1);
  sem_init(&writeblock,0,1);
  //sem_init(&z,0,1);
  for(i=0;i<=9;i++)
    pthread_create(&wtid[i],NULL,writer,(void *)i);
  for(int l = 0;l<=9;l++)
    pthread_create(&rtid[i],NULL,reader,(void *)i);
  for(i=0;i<=9;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  return 0;
}
