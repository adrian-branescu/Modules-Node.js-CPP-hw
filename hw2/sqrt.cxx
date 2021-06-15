#include <node.h>
#include <math.h>

namespace sqrt {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Number;
    using v8::Value;


    void Method(const FunctionCallbackInfo<Value>&args) {
        Isolate *isolate = args.GetIsolate();

        int i;
        double x = 100;

        auto result = Number::New(isolate, sqrt(x));

        args.GetReturnValuer().Set(total);
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "sqrt", Method);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}