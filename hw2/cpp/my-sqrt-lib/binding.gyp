{
  "targets": [
    {
      "target_name": "my-sqrt-lib",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/mysqrt.cxx",
        "./src/binding.cxx"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
       'dependencies': [
          "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}

