const addon = require('./build/Release/addon');

addon.init(1000, 720, "hello world", true);
const event = addon.event;

// console.log("event: " + event());
addon.screenColor(255, 100, 0);

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