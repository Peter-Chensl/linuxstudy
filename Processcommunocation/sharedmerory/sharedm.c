#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

#define KEY  0X99999999
int main()
{
  int shmid = shmget(KEY,1024,IPC_CREAT | 0664);
  if(shmid < 0)
  {
    perror("shmget");
    return -1;
  }
  else 
  {
    printf("creat success!\n");
  }
  while(1)
  {
    sleep(1);
  }
  return 0;
}
