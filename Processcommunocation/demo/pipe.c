#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int fd[2];
  int ret = pipe(fd);
  char buf[1024] = {0};
  if(ret < 0)
  {
    perror("pipe");
    return -1;
  }
  pid_t pid = fork();
  if(pid < 0)
  {
    perror("fork");
    return -1;
  }
  else if(0 == pid)
  {
      ssize_t ret = read(fd[0],buf,sizeof(buf) - 1);
      if(ret < 0)
      {
        perror("read");
      }
      printf("i am child ,buf is:%s\n",buf);
      sleep(1);
  }
  else 
  {
    //ssize_t w_size = write(fd[1],"hello linux!",12);
    //if(w_size <= 0)
   // {
      //perror("write");
     // return -1;
   // }
   printf("i am fsther,I will write:");
   fgets(buf,100,stdin);
   int  len = strlen(buf);
   if(write(fd[1],buf,len) != len)
   {
     perror("write");
   }
      sleep(1);
  }
  return 0;
}
