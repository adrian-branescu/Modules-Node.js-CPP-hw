let bind;

bind = require('../build/Release/mymath.node');

module.exports.mysqrt = (...args) => { return bind.mysqrt(...args);};
