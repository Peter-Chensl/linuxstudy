#include <iostream>
#include <cstdio>

#include "httplib.h"

int main()
{
  using namespace httplib;

  //初始化httplib库的server对象
  Server svr;
  
  //提供三个接口，分别处理三个请求
  //获取整个试题列表
  svr.Get("/all_questions",[](const Request& req,Response& resp){
      //返回试题列表
      resp.set_content("<html>57-linux</html>",21,"text/html");
      });

  //返回单个试题
  svr.Get("/signle_ques",[](const Request& req,Response& resp){

      });

  //编译运行
  svr.Post("/test-no",[](const Request& req,Response& resp){

      });

  svr.listen("0.0.0.0",19123);
  return 0;
}
