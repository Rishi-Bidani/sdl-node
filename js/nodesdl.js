const nodesdl = require('./build/Release/nodesdl');
const Rect = require('./classes/rect');
const Clock = require('./classes/clock');
const Event = require('./classes/events');
const Image = require('./classes/image');

nodesdl.init(1000, 720, "hello world", false);
const clock = new Clock();
const time1 = clock.getTick();


// console.log("rect1: " + rect1);
const img1 = new Image(100, 100, "./test.bmp")
const rect1 = new Rect(0, 0, 500, 100, [0, 0, 200]);

const image = img1.load();
// img1.blit()

function eventHandler(e) {
    // console.log("event: " + e.type);
    if (e == -1) {
        console.log("default exit")
    }
    if (e.type === "KEYDOWN") {
        console.log("keydown: " + Object.values(e));
        rect1.x += 10.2;

    }
    if (e.type === "KEYUP") {
        console.log("keyup: " + Object.values(e));
    }
}


while (true) {
    nodesdl.clear();
    const time2 = new Clock().getTick();
    const dt = time2 - time1;
    // console.log("dt: " + dt);
    nodesdl.screenColor(255, 100, 50);


    img1.blit(image);
    rect1.blit();
    if (rect1.x >= 1000) {
        rect1.x = 0;
    }
    rect1.y = 200;
    const e = new Event(nodesdl.event()).getEvent();


    if (e.type == "QUIT") {
        break;
    }
    eventHandler(e);
    nodesdl.update();
}
