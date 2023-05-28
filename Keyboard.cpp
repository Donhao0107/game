#include "Keyboard.h"

Keyboard::Keyboard() {
    keyStates = {
        {Key::A, false},{Key::D, false},{Key::S, false},{Key::W, false}
   
    };
}

bool Keyboard::isDown(Key key) {
    update();
    return keyStates[key];
}

void Keyboard::update() {
    ExMessage key{};
    if (peekmessage(&key, EX_KEY)) {
        for (auto& keyState : keyStates) {
            keyState.second = false;
        }

        switch (key.vkcode) {
        case 65:  // A
            keyStates[Key::A] = true;
            break;
        case 68:  // D
            keyStates[Key::D] = true;
            break;
        case 83:  // S
            keyStates[Key::S] = true;
            break;
        case 87:  // W
            keyStates[Key::W] = true;
            break;
        }
    }
}








/*
        {Key::B, false},{Key::C, false},
        {Key::E, false},{Key::F, false},
        {Key::G, false},{Key::H, false},{Key::I, false},
        {Key::J, false},{Key::K, false},{Key::L, false},
        {Key::M, false},{Key::N, false},{Key::O, false},
        {Key::P, false},{Key::Q, false},{Key::R, false},
        {Key::T, false},{Key::U, false},
        {Key::V, false},{Key::X, false},
        {Key::Y, false},{Key::Z, false}
 case 65:  // A
        keyStates[Key::A] = true;
        break;
    case 66:  // B
        keyStates[Key::B] = true;
        break;
    case 67:  // C
        keyStates[Key::C] = true;
        break;
    case 68:  // D
        keyStates[Key::D] = true;
        break;
    case 69:  // E
        keyStates[Key::E] = true;
        break;
    case 70:  // F
        keyStates[Key::F] = true;
        break;
    case 71:  // G
        keyStates[Key::G] = true;
        break;
    case 72:  // H
        keyStates[Key::H] = true;
        break;
    case 73:  // I
        keyStates[Key::I] = true;
        break;
    case 74:  // J
        keyStates[Key::J] = true;
        break;
    case 75:  // K
        keyStates[Key::K] = true;
        break;
    case 76:  // L
        keyStates[Key::L] = true;
        break;
    case 77:  // M
        keyStates[Key::M] = true;
        break;
    case 78:  // N
        keyStates[Key::N] = true;
        break;
    case 79:  // O
        keyStates[Key::O] = true;
        break;
    case 80:  // P
        keyStates[Key::P] = true;
        break;
    case 81:  // Q
        keyStates[Key::Q] = true;
        break;
    case 82:  // R
        keyStates[Key::R] = true;
        break;
    case 83:  // S
        keyStates[Key::S] = true;
        break;
    case 84:  // T
        keyStates[Key::T] = true;
        break;
    case 85:  // U
        keyStates[Key::U] = true;
        break;
    case 86:  // V
        keyStates[Key::V] = true;
        break;
    case 87:  // W
        keyStates[Key::W] = true;
        break;
    case 88:  // X
        keyStates[Key::X] = true;
        break;
    case 89:  // Y
        keyStates[Key::Y] = true;
        break;
    case 90:  // Z
        keyStates[Key::Z] = true;


*/