const nodesdl = require('../build/Release/nodesdl');


class Event {
    constructor(event) {
        this.event = event;
    }
    getEvent() {
        if (this.event == "QUIT") {
            return { type: "QUIT" }
        }
        // else if (typeof this.event === "object") {
        //     console.log("Object", this.event);
        // }
        else if (typeof this.event === "object" && this.event.type === "KEYDOWN") {
            return { type: "KEYDOWN", key: this.event.keyname, keycode: this.event.scancode }
        }
        else if (typeof this.event === "object" && this.event.type === "KEYUP") {
            return { type: "KEYUP", key: this.event.keyname, keycode: this.event.scancode }
        }

        else {
            return { type: "" }
        }


    }
}

module.exports = Event;