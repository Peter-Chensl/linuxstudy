#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
  pid_t pid = fork();
  if(pid == 0)
  {
    sleep(5);
    exit(0);
  }else if(pid > 0)
  {
    waitpid(pid,NULL,0);
    while(1){
      printf("正在打麻将！\n");
      sleep(1);
    }
  }
}
