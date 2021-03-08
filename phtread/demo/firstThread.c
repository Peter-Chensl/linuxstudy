#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* TsPthread()
{
  while(1)
  {
      printf("I am work thread!\n");
      sleep(1);
  }
  return NULL;
}
int main()
{
  pthread_t tid;
  int ret = pthread_create(&tid,NULL,TsPthread,NULL);
  if (ret < 0)
  {
    perror("pthread_create");
    return -1;
  }
  else 
  {
    while(1)
    {
      printf("I am main thread!\n");
      sleep(1);
    }
  }
  return 0;
}
