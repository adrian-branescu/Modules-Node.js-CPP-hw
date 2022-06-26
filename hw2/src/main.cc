#include "../node_modules/node-addon-api/napi.h"
#include "../include/mymath.h"

Napi::Number SqrtWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!info[0].IsNumber()) {
       Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }
    Napi::Number number = info[0].As<Napi::Number>();

    int returnValue = mysqrt(number.Int32Value());

    return Napi::Number::New(env, returnValue);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("sqrt", Napi::Function::New(env, SqrtWrapped));
  return exports;
}

NODE_API_MODULE(hw2, Init)