//测试多线程可以传递什么参数


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myThread(void* arg)
{
  int* p = (int*)arg;
  while(1)
  {
    printf("I am work thread:%p, i = %d\n",pthread_self(),*p);
    sleep(1);
  }
  return NULL;
}
int main()
{
  pthread_t tid;
  for(int i = 0;i < 4;++i)
  {
     int ret = pthread_create(&tid,NULL ,myThread, &i);
     if(ret < 0)
     {
       perror("pthread_create");
       return -1;
     }
  }
  while(1)
  {
    printf("I am main thread\n");
    sleep(1);
  }
  return 0;
}
