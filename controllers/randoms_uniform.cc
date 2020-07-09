#include "randoms_uniform.h"

#include <string>

#include "Uniform.h"

using namespace randoms;
//add definition of your processing function here


void uniform::get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double left, double right, uint64_t count){

    LOG_DEBUG<<"Getting uniform randoms. left: " << left << " right: " <<  right << " count: " << count;

    Json::Value ret;
    Json::Value numbers;

    vector<double> uniform_randoms = randoms::Uniform::get(left, right, count);
    for (uint64_t i = 0; i < uniform_randoms.size(); i++) {
        numbers[static_cast<int>(i)] = std::to_string(uniform_randoms[i]);
    }
    
    ret["numbers"] = numbers;
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
