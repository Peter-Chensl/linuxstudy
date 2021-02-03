#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
//#include <iostream>
//using namespace  std;

int main()
{
  pid_t pid = fork();
  if (pid < 0)
  {
    perror("fork");
    return 1;
  }
  else if (pid == 0)
  {
    //创建子进程成功
    printf ("我是子进程，我即将退出\n");
    exit(0);
  }
  else
  {
    printf("我是父进程，我将睡眠30秒\n");
    sleep(30);
  }
 // system("ps -o pid, ppid,state,tty,command");
  printf(" 父进程退出\n");
  return 0;
}
