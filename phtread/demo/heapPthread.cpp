#include <stdio.h>
//#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


struct Data
{
  int data_;
};
void* myPthread(void* arg)
{
#if 0
  Data* d = (Data*)arg;
  while(1)
  {
    printf("I am workthread:%p,i = %d\n",pthread_self(),d->data_);
    sleep(1);
  }
  delete d;
  d = NULL;
  return NULL;
#endif 
  Data* d = (Data*)arg;
  while(1)
    {
      printf("i am workthread %p, i = %d\n", pthread_self(), d->data_);
      sleep(1);
                            
    }
    delete d;
    d = NULL;
                  //code3
    return NULL;
}
int main()
{
  pthread_t tid;
  for(int i = 0;i < 4;i++)
  {
#if 0
    Data* d = new Data();
    d->data_ = i;
#endif
    Data* d = new Data();
    d->data_ = i;
    //int ret = pthread_create(&tid, NULL,myPthread,(void*)d);
    int ret = pthread_create(&tid, NULL, myPthread, (void*)d);
    if(ret < 0)
    {
      perror("pthread_create");
      return -1;
    }
  }
    while(1)
    {
      printf("I am mainpthread!\n");
      sleep(1);
   }
  return 0;
}
