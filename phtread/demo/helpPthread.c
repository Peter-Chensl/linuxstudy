#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PTHREADID 4

struct Data
{
  int data_;
};
void* myPthread(void* arg)
{
  Data d = (Data*)arg;
  while(1)
  {
    printf("I am workthread:%p,i = %d\n",pthread_self(),d->data_);
    sleep(1);
  }
  delete d;
  d = NULL;
  return NULL;
}
int main()
{
  pthread_t tid;
  for(int i = 0;i < PTHREADID;i++)
  {
    Data* d = new Data();
    int ret = pthread_create(&tid, NULL,myPthread,(void*)d);
    if(ret < 0)
    {
      perror("pthread_create");
      return -1;
    }
    while(1)
    {
      printf("I am mainpthread:%p\n",pthread_self());
      sleep(1);
    }
  }
  return 0;
}
