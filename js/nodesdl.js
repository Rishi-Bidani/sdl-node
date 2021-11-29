const nodesdl = require('./build/Release/nodesdl');
const Rect = require('./classes/rect');

nodesdl.init(1000, 720, "hello world", false);
const event = nodesdl.event;

// console.log("event: " + event());
nodesdl.screenColor(255, 100, 0);


// console.log("rect1: " + rect1);
const rect1 = new Rect(0, 0, 500, 100, [0, 0, 200]);




while (true) {
    // const rect1 = nodesdl.rect(0, 0, 500, 100, 0, 0, 200);
    // nodesdl.blit(rect1);
    // nodesdl.updateRect(rect1, 200, 0, 20, 100, 0, 200, 200);

    rect1.blit();
    rect1.x = 200;
    rect1.y = 200;
    const e = event();
    if (e === "QUIT") {
        break;
    }
}

// while (true) {
//     const event = addon.event();
//     const pollevent = addon.pollevent();
//     const quit = addon.quit();

//     while (pollevent) {
//         switch (event.type) {
//             case quit:
//                 running = false;
//                 break;

//             default:
//                 break;
//         }
//     }
// }