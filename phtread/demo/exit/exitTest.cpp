#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* myPthread(void* arg)
{
  sleep(5);
  printf("I am workthread!\n");
  pthread_exit(NULL);
  return NULL;
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
    printf("I am manThread!\n");
    sleep(1);
  }
  return 0;
}
