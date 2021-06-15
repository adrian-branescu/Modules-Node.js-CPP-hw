const result = require('./build/Release/sqrt');

console.time('c++');
result.sqrt();
console.timeEnd('c++');

