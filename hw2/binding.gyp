{
  'targets': [
    {
      'target_name': 'hw2',
      'sources': [ 'src/mysqrt.cxx',
      'src/main.cc' ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
    }
  ]
}