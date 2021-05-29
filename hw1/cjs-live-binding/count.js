'use strict';

let readOnlyCounter = 0;

function increment() {
    console.log("hello" + readOnlyCounter);
    ++readOnlyCounter;
    console.log("hello" + readOnlyCounter);

}

module.exports = {
    increment, // shortcut for 'increment: increment'
    counter: readOnlyCounter
};
