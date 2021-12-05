const nodesdl = require('../build/Release/nodesdl');

class Image {
    constructor(width, height, path) {
        this.width = width;
        this.height = height;
        this.path = path;
        this.image;
    }
    load() {
        this.image = nodesdl.image(this.path, this.width, this.height);
        return this.image
    }
    blit() {
        nodesdl.imgblit(this.image);
    }
}

module.exports = Image;