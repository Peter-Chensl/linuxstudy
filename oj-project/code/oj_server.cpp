#include <iostream>
#include <cstdio>

#include "httplib.h"
#include "oj_model.hpp"

int main()
{
  using namespace httplib;

  //初始化httplib库的server对象
  Server svr;
  ojModel model;
  //提供三个接口，分别处理三个请求
  //获取整个试题列表
  svr.Get("/all_questions",[&model](const Request& req,Response& resp){
      //返回试题列表
      std::vector<Question> questions;
      model.GetAllQuestion(&questions);

      for(int i = 0;i < questions.size();i++)
      {
      std::cout << questions[i].id_ << " "<< question[i].title_ << " " << questions[i].star_ << " " << questions[i].path_ << std::endl;
      //std::cout << questions[i].title_ << std::endl;
      }
      resp.set_content("<html>57-linux</html>",21,"text/html");
      });

  //返回单个试题
  svr.Get("/signle_ques",[model](const Request& req,Response& resp){

      });

  //编译运行
  svr.Post("/test-no",[model](const Request& req,Response& resp){

      });

  svr.listen("0.0.0.0",19123);
  return 0;
}
