#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace v1
{
class Base : public drogon::HttpController<Base>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(Base::convert, "/convert", Post);
    ADD_METHOD_TO(Base::convert, "/convert", Post);
    // METHOD_ADD(Base::get, "/{2}/{1}", Get); // path is /v1/Base/{arg2}/{arg1}
    // METHOD_ADD(Base::your_method_name, "/{1}/{2}/list", Get); // path is /v1/Base/{arg1}/{arg2}/list
    // ADD_METHOD_TO(Base::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
    METHOD_LIST_END


    void convert(const HttpRequestPtr &req,
             std::function<void (const HttpResponsePtr &)> &&callback);
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
};
}
