#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 0x89898989 

int main()
{
  int shmid = shmget(KEY,1024,IPC_CREAT | 0664);
  if(shmid < 0)
  {
    perror("shmget");
    return -1;
  }
  void* lp = shmat(shmid,NULL,0);

  printf("%s",(char*)lp);
  return 0;
}
