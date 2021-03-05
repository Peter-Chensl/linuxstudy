#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 0x89898989

int main()
{
    int shmid = shmget(KEY, 1024, IPC_CREAT | 0664);
    if(shmid < 0)
    {
        perror("shmget");
        return -1;
    }
    //create sucess
    
    //0 ：可读可写
    void* lp = shmat(shmid, NULL, 0);
    strcpy((char*)lp, "linux-57-hahaha");

    //shmdt(lp);

    //shmctl(shmid, IPC_RMID, NULL);

    while(1)
    {
        sleep(1);
    }
    return 0;
}
