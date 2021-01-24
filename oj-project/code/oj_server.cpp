#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>

#include "httplib.h"
#include "oj_model.hpp"
#include "oj_view.hpp"
#include "tools.hpp"

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

      //for(int i = 0;i < questions.size();i++)
      //{
      //std::cout << questions[i].id_ << " "<< questions[i].title_ << " " << questions[i].star_ << " " << questions[i].path_ << std::endl;
      //std::cout << questions[i].title_ << std::endl;
      //}
  
      std::string html;
      OjView::DrawAllQuestions(questions,&html);

      resp.set_content(html,"text/html");
      });

  //返回单个试题
  //正则表达式获取题目ID
  svr.Get(R"(/Question/(\d+))",[&model](const Request& req,Response& resp){
      Question ques;
      //获取单个试题
      model.GetOneQuestion(req.matches[1].str(),&ques);

      //2渲染模板的html文件
      std::string html;
      OjView::DrawOneQuestion(ques,&html);

      resp.set_content(html,"test/html");
      });

  //编译运行
  svr.Post(R"(/compile/(\d+))",[&model](const Request& req,Response& resp){
      //获取试题编号
     // std::string ques_id = req.matches[1].str();
      Question ques;
      model.GetOneQuestion(req.matches[1].str(),&ques);

      //std::cout << req.body << std::endl;
     // std::cout << UrlUtil::urlDecode(req.body) << std::endl;

      std::unordered_map<std::string,std::string> body_kv;
      UrlUtil::PraseBody(req.body,&body_kv);

      std::cout << body_kv["code"] << std::endl;
      //std::vector<std::string>vec;
      //StringUtil::Splite(UrlUtil::UrlDecode(req.body),"=",&vec);
      //StringUtil::Splite(UrlUtil::UrlDecode(req.body),":",&vec);

      //for(int i = 0; i< vec.size();i++)
     // {
     // std::cout << vec[i] << std::endl;
     // std::cout <<"printf success" << std::endl;
     // }

      });

  svr.listen("0.0.0.0",19123);
  return 0;
}
