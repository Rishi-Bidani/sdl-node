//
// Created by rishi on 30-11-2021.
//

#include "SDL.h"
#include <string>
#include <vector>

class KeyHandler {
public:
    std::string eventType;
    int scancode{};
    std::string name;
    std::vector<std::string> modifiers;

    void keyInfo(SDL_KeyboardEvent *key) {
        eventType = "";
        if (key->type == SDL_KEYUP) {
            eventType = "Release";
        } else {
            eventType = "Press";
        }
        scancode = key->keysym.scancode;
        name = SDL_GetKeyName(key->keysym.sym);

//        Modifiers
//        auto mod = static_cast<SDL_Keymod>(key->keysym.mod);
//        No modofiers
//        if (mod == KMOD_NONE) {
//            printf("None\n");
//            return;
//        }
//        if (mod & KMOD_NUM) modifiers.emplace_back("NUMLOCK ");
//        if (mod & KMOD_CAPS) modifiers.emplace_back("CAPSLOCK ");
//        if (mod & KMOD_LCTRL) modifiers.emplace_back("LCTRL ");
//        if (mod & KMOD_RCTRL) modifiers.emplace_back("RCTRL ");
//        if (mod & KMOD_RSHIFT) modifiers.emplace_back("RSHIFT ");
//        if (mod & KMOD_LSHIFT) modifiers.emplace_back("LSHIFT ");
//        if (mod & KMOD_RALT) modifiers.emplace_back("RALT ");
//        if (mod & KMOD_LALT) modifiers.emplace_back("LALT ");
//        if (mod & KMOD_CTRL) modifiers.emplace_back("CTRL ");
//        if (mod & KMOD_SHIFT) modifiers.emplace_back("SHIFT ");
//        if (mod & KMOD_ALT) modifiers.emplace_back("ALT ");
    }


};

//auto keyInfo(SDL_KeyboardEvent *key) {
//    struct Details {
//        std::string eventType;
//        int scancode{};
//        std::string name;
//        std::vector<std::string> modifiers;
//    };
//    Details details;
//    details.eventType = "";
//    if (key->type == SDL_KEYUP) {
//        details.eventType = "Release";
//    } else {
//        details.eventType = "Press";
//    }
//    details.scancode = key->keysym.scancode;
//    details.name = SDL_GetKeyName(key->keysym.sym);
//
////        Modifiers
//    auto mod = static_cast<SDL_Keymod>(key->keysym.mod);
////        No modofiers
////        if (mod == KMOD_NONE) {
////            printf("None\n");
////            return;
////        }
//    if (mod & KMOD_NUM) details.modifiers.emplace_back("NUMLOCK ");
//    if (mod & KMOD_CAPS) details.modifiers.emplace_back("CAPSLOCK ");
//    if (mod & KMOD_LCTRL) details.modifiers.emplace_back("LCTRL ");
//    if (mod & KMOD_RCTRL) details.modifiers.emplace_back("RCTRL ");
//    if (mod & KMOD_RSHIFT) details.modifiers.emplace_back("RSHIFT ");
//    if (mod & KMOD_LSHIFT) details.modifiers.emplace_back("LSHIFT ");
//    if (mod & KMOD_RALT) details.modifiers.emplace_back("RALT ");
//    if (mod & KMOD_LALT) details.modifiers.emplace_back("LALT ");
//    if (mod & KMOD_CTRL) details.modifiers.emplace_back("CTRL ");
//    if (mod & KMOD_SHIFT) details.modifiers.emplace_back("SHIFT ");
//    if (mod & KMOD_ALT) details.modifiers.emplace_back("ALT ");
//
//    return details;
//}


//class keyHandler {
//public:
//    struct Details {
//        std::string eventType;
//        int scancode;
//        std::string name;
//        std::vector<std::string> modifiers;
//    };
//    struct Details details;
//
//    auto keyInfo(SDL_KeyboardEvent *key) {
//        details.eventType = "";
//        if (key->type == SDL_KEYUP) {
//            details.eventType = "Release";
//        } else {
//            details.eventType = "Press";
//        }
//        details.scancode = key->keysym.scancode;
//        details.name = SDL_GetKeyName(key->keysym.sym);
//
////        Modifiers
//        auto mod = static_cast<SDL_Keymod>(key->keysym.mod);
////        No modofiers
////        if (mod == KMOD_NONE) {
////            printf("None\n");
////            return;
////        }
//        if (mod & KMOD_NUM) details.modifiers.emplace_back("NUMLOCK ");
//        if (mod & KMOD_CAPS) details.modifiers.emplace_back("CAPSLOCK ");
//        if (mod & KMOD_LCTRL) details.modifiers.emplace_back("LCTRL ");
//        if (mod & KMOD_RCTRL) details.modifiers.emplace_back("RCTRL ");
//        if (mod & KMOD_RSHIFT) details.modifiers.emplace_back("RSHIFT ");
//        if (mod & KMOD_LSHIFT) details.modifiers.emplace_back("LSHIFT ");
//        if (mod & KMOD_RALT) details.modifiers.emplace_back("RALT ");
//        if (mod & KMOD_LALT) details.modifiers.emplace_back("LALT ");
//        if (mod & KMOD_CTRL) details.modifiers.emplace_back("CTRL ");
//        if (mod & KMOD_SHIFT) details.modifiers.emplace_back("SHIFT ");
//        if (mod & KMOD_ALT) details.modifiers.emplace_back("ALT ");
//
//        return details;
//    }
//};