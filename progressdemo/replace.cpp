#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();
  if(pid < 0)
  {
    perror("fork");
    return -1;
  }
  else if(0 == pid)
  {

    char *const argv[] = {"ps","-ef",NULL};
    char *const envp[] = {"PATH=/bin:/usr/bin", "TERM=console",NULL};
    execl("/bin/ps","ps","-ef",NULL);

    execlp("ps","ps","-ef",NULL,envp);

    execle("ps","ps","-ef",NULL,envp);

    execv("/bin/ps",argv);

    execvp("ps",argv);

    execve("/bin/ps",argv,envp);
    sleep(30);
    exit(0);
  }
  else 
  {
    sleep(30);
    printf("子进程退出！\n");
    while(1)
    {
      printf("正在打麻将！\n");
    } 
  }
}
