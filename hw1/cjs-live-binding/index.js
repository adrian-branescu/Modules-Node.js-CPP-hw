'use strict';

const { counter, increment } = require('./count.js');

console.log(counter);
increment();
console.log(counter);
++counter;
console.log(counter);
