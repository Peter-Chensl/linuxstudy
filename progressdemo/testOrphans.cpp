#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <stdlib.h>

int main()
{

  pid_t pid = fork();

  if(pid < 0)
  {
    // 创建失败
    perror("fork");
  }
  else if(0 == pid)
  {
    //子进程
    printf("我是子进程！\n");
    printf("pid: %d\tppid:%d\n",getpid(),getppid());
    printf("我将睡眠10秒");//睡眠10秒，保证父进程先退出
    sleep(10);
    printf("pid: %d\tppid:%d\n",getpid(),getppid());
    printf("子进程退出！\n");
  }
  else
  {
    printf("我是父进程！\n");
    sleep(1);
    printf("父进程退出");
  }
  return 0;
}
