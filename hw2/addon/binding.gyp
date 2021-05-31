{
  "targets": [
    {
      "target_name": "mymath",
      "sources": ["src/binding.cxx"],
       "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "/usr/include"
      ],
      "libraries": ["/usr/lib64/libmymath.so.1.0"],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
    }
  ]
}