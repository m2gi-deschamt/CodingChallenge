#include <drogon/drogon.h>

int main()
{
    using namespace drogon;

    app().addListener("0.0.0.0", 5555);

    // ✅ CORS - gérer les requêtes OPTIONS (preflight)
    app().registerPreRoutingAdvice(
        [](const HttpRequestPtr &req,
           AdviceCallback &&callback,
           AdviceChainCallback &&chainCallback)
        {
            if (req->method() == Options)
            {
                auto resp = HttpResponse::newHttpResponse();
                resp->addHeader("Access-Control-Allow-Origin", "*");
                resp->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
                resp->addHeader("Access-Control-Allow-Headers", "Content-Type");
                callback(resp);
                return;
            }
            chainCallback();
        });

    // ✅ CORS - ajouter headers à toutes les réponses
    app().registerPostHandlingAdvice(
        [](const HttpRequestPtr &req,
           const HttpResponsePtr &resp)
        {
            resp->addHeader("Access-Control-Allow-Origin", "*");
            resp->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
            resp->addHeader("Access-Control-Allow-Headers", "Content-Type");
        });

    app().run();
}