#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
  pid_t id = fork();
  if(id < 0)
  {
    perror("fork");
    return 1;
  }
  else if(id > 0)
  {
    printf("parent[%d] is sleep,,,\n",getpid());
    sleep(30);
  }
  else 
  {
    printf("chird[%d] is begin Z,,,\n",getpid());
    sleep(5);
    exit(EXIT_SUCCESS);
  }
  return 0;
}
