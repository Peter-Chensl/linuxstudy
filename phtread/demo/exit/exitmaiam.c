#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* myPthread(void* arg)
{
  while(1)
  {
    printf("I am workThread!\n");
    sleep(1);
  }
}
int main()
{
  pthread_t tid;
  int ret = pthread_create(&tid,NULL,myPthread,NULL);
  if(ret < 0)
  {
    perror("pthread_create");
    return -1;
  }
  while(1)
  {
    printf("I am mainThread!\n");
    pthread_cancel(pthread_self());
    sleep(1);
  }
  return 0;
}
