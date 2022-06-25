#include <node_api.h>
#include "mymath.h"

napi_value mySqrt(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    double param;
    double sqrt;
    napi_value output;
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    napi_get_value_double(env, args[0], &param);
    sqrt = mysqrt(param);
    napi_create_double(env, sqrt, &output);
    return output;
}

napi_value init(napi_env env, napi_value exports) {
    napi_value find_sqrt;
    napi_create_function(env, nullptr, 0, mySqrt, nullptr, &find_sqrt);
    return find_sqrt;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);