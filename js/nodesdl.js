const nodesdl = require('./build/Release/nodesdl');

nodesdl.init(1000, 720, "hello world", false);
const event = nodesdl.event;

// console.log("event: " + event());
nodesdl.screenColor(255, 100, 0);


// console.log("rect1: " + rect1);
const rect1 = nodesdl.rect(0, 0, 100, 100, 255, 0, 0);
nodesdl.blit(rect1);
nodesdl.updateRect(rect1, 0, 0, 0, 0, 0, 200, 200);

while (true) {

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