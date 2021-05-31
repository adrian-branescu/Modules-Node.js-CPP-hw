#include <iostream>
#include <mymath.h>
#include <napi.h>

Napi::Value mysqrtFct(const Napi::CallbackInfo&info){
    Napi::Env env = info.Env();
    
    if(info.Length() < 1){
        Napi::TypeError::New(env, "You need one argument!").ThrowAsJavaScriptException();
        return env.Null();
    }
    if(!info[0].IsNumber()){
        Napi::TypeError::New(env, "The argument must be number!").ThrowAsJavaScriptException();
        return env.Null();
    }

    double nr = info[0].As<Napi::Number>().DoubleValue();
    double result = mysqrt(nr);
    return Napi::Number::New(env, result);
}
Napi::Object Init(Napi::Env env, Napi::Object exports){
    exports.Set("mysqrt", Napi::Function::New(env, mysqrtFct));
    return exports;
}
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)