#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
  int fd[2];
  int ret = pipe(fd);
  if(ret < 0)
  {
    perror("pipe");
    return -1;
  }
 // int flag = fcntl(fd[1], F_GETFL);
 // fcntl(fd[1],F_SETFL, flag | O_NONBLOCK);
  int flag = fcntl(fd[0], F_GETFL);
  fcntl(fd[0],F_SETFL, flag | O_NONBLOCK);

  int pid = fork();
  if(pid < 0)
  {
    perror("fork");
    return -1;
  }
  else if(pid == 0)
  {
   // close(fd[1]);
    char buf[1024] = {0};
    while(1)
    {
      int ret = read(fd[0],buf,sizeof(buf) - 1);
      printf("ret:%d\n",ret);
      if(ret < 0)
      {
        perror("read");
        break;
      }
      sleep(1);
    }
#if 0
   // close(fd[0]);
    int count = 0;
    while(1)
    {
     //har buf[1024] = {0};
     // ssize_t ret = read(fd[0],buf,sizeof(buf) - 1);
     ssize_t ret = write(fd[1],"1",1);
       printf("ret:%d\n",ret);
      if(ret <= 0)
      {
        perror("write");
        break;
      }
      count++;
      printf("write:%d\n",count);
    }
#endif
  }
  else
  {
   // close(fd[1]);
    while(1)
    {
      printf("i am father!\n");
      sleep(1);
    }
#if 0
    close(fd[0]);
    while(1)
    {
      printf("i am father!\n");
      sleep(1);
    }
#endif
  }
  return 0;
}
