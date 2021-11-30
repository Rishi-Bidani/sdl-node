const nodesdl = require('./build/Release/nodesdl');
const Rect = require('./classes/rect');
const Clock = require('./classes/clock');


nodesdl.init(1000, 720, "hello world", false);
const event = nodesdl.event;
const clock = new Clock();
const time1 = clock.getTick();


// console.log("rect1: " + rect1);
const rect1 = new Rect(0, 0, 500, 100, [0, 0, 200]);




while (true) {
    nodesdl.clear();
    const time2 = new Clock().getTick();
    const dt = time2 - time1;
    // console.log("dt: " + dt);
    nodesdl.screenColor(255, 100, 0);
    rect1.blit();
    rect1.x += 0.2;
    rect1.y = 200;
    const e = event();
    if (e === "QUIT") {
        break;
    }
    nodesdl.update();
}
