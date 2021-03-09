#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define PTHREADCOUNT 4
int g_tickets = 100;

void* myPthread(void* arg)
{
  (void)arg;
  while(1)
  {
    if(g_tickets > 0)
    {
      printf("I am thread:%p,i have ticket %d\n",pthread_self,g_tickets);
      g_tickets--;
    }
    else 
    {
      break;
    }
  }
}
int main()
{
  pthread_t tid[PTHREADCOUNT];
  for(int i = 0;i < PTHREADCOUNT;i++)
  {
     int ret =  pthread_create(&tid[i],NULL,myPthread,NULL);
     if(ret < 0)
     {
       perror("pthread_create");
       return -1;
     }
  }
  for(int i = 0;i < PTHREADCOUNT;i++)
  {
    pthread_join(tid[i],NULL);
  }
  return 0;
}
