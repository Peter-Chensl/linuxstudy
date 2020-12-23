#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t pid = fork();//创建子进程
  //子进程复制父进程，运行代码位置一样
  //从代码角度看，就都是从fork函数之后开始运行的
  //因为父子进程运行的代码数据都是一样的，所以无法直接分辨，只能通过返回值判断
  if(pid > 0)
  {
    //this is prents
    printf("this is prents!\n");
  }
  else if(pid == 0)
  {
    //this id child
    printf("this is child!\n");
  }
  else{
    //错误
    perror("fork");
  }
  printf("This is a progress!\n");
  return 0;
}

