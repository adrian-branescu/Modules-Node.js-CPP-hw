#include <napi.h>
#include "../../cpp/my-sqrt-lib/include/mymath.h"

// native C++ function that is assigned to "node-mymath" 
// property on 'exports' object
Napi::Number mysqrtFunction(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // call mysqrt() function from mysqrt.cxx file
    double number = (double)info[0].ToNumber();
    double result = mysqrt(number);

    // return the result
    return Napi::Number::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  // set a key  on 'exports' object
  exports.Set(
      Napi::String::New(env, "mysqrtFunction"), // property name
      Napi::Function::New(env, mysqrtFunction) // property value
  );

  return exports;
}

NODE_API_MODULE(node_mymath, Init)