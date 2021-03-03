#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
  int count = 0;
  while(1)
  {
    int fd = open("./linux",O_RDWR | O_CREAT,0664);
    if(fd < 0)
    {
      perror("open");
      break;
    }
    count++;
    printf("fd:%d\n",fd);
  }
  printf("count: %d\n",count);
  return 0;
}
