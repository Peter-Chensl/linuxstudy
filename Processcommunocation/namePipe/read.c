#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  int fd = open("./fifoTest",O_RDONLY);
  if(fd < 0)
  {
    perror("open");
    return -1;
  }
  else 
  {
    char *buf[1024] = {0};
    int ret = read(fd,buf,12);
    if(ret < 0)
    {
      perror("read");
      return -1;
    }
    printf("buf is : %s\n",buf);
  }
  return 0;

}
