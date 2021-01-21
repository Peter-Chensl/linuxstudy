#apragma once 
#include <iostream>
#include <vector>
#include <ctemplate/template.h>

#include "oj_model.hpp"

class OjView
{
      public:
        static void DrawAllQuestions(std::vector<Question& questions>,std::string* html)
        {
          ctemplate::TemplateDictionary dict("allquestion");

          for(const auto& ques : questions)
           {
             ctemplate::TemplateDictionary* sub_dict = dict.AddSelectionDictionary("question");
  
             sub_dict->SetValue("id",ques.id_);
             sub_dict->SetValue("id",ques.id_);
             sub_dict->SetValue("title",ques.title_);
             sub_dict->SetValue("star",ques.star_);
           }

        //填充
        ctemplate::Template* t1 = ctemplate::Template::GetTemplate("./template/all_questions.html",ctemplate::DO_NOT_STRIP);
        //渲染
        t1->Expand(html,&dict);
        }
        static void DrawOneQuestion(const Question &question,std::string *html)
        {
          ctemplate::TemplateDictionary dict("question");
          dict.SetValue("id",question.id_);
          dict.SetValue("title",question.title_);
          dict.SetValue("star",question.star_);
          dict.SetValue("desc",question.desc_);
          dict.SetValue("id",question.id_);
          dict.SetValue("code",question.header_cpp_);

          ctemplate::Template* tl = ctemplate::Template::GetTemplate("./template/question.html",ctemplate::DO_NOT_STRIP);
          //渲染
          tl->Expand(html,&dict);
        }
};
