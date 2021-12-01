//
// Created by rishi on 01-12-2021.
//
#include "SDL.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class KeyHandler {
public:
    static std::vector<std::string> keyInfo(SDL_KeyboardEvent *key) {
        std::vector<std::string> info;
        if (key->type == SDL_KEYUP)
            info.emplace_back("KEYUP");
        else
            info.emplace_back("KEYDOWN");

        std::stringstream ss;
        ss << std::hex << key->keysym.scancode;

        info.emplace_back(ss.str());
        info.emplace_back(SDL_GetKeyName(key->keysym.sym));
        return info;
    }

    static std::vector<std::string> modifierInfo(SDL_Keymod mod) {
        /* If there are none then say so and return */
        std::vector<std::string> modifiers;

        if (mod == KMOD_NONE) {
            printf("None\n");
            return modifiers;
        }

        /* Check for the presence of each SDLMod value */
        /* This looks messy, but there really isn't    */
        /* a clearer way.                              */
        if (mod & KMOD_NUM) modifiers.emplace_back("NUMLOCK ");
        if (mod & KMOD_CAPS) modifiers.emplace_back("CAPSLOCK ");
        if (mod & KMOD_LCTRL) modifiers.emplace_back("LCTRL ");
        if (mod & KMOD_RCTRL) modifiers.emplace_back("RCTRL ");
        if (mod & KMOD_RSHIFT) modifiers.emplace_back("RSHIFT ");
        if (mod & KMOD_LSHIFT) modifiers.emplace_back("LSHIFT ");
        if (mod & KMOD_RALT) modifiers.emplace_back("RALT ");
        if (mod & KMOD_LALT) modifiers.emplace_back("LALT ");
        if (mod & KMOD_CTRL) modifiers.emplace_back("CTRL ");
        if (mod & KMOD_SHIFT) modifiers.emplace_back("SHIFT ");
        if (mod & KMOD_ALT) modifiers.emplace_back("ALT ");
        return modifiers;
    }
};
