#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  pid_t pid = fork();
  if(0 == pid)
  {
    sleep(5);
    exit(0);
  }
  else if(pid > 0)
  {
    int status;
    while(waitpid(pid,&status,WNOHANG)== 0){
      printf("没有子进程退出，再等等！");
      sleep(1);
    }
    while(1)
    {
      printf("正在打麻将！\n");
      sleep(1);
    }
  }
  return 0;
}
