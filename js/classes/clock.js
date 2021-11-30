const nodesdl = require('../build/Release/nodesdl');

class Clock {
    getTick() {
        return nodesdl.getTick();
    }
}


module.exports = Clock;