let binding;

try {
    // for the debug build you only need to `node-gyp rebuild -d`
    binding = require('../build/Debug/node-mymath.node');

} catch (_) {
    binding = require('../build/Release/node-mymath.node');
}

module.exports.mysqrtFunction = (...args) => {
    // yet another proxy later
    return binding.mysqrtFunction(...args);
}