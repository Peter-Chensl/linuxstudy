#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();//创建一个子进程
  if(pid > 0)    //父进程
  {
    printf("this is prents:%d\n",getpid());
    sleep(3);
    exit(0);
  }
  else if (pid == 0)
  {
    //子进程
    printf("this is child:%d\n",getpid());
  }
  else 
  {
    //创建失败
    exit(0);
  }
  printf("------------------------------------%d\n",getpid());
  sleep(100);
  return 0;
}
