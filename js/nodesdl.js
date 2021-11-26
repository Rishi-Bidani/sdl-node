const addon = require('./build/Release/addon');

addon.init(1000, 720, "hello world", true);
console.log(addon.event)