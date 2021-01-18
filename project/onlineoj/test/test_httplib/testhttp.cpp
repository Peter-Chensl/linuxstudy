#include <stdio.h>
#include "httplib.h"

void func(const httplib::Request& req, httplib::Response& resp)
{
    printf("recv abc\n");
}

int main()
{
    //����httplib���е�server����� ʹ�ø������ ģ�ⴴ��һ��http������
    httplib::Server svr;

    svr.Get("/abc", func);

    svr.listen("0.0.0.0", 18989);
    return 0;
}

