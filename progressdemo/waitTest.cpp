#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
  pid_t pid = fork();
  if(pid == 0)
  {
    sleep(5);
    exit(0);
  }
  else if(pid > 0)
  {
    int ret = waitpid(pid,NULL,WNOHANG);
    if(0 == ret)
    {
      printf("没有子进程退出！\n");
    }
    while(1)
    {
      printf("正在打麻将！\n");
    }
  }
  return 0;
}
