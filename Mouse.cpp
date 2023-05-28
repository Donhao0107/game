#include "Mouse.h"

int Mouse::getX() {
    return x;
}

int Mouse::getY() {
    return y;
}

bool Mouse::isLeftDown() {
    return left;
}

bool Mouse::isRightDown() {
    return right;
}

void Mouse::update() {
    ExMessage msg; // 消息结构体
    if (peekmessage(&msg)) { // 如果有消息
        if (msg.message == WM_MOUSEMOVE) { // 如果是鼠标移动事件
            x = msg.x; // 更新横坐标
            y = msg.y; // 更新纵坐标
        }
        else if (msg.message == WM_LBUTTONDOWN) { // 如果是左键按下事件
            left = true; // 更新左键状态
        }
        else if (msg.message == WM_LBUTTONUP) { // 如果是左键弹起事件
            left = false; // 更新左键状态
        }
        else if (msg.message == WM_RBUTTONDOWN) { // 如果是右键按下事件
            right = true; // 更新右键状态
        }
        else if (msg.message == WM_RBUTTONUP) { // 如果是右键弹起事件
            right = false; // 更新右键状态
        }
        flushmessage(); // 清空消息队列
    }
}
