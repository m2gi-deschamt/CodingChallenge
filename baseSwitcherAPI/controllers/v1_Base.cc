#include "v1_Base.h"
#include <iostream>

#include "../src/convert.h"
using namespace v1;

// curl -X POST "http://localhost:5555/v1/Base/?value=1011&base1=2&base2=10"




void Base::convert(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback) 
{
    std::shared_ptr<Json::Value> json = req->getJsonObject();

    if (json.get() == NULL)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k400BadRequest);
        resp->setBody("JSON is missing");
        callback(resp);
        return;
    }

    std::string value = (*json).get("value", "1011").asString();
    int base1 = (*json).get("base1", 4).asInt();
    int base2 = (*json).get("base2", 3).asInt();

    std::string val = from_X_to_10(value, base1);
    val = from_10_to_X(val, base2); 

    Json::Value res;
    res["input"]["base2"] = base2;
    res["input"]["base1"] = base1;
    res["input"]["value"] = value;
    res["output"]["base"] = base2;
    res["output"]["value"] = val;
    res["success"] = true;
    res["status"] = "200";

    auto resp = HttpResponse::newHttpJsonResponse(res);

    callback(resp);
}