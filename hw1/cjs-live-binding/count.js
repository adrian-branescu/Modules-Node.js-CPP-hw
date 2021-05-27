'use strict';

let readOnlyCounter = 0;

function increment() {
    ++readOnlyCounter;
}

module.exports = {
    increment, // shortcut for 'increment: increment'
    counter: readOnlyCounter
};
