#include <node.h>

double mysqrt(double x) {
  if (x <= 0) {
    return 0;
  }

  double result = x;

  // do ten iterations
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
  }
  return result;
}


namespace demo {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Number;

    void Method(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        double number = args[0].As<Number>()->Value();
        auto result = Number::New(isolate, mysqrt(number));
        args.GetReturnValue().Set(result);
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "mysqrt", Method);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}

