#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int fd[2];
  char buf[100];
  int len;
  int pipeid = pipe(fd);

  if(pipeid < 0)
  {
    perror("pipe");
    return -1;
  }

  while(fgets(buf,100,stdin))
  {
    len = strlen(buf);
    if(write(fd[1],buf,len) != len)
    {
      perror("write to pipe!\n");
      break;
    }
    memset(buf,0x00,sizeof(buf));

    if((len = read(fd[0],buf,100)) == -1 )
    {
      perror("read from pipe!\n");
      break;
    }
    if(write(1,buf,len) != len)
    {
      perror("writer to stfout!\n");
      break;
    }
  }
}
