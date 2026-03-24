#include "v1_Base.h"
#include <iostream>

#include "../src/index.h"
using namespace v1;

// curl -X POST "http://localhost:5555/v1/Base/?value=1011&base1=2&base2=10"

void Base::convert(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback,
                   const std::string &value,
                   int base1,
                   int base2) 
{
    std::string val = from_X_to_10(value, base1);
    val = from_10_to_X(val, base2); 
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody(val);
    //resp->setBody(std::to_string(result));
    callback(resp);
}