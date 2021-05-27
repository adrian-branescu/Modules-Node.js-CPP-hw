let readOnlyCounter = 0;

function increment() {
    ++readOnlyCounter;
}

export {
    increment, // shortcut for 'increment: increment'
    readOnlyCounter as counter
};
