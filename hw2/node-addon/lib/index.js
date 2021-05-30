let binding;

try {
    // for the debug build you only need to `node-gyp rebuild -d`
    binding = require('../build/Debug/node-mymath.node');

} catch (_) {
    binding = require('../build/Release/node-mymath.node');
}

module.exports.mysqrtFunction = (...args) => {
    return binding.mysqrtFunction(...args);
}