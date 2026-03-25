#include "v1_Base.h"
#include <iostream>

#include "../src/index.h"
using namespace v1;

// curl -X POST "http://localhost:5555/v1/Base/?value=1011&base1=2&base2=10"

void Base::convert(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback) 
{
    auto json = req->getJsonObject();

    if (!json)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k400BadRequest);
        resp->setBody("Invalid JSON");
        callback(resp);
        return;
    }

    std::string value = (*json)["value"].asString();
    int base1 = (*json)["base1"].asInt();
    int base2 = (*json)["base2"].asInt();

    std::string val = from_X_to_10(value, base1);
    val = from_10_to_X(val, base2); 

    Json::Value res;
    res["input"] = value;
    res["base1"] = base1;
    res["base2"] = base2;
    res["result"] = val;

    auto resp = HttpResponse::newHttpJsonResponse(res);

    callback(resp);
}