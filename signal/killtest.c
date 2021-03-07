#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
  while(1)
  {
    printf("linux so easy!\n");
    kill(getpid(),2);
    sleep(1);
  }
  return 0;
}
