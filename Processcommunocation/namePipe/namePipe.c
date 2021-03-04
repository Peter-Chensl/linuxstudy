#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
  int fifoid = mkfifo("./fifoTest",0664);
  if(fifoid < 0)
  {
    perror("mkfifo");
    return -1;
  }
  printf("创建成功！\n");
  int fd =  open("./fifoTest",O_RDWR | O_CREAT);
  if(fd < 0)
  {
    perror("open");
    return -1;
  }
  else 
  {
    ssize_t w_size = write(fd,"hello linux!",12);
    if(w_size < 0)
    {
      perror("write");
      return -1;
    }
    printf("write:%d",w_size);
  }
  while(1)
  {
    printf("wait!\n");
    sleep(1);
  }
  return 0;
}
