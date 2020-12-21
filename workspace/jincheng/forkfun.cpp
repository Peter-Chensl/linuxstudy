#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main()
{
  pid_t pid;

  cout<<"Before pid is:"<<getpid()<<endl;
  if((pid = fork())== -1)
  {
    perror("fork()");
    exit(1);
  }
  cout<<"After:pid is:"<<getpid()<<",fork return is:"<<pid<<endl;
  sleep(1);
  return 0;
}
