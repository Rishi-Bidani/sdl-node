const nodesdl = require('./build/Release/nodesdl');
const Rect = require('./classes/rect');
const Clock = require('./classes/clock');


nodesdl.init(1000, 720, "hello world", false);
const clock = new Clock();
const time1 = clock.getTick();


// console.log("rect1: " + rect1);
const rect1 = new Rect(0, 0, 500, 100, [0, 0, 200]);



function eventHandler(e) {
    // console.log("event: " + e);
    if (e == -1) {
        console.log("default exit")
    }
    if (typeof e === "object" && e.type == "KEYDOWN") {
        console.log("keydown: " + e);
    }
}


while (true) {
    nodesdl.clear();
    const time2 = new Clock().getTick();
    const dt = time2 - time1;
    // console.log("dt: " + dt);
    nodesdl.screenColor(255, 100, 0);
    rect1.blit();
    rect1.x += 0.2;
    if (rect1.x >= 1000) {
        rect1.x = 0;
    }
    rect1.y = 200;
    const event = nodesdl.event();
    console.log("event: " + event);
    if (event == "QUIT") {
        break;
    }
    eventHandler(event);
    nodesdl.update();
}
