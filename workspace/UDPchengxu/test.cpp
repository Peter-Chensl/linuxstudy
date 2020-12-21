#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
//网络编程
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
  //创建套接字
 int sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_IDP);
 if(sockfd<0)
 {
   perror("socket");
   return -1;
 }
  //绑定地址信息
  
 struct sockaddr_in addr;
 addr.sin_family = AF_INET;
 addr.sin_addr.s_addr = inet_addr("172.16.99.129");
 addr.sin_port = htonl(19999);
 int ret = bind(socket,(struct sockaddr*)&addr,sizeof(addr));
 if(ret < 0)
 {
   perror("bind");
   return -1;
 }
  while(1)
  {
    sleep(1); 
  }
  return 0;
}
