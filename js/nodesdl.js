const nodesdl = require('./build/Release/nodesdl');
const Rect = require('./classes/rect'); // Allows you to create rectangles
const Clock = require('./classes/clock'); // doesn't work yet -> intended for timing stuff and FPS
const Event = require('./classes/events'); // Keydown keyup events etc
const Image = require('./classes/image'); // Allows you to put images on the screen

nodesdl.init(1000, 720, "hello world", false);
const clock = new Clock();
const time1 = clock.getTick();

const img1 = new Image(100, 100, "./test.bmp")
const rect1 = new Rect(0, 0, 500, 100, [0, 0, 200]); // x, y, width, height, color

const image = img1.load(); // load image


// Event Handler -> parameter passeed through the event in while loop
function eventHandler(e) {
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
    nodesdl.clear(); // Clear screen for updated content in the next frame
    // const time2 = new Clock().getTick(); // -> not working
    // const dt = time2 - time1; // -> not working

    nodesdl.screenColor(255, 100, 50); // Set screen color -> R, G, B


    img1.blit(image); // show image on screen
    rect1.blit(); // show rect on screen
    if (rect1.x >= 1000) {
        rect1.x = 0;
    }
    rect1.y = 200;
    const e = new Event(nodesdl.event()).getEvent();


    if (e.type == "QUIT") {
        break;
    }
    eventHandler(e);
    nodesdl.update(); // Updates the screen and allows items to be displayed
}
