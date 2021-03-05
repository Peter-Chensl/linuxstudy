#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 0X89898989

int main()
{
  int ret = shmget(KEY,1024,IPC_CREAT | 0664);
  if(ret < 0)
  {
    perror("shmget");
    return -1;
  }
  void *lp = shmat(ret,NULL,0);
  strcpy((char*)lp,"hello world!\n");

  shmdt(lp);
  //shmctl(ret,IPC_RMID,NULL);
  
  while(1)
  {
    sleep(1);
  }
  return 0;
}
