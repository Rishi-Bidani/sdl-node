const nodesdl = require('../build/Release/nodesdl');

class Rect {
    constructor(x, y, w, h, RGB) {
        this._x = x;
        this._y = y;
        this._w = w;
        this._h = h;
        this._r = RGB[0];
        this._g = RGB[1];
        this._b = RGB[2];
        this.rect;
    }
    set x(x) {
        this._x = x;
        this.rect = nodesdl.rect(this._x, this._y, this._w, this._h, this._r, this._g, this._b);
        nodesdl.blit(this.rect);
    }

    set y(y) {
        this._y = y;
        this.rect = nodesdl.rect(this._x, this._y, this._w, this._h, this._r, this._g, this._b);
        nodesdl.blit(this.rect);
    }
    blit() {
        this.rect = nodesdl.rect(this._x, this._y, this._w, this._h, this._r, this._g, this._b);
        nodesdl.blit(this.rect);
    }
    update(x, y, w, h, RGB) {
        this._x = x;
        this._y = y;
        this._w = w;
        this._h = h;
        this._r = RGB[0];
        this._g = RGB[1];
        this._b = RGB[2];
        this.rect = nodesdl.rect(this._x, this._y, this._w, this._h, this._r, this._g, this._b);
        nodesdl.blit(this.rect);
    }
}

module.exports = Rect;