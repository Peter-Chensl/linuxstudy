#include <stdio.h>
#include <unistd.h>

int main()
{
  int fd[2];
  int ret = pipe(fd);
  if(ret < 0)
  {
    perror("pipe");
    return -1;
  }
  int count = 0;
  while(1)
  {
    write(fd[1],"1",1);
    count++;
    printf("count:%d\n",count);
  }
  return 0;
}
