#include <assert.h>
#include <node_api.h>

// a hack square root calculation using simple operations
double mysqrt(double x)
{
  if (x <= 0)
  {
    return 0;
  }

  double result = x;

  // do ten iterations
  for (int i = 0; i < 10; ++i)
  {
    if (result <= 0)
    {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    // std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }
  return result;
}

napi_value mySqrt(napi_env env, napi_callback_info info)
{
  napi_status status;

  size_t argc = 1;
  napi_value args[1];
  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  if (argc != 1)
  {
    napi_throw_type_error(env, NULL, "Wrong number of arguments");
    return NULL;
  }
  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  assert(status == napi_ok);

  if (valuetype != napi_number)
  {
    napi_throw_error(env, NULL, "Wrong argument type");
    return NULL;
  }
  double x;
  status = napi_get_value_double(env, args[0], &x);
  assert(status == napi_ok);

  napi_value result;
  status = napi_create_double(env, mysqrt(x), &result);
  assert(status == napi_ok);

  return result;
}

#define DECLARE_NAPI_METHOD(name, func)     \
  {                                         \
    name, 0, func, 0, 0, 0, napi_default, 0 \
  }

napi_value Init(napi_env env, napi_value exports)
{
  napi_status status;
  napi_property_descriptor mySqrtDescriptor = DECLARE_NAPI_METHOD("mysqrt", mySqrt);
  status = napi_define_properties(env, exports, 1, &mySqrtDescriptor);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)