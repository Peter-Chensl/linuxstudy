#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define PTHREADCOUNT 1

void* myPthread(void* arg)
{
  while(1)
  {
    printf("I am workthream!\n");
    sleep(1);
    pthread_cancel(pthread_self());
  }

}
int main()
{
  pthread_t tid[PTHREADCOUNT];
  for(int i = 0;i < 1;i++)
  {
    int ret = pthread_create(&tid[i],NULL,myPthread,NULL);
    if(ret < 0)
    {
      printf("pthread_create");
      return -1;
    }
    for(int i = 0;i < PTHREADCOUNT;i++)
    {
     // pthread_join(tid[i],NULL);
     pthread_detach(tid[i]);
    }
    while(1)
    {
      printf("I am main thread!\n");
      sleep(6);
      //printf("exit\n");
     // pthread_cancel(pthread_self());
    }
  }
  return 0;
}
