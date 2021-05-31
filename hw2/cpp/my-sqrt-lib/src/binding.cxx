#include <napi.h> // provided by node-addon-api

// Napi::CallbackInfo object contains the arguments passed by the caller
Napi::Number mySqrt(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    double result = mysqrt((double)info[0].toNumber(););

    // return new 'Napi::Number' value
    return Napi::Number::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {

    // set a key on 'exports' object
    exports.Set(
        Napi::Number::(env, "mySqrt"),
        Napi::Function::New(env, mySqrt)
    );

    return exports;
}

NODE_API_MODULE(my-sqrt-lib, Init);