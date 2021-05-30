# a Python file  that contains JSON like data structure to 
# tell node-gyp about the configuration of our Native Module

{
    "targets": [{
        "target_name": "node-mymath",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "../cpp/my-sqrt-lib/src/mysqrt.cxx",
            "./src/binding.cxx"
        ],
        "include_dirs": [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }]
}
