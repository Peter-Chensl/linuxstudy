#pragma once 

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <boost/algorithm/string.hpp>

#include "tools.hpp"

struct Question
{
  std::string id_;
  std::string title_;
  std::string star_;// 
  std::string path_;

  std::string desc_;
  std::string header_cpp_;// 
  std::string tail_cpp_;
};

class ojModel
{
  public:
    ojModel()
    {
      Load("./oj_data/oj_config.cfg");
    }
    ~ojModel()
    {

    }
    bool Load(const std::string filename)
    {
      std::ifstream file(filename.c_str());
      if(!file.is_open())
      {
        std::cout << "打开失败！" << std::endl;
        return false;
      }
      std::string line;
      while(std::getline(file,line))
      {
        std::vector<std::string> vec;
        StringUtil::Split(line,"/t",&vec);
       // boost::split(vec,line, boost::is_any_of(" "), boost::token_compress_off);

        Question ques;
        ques.id_ = vec[0];
        ques.title_ = vec[1];
        ques.star_ = vec[2];
        ques.path_ = vec[3];

        std::string dir = vec[3];
        FileUtil::ReadFile(dir + "/desc.txt", &ques.desc_);
        FileUtil::ReadFile(dir + "/header.cpp", &ques.header_cpp_);
        FileUtil::ReadFile(dir + "/tail.cpp", &ques.tail_cpp_);

        ques_map_[ques.id_] = ques;
      }
      file.close();
      return true;
    }
    bool GetAllQuestion(std::vector<Question>* questions)
    {
      //遍历无序的map
      //对于每一个试题，都是一个Question结构体对象
      for(const auto& kv : ques_map_)
      {
        questions->push_back(kv.second);
      }
      //排序
      std::sort(questions->begin(), questions->end(),[](const Question& l, const Question& r){return std::stoi(l.id_) < std::stoi(r.id_);});
    }
    bool GetOneQuestion()
    {

    }
  private:
    std::unordered_map<std::string,Question> ques_map_;

};
